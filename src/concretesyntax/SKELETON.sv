grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

terminal Open_t 'open`;
terminal Close_t 'close';
terminal Chan_t 'chan';
terminal Arrow_t '<-';
terminal Spawn_t 'spawn';
terminal Select_t 'select';
terminal Case_t 'case';
terminal Default 'default';

concrete production open_c
s::Stmt_c ::= sk::Open_t sk::Chan_t
{
  s.ast = open( sk.location );
}
