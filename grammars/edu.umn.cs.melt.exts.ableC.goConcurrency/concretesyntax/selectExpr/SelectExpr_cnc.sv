grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:selectExpr;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;
imports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrow   ;

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
| ch::PrimaryExpr_c SelectArrow_t v::PrimaryExpr_c
{   
  s.ast = trySend(ch.ast, v.ast, location=s.location);
}
| v::PrimaryExpr_c '=' SelectArrow_t ch::PrimaryExpr_c 
{
  s.ast = tryAssign(ch.ast, v.ast, location=s.location);
}