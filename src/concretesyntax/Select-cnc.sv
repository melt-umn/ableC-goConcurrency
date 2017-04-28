grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

marking terminal Select_t ‘select’;
Closed nonterminal SelectExpr_c with location; ast<ast:SelectExpr>;
Closed nonterminal SelectCases_c with location, ast<ast:SelectCases>;

Concrete productions s::SelectExpr_c
| ‘<-’ ch::Expr_c
{
   S.ast = makeReceive(ch.ast, location=s.location)
}
| v::AssignExpr_c ‘=’ ‘<-’ ch::Expr_c 
{
  S.ast = makeAssign(ch.ast, v.ast, location=s.location)
}
| ch::AssignExpr_c ‘<-’ v::AssignExpr_c
{   
   S.ast = makeSend(ch.ast, v.ast, location=s.location)
}

Concrete productions s::SelectCases_c
| ‘case’ chexp::SelectExpr_c ‘:’ stm::Stmt_c sc::SelectCases_c
{
  S.ast = chanCase(chexp, stm, sc, location = s.location)
}
| default’ ‘:’ stm::Stmt_c sc::SelectCases_c
{
  S.ast = defaultCase(stm, sc, location = s.location)
}
|  
{
  S.ast = nilCase(location = s.location)
}

Concrete production Select_c 
S::Stmt_c ::= ‘select’ ‘{‘ lst::selectCases_c‘}’ 
{
  S.ast = select(lst.ast, location=s.location)
}