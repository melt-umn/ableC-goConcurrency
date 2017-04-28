grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

nonterminal SelectExpr with location, pp, errors, value, chanType, chan;
nonterminal SelectCases with location, pps, errors, body, host<SelectCases>, lifted<SelectCases>, globalDecls, env, def;

synthesized attribute value::Expr;
synthesized attribute chan::Expr;
synthesized attribute chanType::String;
synthesized attribute body::Stmt;
synthesized attribute def::Maybe<Stmt>;

abstract production nilCase
top::SelectCases ::= {
   propagate host, lifted;
   top.pps = [];
   top.errors := [];
   top.globalDecls := [];
   top.def = nothing();
   top.body = exprStmt(nilExpr());
}

abstract production chanCase 
top::SelectCases ::= chexp::SelectExpr stm::Stmt sc::SelectCases {
   propagate host, lifted;
   top.pps = "chanExpr" ++ sc.pps;
   top.errors = sc.errors;
   top.globalDecls = sc.globalDecls;
   top.env = sc.env;
   top.def = sc.def;
   top.body = seqStmt(
                ifStmtNoElse(
                        chanCond(chexp),
                        seqStmt(stm,breakStmt())),
                c.body);
}


abstract production chanCond 
top::Expr ::= chExpr::SelectExpr 
{
  forwards to if chExpr.chanType == "receive" then tryRecieve(chExpr.chan)
    else if chExpr.chanType == "send" then trySend(chExpr.chan, chExpr.val)
     else tryAssign(chExpr.chan, chExpr.val);
}

abstract production makeReceive
top::SelectExpr ::= ch::Expr
{
  top.chanType = "receive";
  top.chan = ch;
}

abstract production makeSend
top::SelectExpr ::= ch::Expr v::Expr
{
  top.chanType = "send";
  top.chan = ch;
  top.value = v;
}

abstract production makeAssign
top::SelectExpr ::= ch::Expr v::Expr
{
  top.chanType = "assign";
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

abstract production tryReceive
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

abstract production select
top::Stmt ::= cs::SelectCases {
  
   local body::Stmt = case cs.def of 
                 just(def) -> seqStmt(cs.body, cs.def) 
               | nothing() -> cs.body end;
     
   forwards to whileStmt(
                                mkIntConst(1),
                                body);  
}

abstract production defaultCase 
top::SelectCases ::= stm::Stmt sc::SelectCases {
   propagate host, lifted;
   top.pps = "default" :: sc.pps;
   top.errors = sc.errors;
   top.globalDecls = sc.globalDecls;
   top.env = sc.env;
   top.def = sc.def;
   top.body = sc.body;

   top.def = case cs.def of 
       just(def) -> nothing()
     | nothing() -> just(seqStmt(stm, breakStmt())) end;
   
   top.errors := if top.def == nothing() then "Multiple default statements in select" :: top.errors
                else top.errors;
}