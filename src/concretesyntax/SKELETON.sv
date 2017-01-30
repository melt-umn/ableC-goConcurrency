grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

marking terminal Skeleton_t 'skeleton!' ;

concrete production skeleton_c
s::Stmt_c ::= sk::Skeleton_t
{
  s.ast = skeleton( sk.location );
}
