grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:close;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax only close;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:closeTerm;

concrete production close_c
s::PrimaryExpr_c ::= Close_t '(' e::PrimaryExpr_c ')'
{
  s.ast = close(e.ast, location=s.location);
}