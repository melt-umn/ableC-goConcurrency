grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax as abs;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction as abs;
imports edu:umn:cs:melt:ableC:abstractsyntax:env as abs;

imports silver:langutil;

abstract production open
top::abs:Expr ::= 
{
  forwards to 
      abs:directCallExpr( 
        abs:name("chan_open", location=top.location),
        abs:nilExpr(),
        location=top.location
      );
}

abstract production close
top::abs:Expr ::= e::abs:Expr
{
  forwards to
      abs:directCallExpr( 
        abs:name("chan_close", location=top.location),
        abs:consExpr(e, abs:nilExpr()),
        location=top.location
      );
}