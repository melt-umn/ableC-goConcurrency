grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;

nonterminal Expr with pp, value;

abstract production open
op::Expr ::= loc::Location
{
  op.value = exprStmt(
      directCallExpr( 
        name("chan_open", location=loc),
        nilExpr(),
        location=loc
      )
    )
}