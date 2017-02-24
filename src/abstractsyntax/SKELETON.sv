grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax as abs;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction as abs;
imports edu:umn:cs:melt:ableC:abstractsyntax:env as abs;

imports silver:langutil;

abstract production open
top::abs:Expr ::= text::abs:Expr
{
  forwards to 
      directCallExpr( 
        name("chan_open", location=top.location),
        nil,
        location=top.location
      );
}