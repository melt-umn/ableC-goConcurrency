grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:select;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:selectCases;

marking terminal Select_t 'select' lexer classes{Ckeyword};

concrete production Select_c 
s::Stmt_c ::= 'select' '{' lst::SelectCases_c '}' 
{
  s.ast = select(lst.ast);
}