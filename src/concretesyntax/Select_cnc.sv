grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

closed nonterminal SelectExpr_c with location, ast<SelectExpr>;
closed nonterminal SelectCases_c with location, ast<SelectCases>;
marking terminal Select_t 'select' lexer classes{Ckeyword};
marking terminal Test_t '<==' lexer classes{Ckeyword};

concrete productions s::SelectExpr_c
| '<-' ch::AssignExpr_c
{
  s.ast = makeReceive(ch.ast, location=s.location);
}
| v::AssignExpr_c '<==' ch::AssignExpr_c 
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

concrete production Select_c 
s::Stmt_c ::= 'select' '{' lst::SelectCases_c'}' 
{
  s.ast = select(lst.ast);
}