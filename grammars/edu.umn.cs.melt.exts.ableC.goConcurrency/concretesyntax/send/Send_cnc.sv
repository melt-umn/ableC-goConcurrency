grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:send;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax only send;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrow;

concrete productions top::AddMulNoneOp_c
| '<-'
{
    top.ast = send(top.leftExpr, top.rightExpr, location=top.location);
}