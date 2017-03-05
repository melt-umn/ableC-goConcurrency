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

inherited attribute baseTypeExpr :: abs:BaseTypeExpr;
inherited attribute typeModifierExpr :: abs:TypeModifierExpr;

-- Right now we're explicitly casting to 
-- void*. This is not how we want to be 
-- doing this eventually-- given understandable
-- templates we'll abandon the standard channel
-- struct and lift channels with defined types.
abstract production send
top::abs:Expr ::= ch::abs:Expr v::abs:Expr
{

  forwards to
      abs:directCallExpr(
        abs:name("chan_send", location=top.location),
        abs:consExpr(ch, 
          abs:consExpr(
          abs:explicitCastExpr(
            -- It seems like we're calling this a pointer twice
            -- which may be wrong 
            abs:typeName(abs:directTypeExpr(abs:pointerType([], abs:builtinType([], abs:voidType()))),
              abs:pointerTypeExpr([], abs:baseTypeExpr())),
            v, location=top.location), abs:nilExpr())),
        location=top.location
      );
}

abstract production recieve
top::abs:Expr ::= ch::abs:Expr
{
  forwards to
      abs:directCallExpr( 
        abs:name("chan_recv", location=top.location),
        abs:consExpr(ch, abs:nilExpr()),
        location=top.location
      );
}