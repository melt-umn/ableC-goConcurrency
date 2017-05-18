grammar edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:spawn;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 
imports edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax only spawnFunction;

exports edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:spawnTerm;

concrete production spawn_function_c
s::Stmt_c ::= Spawn_t '(' lambda::AssignExpr_c ',' args::ArgumentExprList_c ')' 
{ 
  s.ast = spawnFunction(args.ast, lambda.ast); 
}