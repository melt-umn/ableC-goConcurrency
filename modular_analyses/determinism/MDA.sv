grammar edu:umn:cs:melt:exts:ableC:goConcurrency:modular_analyses:determinism ;

import edu:umn:cs:melt:ableC:host ;

copper_mda testArrow(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrow;
}

copper_mda testCloseTerm(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:closeTerm;
}

copper_mda testAssignTerm(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectAssignTerm;
}

copper_mda testSelectTerm(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectTerm;
}

copper_mda testSpawnTerm(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:spawnTerm;
}

copper_mda testArrowInfix(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:arrowInfix;
}

copper_mda testClose(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:close;
}

copper_mda testRecieve(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:recieve;
}

copper_mda testSend(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:send;
}

copper_mda testSpawn(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:spawn;
}

copper_mda testSelectExpr(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectExpr;
}

copper_mda testSelectCases(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:selectCases;
}

copper_mda testSelect(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:src:concretesyntax:select;
}
