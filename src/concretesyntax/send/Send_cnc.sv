grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:send;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrowInfix;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

concrete production sendTo_c
s::AssignExpr_c ::= ch::PrimaryExpr_c a::ArrowInfix_c v::PrimaryExpr_c
{
  s.ast = send(ch.ast, v.ast, location=s.location);
}
