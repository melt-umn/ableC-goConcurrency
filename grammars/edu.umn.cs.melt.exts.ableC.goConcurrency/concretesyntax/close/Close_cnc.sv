grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:close;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax only close;

marking terminal Close_t 'close' lexer classes {Ckeyword};

concrete production close_c
s::AssignExpr_c ::= Close_t '(' e::AssignExpr_c ')'
{
  s.ast = close(e.ast, location=s.location);
}