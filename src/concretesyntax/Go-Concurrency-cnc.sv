grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

marking terminal Arrow_t '<-' lexer classes{Ckeyword};
marking terminal Open_t 'open' lexer classes {Ckeyword};
marking terminal Close_t 'close' lexer classes {Ckeyword};
terminal Chan_t 'chan';
marking terminal Spawn_t 'spawn' lexer classes {Ckeyword};
terminal Case_t 'case';
terminal Default_t 'default';
terminal Spawn_delim_t '@';

concrete production open_c
s::PrimaryExpr_c ::= Open_t Chan_t '<' t::TypeName_c '>'
{
  s.ast = open(t.ast, location=s.location);
}

concrete production close_c
s::PrimaryExpr_c ::= Close_t '(' e::PrimaryExpr_c ')'
{
  s.ast = close(e.ast, location=s.location);
}

concrete production recieveFrom_c
s::UnaryExpr_c ::= '<-' ch::PrimaryExpr_c
{
  s.ast = recieve(ch.ast, location=s.location);
}

concrete production sendTo_c
s::AssignExpr_c ::= ch::PrimaryExpr_c '<-' v::PrimaryExpr_c
{
  s.ast = send(ch.ast, v.ast, location=s.location);
}

concrete production spawn_function_c
s::Stmt_c ::= Spawn_t '(' lambda::AssignExpr_c ',' args::ArgumentExprList_c ')' 
{ 
  s.ast = spawnFunction(args.ast, lambda.ast); 
}