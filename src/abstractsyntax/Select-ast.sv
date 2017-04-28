grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction;
imports edu:umn:cs:melt:ableC:abstractsyntax:construction:parsing;
imports edu:umn:cs:melt:ableC:abstractsyntax:substitution;
imports edu:umn:cs:melt:ableC:abstractsyntax:env;
imports edu:umn:cs:melt:exts:ableC:templating:abstractsyntax as tmp;

imports silver:langutil;

Nonterminal SelectExpr with location, pp, errors, value, chanType;
Nonterminal SelectCases with location, pps, errors, body, host<SelectCases>, lifted<SelectCases>, globalDecls, env, default<Maybe<Stmt>>;


abstract production nilCase
top::SelectCases ::= c::SelectCase {
   Propagate host, lifted;
   top.pps = [];
   top.errors = [];
    top.globalDecls = [];
   Top.env = [];
   Top.default = nothing();
   Top.body = exprStmt(nilExpr());
}

Abstract production chanCase 
top::SelectCases ::= chexp::SelectExpr stm::Stmt sc::SelectCases {
   propagate host, lifted;
   top.pps = “chanExpr” ++ sc.pps;
   top.errors = sc.errors;
   top.globalDecls = sc.globalDecls;
   top.env = sc.env;
   top.default = sc.default;
   top.body = seqStmt(
                         ifStmtNoElse(
                                    chanCond(chexp),
                                    seqStmt(stm,breakStmt()),
                         c.body);
}

abstract production defaultCase 
top::SelectCases ::= stm::Stmt sc::SelectCases {
   propagate host, lifted;
   top.pps = “default” :: sc.pps;
   top.errors = sc.errors;
   top.globalDecls = sc.globalDecls;
   top.env = sc.env;
   top.default = sc.default;
   top.body = sc.body;
   Case top.default of 
       just(def) -> top.errors = “Multiple default statements in select” :: top.errors;
     | nothing() -> top.default = seqStmt(stm, breakStmt());
}

abstract production select
top:Stmt ::= cs::SelectCases {
  
   Local body = case cs.default of 
                 just(def) -> seqStmt(cs.body, cs.default) 
               | nothing() -> cs.body
     
   Forwards to whileStmt(
                                mkIntConst(1),
                                body)  
}

abstract production chanCond 
top::Expr ::= chExpr::SelectExpr 
{
  Forwards to if chExpr.chanType == “receive” then tryRecieve(chExpr.chan)
    Else if chExpr.chanType == “send” then trySend(chExpr.chan, chExpr.val)
     Else tryAssign(chExpr.chan, chExpr.val)
}

Abstract production makeReceive
top::SelectExpr ::= ch::Expr
{
  top.chanType = “receive”;
  top.chan = ch;
}

Abstract production makeSend
top::SelectExpr ::= ch::Expr v::Expr
{
  top.chanType = "send”;
  top.chan = ch;
  top.value = v;
}

Abstract production makeAssign
top::SelectExpr ::= ch::Expr v::Expr
{
  top.chanType = “assign”;
  top.chan = ch;
  top.value = v;
}

abstract production trySend
top::Expr ::= ch::Expr v::Expr
{
  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_send_select",location=top.location), 
              consTypeName(typeName(directTypeExpr(v.typerep), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, consExpr(v, nilExpr())), location=top.location);
}

abstract production tryAssign
top::Expr ::= ch::Expr v::Expr
{
  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv_select",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
                                               -- this v needs to be the pointer to v!
          consExpr(ch, consExpr(v, nilExpr())), location=top.location);
}

Abstract production tryReceive
top::Expr ::= ch::Expr
{
  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv_select_drop",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
                                               -- this v needs to be the pointer to v!
          consExpr(ch, nilExpr()), location=top.location);
}