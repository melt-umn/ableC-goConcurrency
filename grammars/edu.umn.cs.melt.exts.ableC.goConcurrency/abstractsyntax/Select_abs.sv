grammar edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

imports silver:langutil:pp;

nonterminal SelectExpr with location, pp, value, chanType, chan;
nonterminal SelectCases with location, pp, errors, body, globalDecls, env, def;

synthesized attribute value::Expr;
synthesized attribute chan::Expr;
synthesized attribute chanType::String;
synthesized attribute body::Stmt;
synthesized attribute def::Maybe<Stmt>;

abstract production trySend
top::Expr ::= ch::Expr v::Expr
{
  propagate substituted;
  top.pp = pp"trySend(${ch.pp})";

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
  propagate substituted;
  top.pp = pp"tryAssign(${ch.pp})";

  local channelType::Type = channelSubType(ch.typerep, ch.env);

  local vpointer::Expr = subExpr([declRefSubstitution("__expr__", v)],
                    parseExpr(s"""&__expr__"""));

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv_select",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
                                               -- this v needs to be the pointer to v!
          consExpr(ch, consExpr(vpointer, nilExpr())), location=top.location);
}

abstract production tryReceive
top::Expr ::= ch::Expr
{
  propagate substituted;
  top.pp = pp"tryReceive(${ch.pp})";

  local channelType::Type = channelSubType(ch.typerep, ch.env);

  forwards to 
      callExpr(
          tmp:templateDeclRefExpr(name("chan_recv_select_drop",location=top.location), 
              consTypeName(typeName(directTypeExpr(channelType), baseTypeExpr()),
                   nilTypeName()),location=top.location),
          consExpr(ch, nilExpr()), location=top.location);
}

abstract production select
top::Stmt ::= cs::SelectCases {
  
   local body::Stmt = case cs.def of 
                 just(def) -> seqStmt(cs.body, def) 
               | nothing() -> cs.body end;
     
   forwards to whileStmt(
            mkIntConst(1, cs.location),
            body);  
}


abstract production nilCase
top::SelectCases ::= {
   top.pp = text("");
   top.errors := [];
   top.globalDecls := [];
   top.def = nothing();
   top.body = nullStmt();
}

abstract production chanCase 
top::SelectCases ::= chexp::Expr stm::Stmt sc::SelectCases {
   top.globalDecls := sc.globalDecls;
   top.def = sc.def;
   top.pp = ppConcat([chexp.pp, sc.pp]);
   top.errors := sc.errors;

   sc.env = top.env;
   top.body = seqStmt(
                ifStmtNoElse(
                        chexp,
                        seqStmt(stm,breakStmt())),
                sc.body);
}

abstract production defaultCase 
top::SelectCases ::= stm::Stmt sc::SelectCases {
  top.globalDecls := sc.globalDecls;
   top.body = sc.body;
   top.pp = ppConcat([text("default,"), sc.pp]);

   top.def = case sc.def of 
       just(def) -> nothing()
     | nothing() -> just(seqStmt(stm, breakStmt())) end;
   
   top.errors := case top.def of
       nothing() -> [err(top.location, "Multiple default statements in select")] ++ sc.errors
     | just(d) -> sc.errors end;
}