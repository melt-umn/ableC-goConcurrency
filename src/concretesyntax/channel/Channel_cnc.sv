grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:channel;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrow;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

marking terminal Close_t 'close' lexer classes {Ckeyword};

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

