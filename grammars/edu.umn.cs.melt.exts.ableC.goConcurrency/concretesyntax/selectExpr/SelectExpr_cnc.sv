grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:selectExpr;

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
| SelectArrow_t ch::UnaryExpr_c
{
  s.ast = tryReceive(ch.ast, location=s.location);
}
--| ch::UnaryExpr_c SelectArrow_t v::UnaryExpr_c
--{   
--  s.ast = trySend(ch.ast, v.ast, location=s.location);
--}
| v::UnaryExpr_c '=' SelectArrow_t ch::UnaryExpr_c 
{
  s.ast = tryAssign(ch.ast, v.ast, location=s.location);
}

-- We need to create a new binary operation type? 
-- The issue becomes avoiding a conflict with x arrow_t y 
-- and x selectarrow_t y, if both of them are just AddMulOp_c
 