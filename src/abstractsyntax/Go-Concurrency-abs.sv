grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction:parsing;
imports edu:umn:cs:melt:ableC:abstractsyntax:substitution;
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
top::Stmt ::= argList::[Expr] origFunc::Expr
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
          argsToStructItems(argList, 0, openScope(top.env)),
          location=builtin)));
  
  local funDcl::Decl =
    subDecl( 
      [declRefSubstitution("__origFunc__", origFunc),
       exprsSubstitution("__params__", paramsFromStruct(argList, 0))],
      decls(
        parseDecls(s"""
            static void *${funName}(void *_arg_ptr) {
                struct ${argStructName} _env = 
                    *(struct ${argStructName}*)_arg_ptr;
                (__origFunc__)(__params__);
            }""")));

  local globalDecls::Decls = foldDecl([argStructDcl, funDcl]);
 
  local structVarName::String = s"_spawn_struct_var_${id}_s";
  local structVarExpr::Expr = parseExpr(s"""${structVarName}""");

  local actual_forwards::Stmt = seqStmt(
      makeArgStruct(argList,argStructName,structVarName),
        exprStmt(
            directCallExpr(name("spawn_function",location=builtin),
                consExpr(
                    parseExpr(s"""${funName}"""), consExpr(
                        explicitCastExpr(typeName(
                            directTypeExpr(builtinType([],voidType())), 
                                pointerTypeExpr([], baseTypeExpr())), 
                            structVarExpr, location=builtin), 
                        nilExpr())), location=builtin)));

  forwards to injectGlobalDeclsStmt (  globalDecls, actual_forwards );
}

function paramsFromStruct
Exprs ::= args::[Expr] count::Integer
{
    local count_s::String = toString(count);
    return consExpr(parseExpr(s"""_env.f${count_s}"""), 
              if length(args) == 1 then nilExpr()
                 else paramsFromStruct(tail(args), count+1));
}

-- returns a list of struct items from the list of arguments passed in
function argsToStructItems
StructItemList ::= args::[Expr] count::Integer e::Decorated Env
{
  local count_s::String = toString(count);
  
  local h::Expr = head(args);
  h.env = e;

  return consStructItem(structItem([], directTypeExpr(h.typerep), 
        consStructDeclarator(
            structField(name(s"f${count_s}",location=head(args).location),
            baseTypeExpr(), []), nilStructDeclarator())),
            if length(args) == 1 then nilStructItem()
            else argsToStructItems(tail(args), count+1, e));
}

-- return a filled in struct of type structName with the given args
function makeArgStruct
Stmt::= args::[Expr] structName::String varName::String
{	                             
    return seqStmt(
        parseStmt(s"""struct ${structName} *${varName} = malloc(sizeof(struct ${structName}));"""),
                         fillArgs(args,varName, 0));
}

function fillArgs
Stmt::= args::[Expr] varName::String count::Integer
{
   local count_s::String = toString(count);
   local headStmt::Stmt = subStmt([declRefSubstitution("__expr__", head(args))],
                    parseStmt(s"""${varName}->f${count_s} = __expr__;"""));

   return if length(args) == 1 then headStmt  
               else seqStmt(headStmt, fillArgs(tail(args),varName, count+1));
}
