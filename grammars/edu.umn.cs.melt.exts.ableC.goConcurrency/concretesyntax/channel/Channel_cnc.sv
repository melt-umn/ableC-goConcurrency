grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:channel;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

marking terminal Arrow_t '<-' lexer classes{Cassignment}, association = left;

-------
-- Recieve Statement
-- "val = <-ch;"
-- "<-ch;"
-------

concrete production recieveFrom_c
s::AssignExpr_c ::= Arrow_t ch::UnaryExpr_c
{
  s.ast = recieve(ch.ast, location=s.location);
}

--------
-- Send Statement
-- "ch <- val;"
--------

concrete productions top::AddMulNoneOp_c
| Arrow_t
{
    top.ast = send(top.leftExpr, top.rightExpr, location=top.location);
}

---------
-- Close Statement
-- "close(ch);"
---------

marking terminal Close_t 'close' lexer classes {Ckeyword};

concrete production close_c
s::AssignExpr_c ::= Close_t '(' e::AssignExpr_c ')'
{
  s.ast = close(e.ast, location=s.location);
}

--------
-- Select Statement
-- select {
--    case <-ch:
--      ...
--    case v = <-ch:
--      ...
--    case ch <- v:
--      ...
--    default:
--      ...
-- }
--------

marking terminal Select_t 'select' lexer classes{Ckeyword};

concrete production Select_c 
s::Stmt_c ::= 'select' '{' lst::SelectCases_c '}' 
{
  s.ast = select(lst.ast);
}

terminal SelectArrow_t '<-' lexer classes{Cassignment}, association = left;

disambiguate Arrow_t, SelectArrow_t {
  pluck Arrow_t;
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

closed nonterminal SelectExpr_c with location, ast<Expr>;

concrete productions s::SelectExpr_c
| SelectArrow_t ch::AssignExpr_c
{
  s.ast = tryReceive(ch.ast, location=s.location);
}
| ch::PrimaryExpr_c  op::AddMulNoneOp_c v::UnaryExpr_c
{   
  -- Todo: check that op.lexeme == "<-"
  s.ast = trySend(ch.ast, v.ast, location=s.location);
}
| v::UnaryExpr_c '=' SelectArrow_t ch::UnaryExpr_c 
{
  s.ast = tryAssign(ch.ast, v.ast, location=s.location);
}