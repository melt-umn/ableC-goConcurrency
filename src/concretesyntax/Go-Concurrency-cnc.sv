grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

marking terminal Arrow_t '<-' lexer classes{Ckeyword};
marking terminal Open_t 'open' lexer classes {Ckeyword};
marking terminal Close_t 'close' lexer classes {Ckeyword};
terminal Chan_t 'chan';
terminal Spawn_t 'spawn';
terminal Select_t 'select';
terminal Case_t 'case';
terminal Default_t 'default';

concrete production open_c
s::PrimaryExpr_c ::= Open_t Chan_t
{
  s.ast = open(location=s.location);
}

concrete production close_c
s::PrimaryExpr_c ::= Close_t '(' e::AssignExpr_c ')'
{
  s.ast = close(e.ast, location=s.location);
}

concrete production recieveFrom_c
s::Expr_c ::= '<-' ch::Expr_c
{
  s.ast = recieve(ch.ast, location=s.location);
}

--concrete production sendTo_c
--s::Expr_c ::= ch::Expr_c '<-' v::Expr_c
--{
--  s.ast = send(ch.ast, v.ast, location=s.location);
--}