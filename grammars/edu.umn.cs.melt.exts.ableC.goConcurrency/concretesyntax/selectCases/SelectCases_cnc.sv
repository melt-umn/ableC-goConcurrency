grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:selectCases;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrow;

terminal SelectArrow_t '<-' lexer classes{Cassignment}, association = left;
terminal EqArrow '=<-' lexer classes{Cassignment};

disambiguate Arrow_t, SelectArrow_t {
  pluck Arrow_t;
}

closed nonterminal SelectExpr_c with location, ast<Expr>;

concrete productions s::SelectExpr_c
| SelectArrow_t ch::AssignExpr_c
{
  s.ast = tryReceive(ch.ast, location=s.location);
}
| ch::PrimaryExpr_c  op::AddMulNoneOp_c v::UnaryExpr_c
{   
  s.ast = trySend(ch.ast, v.ast, location=s.location);
}
| v::UnaryExpr_c '=' SelectArrow_t ch::UnaryExpr_c 
{
  s.ast = tryAssign(ch.ast, v.ast, location=s.location);
}

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