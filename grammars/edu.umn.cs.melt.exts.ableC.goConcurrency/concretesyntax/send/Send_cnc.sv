grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:send;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrowInfix;

concrete production sendTo_c
s::AssignExpr_c ::= ch::PrimaryExpr_c a::ArrowInfix_c v::PrimaryExpr_c
{
  s.ast = send(ch.ast, v.ast, location=s.location);
}
