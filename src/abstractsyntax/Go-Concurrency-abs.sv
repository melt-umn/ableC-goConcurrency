grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:abstractsyntax:env;
imports edu:umn:cs:melt:exts:ableC:templating:abstractsyntax as tmp;

imports silver:langutil;

abstract production open
top::Expr ::= 
{
  forwards to 
      directCallExpr( 
        name("chan_open", location=top.location),
        nilExpr(),
        location=top.location
      );
}

abstract production close
top::Expr ::= e::Expr
{
  forwards to
      directCallExpr( 
        name("chan_close", location=top.location),
        consExpr(e, nilExpr()),
        location=top.location
      );
}

abstract production send
top::Expr ::= ch::Expr v::Expr
{
  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_send",location=top.location), 
              consTypeName(typeName(directTypeExpr(v.typerep), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, consExpr(v, nilExpr())), location=top.location);
}

abstract production recieve
top::Expr ::= ch::Expr
{

  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);
}