grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectExpr;

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectAssignTerm;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectTerm;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrow;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

nonterminal SelectExpr_c with location, ast<SelectExpr>;

concrete productions s::SelectExpr_c
| '<-' ch::PrimaryExpr_c
{
  s.ast = makeReceive(ch.ast, location=s.location);
}
| v::PrimaryExpr_c '<==' ch::PrimaryExpr_c 
{
  s.ast = makeAssign(ch.ast, v.ast, location=s.location);
}
| ch::PrimaryExpr_c '<-' v::PrimaryExpr_c
{   
  s.ast = makeSend(ch.ast, v.ast, location=s.location);
}