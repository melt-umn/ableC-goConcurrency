grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:select;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectCases;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectTerm;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

concrete production Select_c 
s::Stmt_c ::= 'select' '{' lst::SelectCases_c '}' 
{
  s.ast = select(lst.ast);
}