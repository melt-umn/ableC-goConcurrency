grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:recieve;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrow;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax only recieve;

concrete production recieveFrom_c
s::UnaryExpr_c ::= '<-' ch::PrimaryExpr_c
{
  s.ast = recieve(ch.ast, location=s.location);
}
