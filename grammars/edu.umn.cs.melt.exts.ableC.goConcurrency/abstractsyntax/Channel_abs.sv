grammar edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction:parsing;
imports edu:umn:cs:melt:ableC:abstractsyntax:substitution;
imports edu:umn:cs:melt:ableC:abstractsyntax:env;
imports edu:umn:cs:melt:exts:ableC:templating:abstractsyntax as tmp;

imports silver:langutil;

abstract production close
top::Expr ::= ch::Expr
{ 
  propagate substituted;
  top.pp = pp"close(${ch.pp})";

  local channelType::Type = channelSubType(ch.typerep, ch.env);

  -- next, fill this with an error from the above channelSubType
  local localErrors::[Message] = [];

  local fwrd::Expr = 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_close",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);

  forwards to mkErrorCheck(localErrors, fwrd);
}

abstract production send
top::Expr ::= ch::Expr v::Expr
{
  propagate substituted;
  top.pp = pp"send(${ch.pp})";

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
  propagate substituted;
  top.pp = pp"recieve(${ch.pp})";

  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);
}