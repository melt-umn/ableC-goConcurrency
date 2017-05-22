grammar determinism;

import edu:umn:cs:melt:ableC:host ;

-- I don't think you're supposed to run copper_mda tests on
-- terminal-only grammars? Grammars are expected to have bridge
-- productions, and terminal-only grammars have zero productions
-- to be inferred as a bridge production.

--copper_mda testArrow(ablecParser) {
--  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:arrow;
--}

--copper_mda testSelectCases(ablecParser) {
--  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:selectCases;
--}

copper_mda testSelect(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:select;
}

copper_mda testSend(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:send;
}

copper_mda testRecieve(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:recieve;
}

copper_mda testSpawn(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:spawn;
}

copper_mda testClose(ablecParser) {
  edu:umn:cs:melt:exts:ableC:goConcurrency:concretesyntax:close;
}