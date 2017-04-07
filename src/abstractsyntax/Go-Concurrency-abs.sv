grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:abstractsyntax:env;
imports edu:umn:cs:melt:exts:ableC:templating:abstractsyntax as tmp;

imports silver:langutil;

abstract production open
top::Expr ::= t::TypeName
{
  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_open",location=top.location), 
              consTypeName(t, nilTypeName()),location=top.location),
          nilExpr(), location=top.location);
}

abstract production close
top::Expr ::= ch::Expr
{
  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_close",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);
}

abstract production send
top::Expr ::= ch::Expr v::Expr
{
  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_send",location=top.location), 
              consTypeName(typeName(directTypeExpr(v.typerep), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, consExpr(v, nilExpr())), location=top.location);
}

abstract production recieve
top::Expr ::= ch::Expr
{
  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);
}

global builtin::Location = builtinLoc("go_conc");

abstract production spawnFunction
top::Stmt ::= argList::[Expr] res::Expr
{
  local args::Exprs = foldExpr(argList);
  local id::String = toString(genInt()); 
  local argStructName::String = s"_spawn_arg_${id}_s";
  local funName::String = s"_spawn_fn_${id}";
  
  local argStructDcl::Decl =
    typeExprDecl([],
      structTypeExpr([],
        structDecl([],
          justName(name(argStructName, location=builtin)),
          argsToStructItems(args, 0),
          location=builtin)));
  
  local funDcl::Decl =
    subDecl(
      [stmtSubstitution("__call__", callFromStruct(funName, argStructName))],
      decls(
        parseDecls(s"""
            static void * ${funName}(void *_arg_ptr) {
                struct ${argStructName} _env = 
                    *(struct ${argStructName}*)_arg_ptr;
                __call__;
            }""")));

  local globalDecls::Decls = foldDecl([argStructDcl, funDcl]);
 
  local structVarName::String = s"_spawn_struct_var_${id}_s";
  local structVarExpr::Expr = parseExpr(s"""${structVarName}""");

  local actual_forwards::Stmt = seqStmt(
      makeArgStruct(args,argStructName,structVarName),
        exprStmt(
            directCallExpr("spawn_function",
                consExpr(
                    parseExpr(s"""${funName}"""), consExpr(
                        explicitCastExpr(typeName(
                            directTypeExpr(builtinType([],voidType()), 
                                pointerTypeExpr([], baseTypeExpr()))), 
                            structVarExpr), 
                        nilExpr())))));

  forwards to injectGlobalDeclsStmt (  globalDecls, actual_forwards );
}

-- return a filled in struct of type structName with the given args
function makeArgStruct
Stmt::= args:Exprs structName::Name varName::Name
{	
	return seqStm(parseStmt(s"""malloc(sizeof(${structName}))"""),
                         fillArgs(args,varName, 0));
}

function fillArgs
Stmt::= args::Exprs varName::Name count::Integer
{
   local headStmt::Stmt = subStmt([exprSubstitution("__expr__", head(args))],
                    parseStmt(s"""${varName}.${count} = __expr__"""));

   return if args.count == 1 then headStmt  
               else seqStmt(headStmt, fillArgs(tail(args),varName, count+1));
}

-- put all of the args from the struct and call the function
function callFromStruct
Stmt ::= funName::Name args::Exprs
{ 
   return directCallExpr(funName, paramsFromStruct(args, 0));  
}

function paramsFromStruct
Exprs ::= args::Exprs count::Integer
{
    return consExpr(parseExpr(s"""_env.f${count}"""), 
              if args.count == 1 then nilExpr()
                 else fieldsFromStruct(tail(args), count+1));
}

-- returns a list of struct items from the list of arguments passed in
function argsToStructItems
StructItemList ::= args::Exprs count::Integer
{
  return foldr(consStructItem, structItem([], head(args).typerep, 
        structField(name(s"f${count}",location=head(args).location),
            nilTypeModifierExpr(), [])),
            if args.count == 1 then []
            else argsToStructItems(tail(args), count+1));
}
