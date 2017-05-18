grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectCases;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectExpr;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectTerm;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrow;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

nonterminal SelectCases_c with location, ast<SelectCases>;

concrete productions s::SelectCases_c
| 'case' chexp::SelectExpr_c ':' stm::Stmt_c sc::SelectCases_c
{
  s.ast = chanCase(chexp.ast, stm.ast, sc.ast, location = s.location);
}
| 'default' ':' stm::Stmt_c sc::SelectCases_c
{
  s.ast = defaultCase(stm.ast, sc.ast, location = s.location);
}
|  
{
  s.ast = nilCase(location = s.location);
}