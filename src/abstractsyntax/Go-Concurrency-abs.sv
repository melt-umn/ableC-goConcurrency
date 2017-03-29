grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;

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

inherited attribute baseTypeExpr :: BaseTypeExpr;
inherited attribute typeModifierExpr :: TypeModifierExpr;

abstract production send
top::Expr ::= ch::Expr v::Expr
{

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_send",location=top.location), 
              consTypeName(typeName(directTypeExpr(v.typerep), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, consExpr(v, nilExpr())), location=top.location);

  --forwards to
  --    directCallExpr(
        -- chan_send's generated name is created by the templating
        -- extension's mangled name function, so we call that name.
  --      name(tmp:templateMangledName("chan_send", [v.typerep]),
  --        location=top.location),
  --      consExpr(ch, 
  --        consExpr(v, nilExpr())),
  --      location=top.location
  --    );
}

abstract production recieve
top::Expr ::= ch::Expr
{
  forwards to
      directCallExpr( 
        name("chan_recv", location=top.location),
        consExpr(ch, nilExpr()),
        location=top.location
      );
}