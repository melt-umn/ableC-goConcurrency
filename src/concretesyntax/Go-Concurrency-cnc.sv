grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast; 

imports edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

terminal Arrow_t '<-';
marking terminal Open_t 'open' lexer classes {Ckeyword};
terminal Close_t 'close';
terminal Chan_t 'chan';
terminal Spawn_t 'spawn';
terminal Select_t 'select';
terminal Case_t 'case';
terminal Default_t 'default';

concrete production open_c
s::PrimaryExpr_c ::= Open_t Chan_t
{
  s.ast = open(location=s.location);
}
