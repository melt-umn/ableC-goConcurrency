grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:recieve;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax only recieve;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrow;

concrete production recieveFrom_c
s::AssignExpr_c ::= Arrow_t ch::UnaryExpr_c
{
  s.ast = recieve(ch.ast, location=s.location);
}
