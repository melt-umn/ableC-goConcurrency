grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

closed nonterminal SelectExpr_c with location, ast<ast:SelectExpr>;
closed nonterminal SelectCases_c with location, ast<ast:SelectCases>;
marking terminal Select_t 'select' lexer classes{Ckeyword};

concrete productions s::SelectExpr_c
| '<-' ch::Expr_c
{
  s.ast = makeReceive(ch.ast, location=s.location);
}
| v::AssignExpr_c '=' '<-' ch::Expr_c 
{
  s.ast = makeAssign(ch.ast, v.ast, location=s.location);
}
| ch::AssignExpr_c '<-' v::AssignExpr_c
{   
  s.ast = makeSend(ch.ast, v.ast, location=s.location);
}

concrete productions s::SelectCases_c
| 'case' chexp::SelectExpr_c ':' stm::Stmt_c sc::SelectCases_c
{
  s.ast = chanCase(chexp, stm, sc, location = s.location);
}
| 'default' ':' stm::Stmt_c sc::SelectCases_c
{
  s.ast = defaultCase(stm, sc, location = s.location);
}
|  
{
  s.ast = nilCase(location = s.location);
}

concrete production Select_c 
s::Stmt_c ::= 'select' '{' lst::selectCases_c'}' 
{
  s.ast = select(lst.ast, location=s.location);
}