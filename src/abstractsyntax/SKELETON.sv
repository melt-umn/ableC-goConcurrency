grammar edu:umn:cs:melt:exts:ableC:goConcurrency:src:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax;


abstract production skeleton
s::Stmt ::= loc::Location
{
  local printStmts :: [Stmt] 
    = map (mkSkeletonLinePrint(loc,_), skeletonLines);

  forwards to 
    foldl1 (seqStmt, printStmts);

  -- The skeleton, as a list of strings.  The need to escape
  -- backslashes and double quotes obscures things a bit.
  local skeletonLines :: [ String ] =
   [ "                 .-\\\"```\\\"-.     ",
     "                /         \\\\    ",
     "                |  _   _  |    ",
     "                | (_\\\\ /_) |    ",
     "                (_   A   _)    ",
     "                 | _____ |     ",
     "                 \\\\`\\\"\\\"\\\"\\\"\\\"`/     ",
     "                  '-.-.-'      ",
     "                   _:=:_                   \\\\\\\\|  ",
     "            .-\\\"\\\"\\\"\\\"`_'='_`\\\"\\\"\\\"\\\"-.           \\\\///  ",
     "           (`,-- -`\\\\   /`- --,`)          (`/  ",
     "           / //`-_--| |--_-`\\\\\\\\ \\\\         .//  ",
     "          / /(_-_  _| |_  _-_)\\\\ \\\\       ///  ",
     "         / / (_- __ \\\\ / __ -_) \\\\ \\\\     ///  ",
     "        / /  (_ -_ - ^ - _- _)  \\\\ \\\\   ///  ",
     "       / /   (_-  _ /=\\\\ _ - _)   \\\\ \\\\ '//  ",
     "      / /     (_ -.':=:'. -_)     \\\\ \\\\//  ",
     "     (`;`     (_-'  :=:  '-_)      (_,'  ",
     "      \\\\\\\\.   jgs __  :=:  __     ",
     "       \\\\\\\\\\\\    .'  `':=:'`  '.     ",
     "        \\\\\\\\\\\\  |  .--. = .--.  |    ",
     "         \\\\\\\\\\\\ |  (  / = \\\\  )  |    ",
     "          \\\\\\\\` \\\\ _`' \\\\=/ '`_ /    ",
     "          ;`)  ( ;_/`v`\\\\_; )    ",
     "          |||\\\\ | |       | |    ",
     "          |\\\\\\\\  | |       | |    ",
     "               | |       | |    ",
     "               | |       | |    ",
     "               | |       | |    ",
     "               | |       | |    ",
     "               | |       | |    ",
     "              (._)       (_.)    ",
     "               ||,       ,||    ",
     "               ||:       :||    ",
     "               ||:       :||    ",
     "               ||:       :||    ",
     "               ||:       :||    ",
     "               ||'       '||    ",
     "              ///)       (\\\\\\\\\\\\    ",
     "            .///`         `\\\\\\\\\\\\.    ",
     "           `//`             `\\\\\\\\`    ",
     "",
     "     Courtesy of http://ascii-art.com."
   ] ;
}

function mkSkeletonLinePrint
Stmt ::= loc::Location skeletonLine::String
{
  local strForPrintf :: String =
    "\"" ++ skeletonLine ++ "\\n\"" ;

  return
    exprStmt(
      directCallExpr( 
        name("printf", location=loc),
        consExpr( stringLiteral(strForPrintf, location=loc),
	          nilExpr() ),
        location=loc
      )
    ) ;
}



{-
                 .-"```"-.
                /         \
                |  _   _  |
                | (_\ /_) |
                (_   A   _)
                 | _____ |
                 \`"""""`/
                  '-.-.-'
                   _:=:_                   \\|
            .-""""`_'='_`""""-.           \///
           (`,-- -`\   /`- --,`)          (`/
           / //`-_--| |--_-`\\ \         .//
          / /(_-_  _| |_  _-_)\ \       ///
         / / (_- __ \ / __ -_) \ \     ///
        / /  (_ -_ - ^ - _- _)  \ \   ///
       / /   (_-  _ /=\ _ - _)   \ \ '//
      / /     (_ -.':=:'. -_)     \ \//
     (`;`     (_-'  :=:  '-_)      (_,'
      \\.   jgs __  :=:  __
       \\\    .'  `':=:'`  '.
        \\\  |  .--. = .--.  |
         \\\ |  (  / = \  )  |
          \\` \ _`' \=/ '`_ /
          ;`)  ( ;_/`v`\_; )
          |||\ | |       | |
          |\\  | |       | |
               | |       | |
               | |       | |
               | |       | |
               | |       | |
               | |       | |
              (._)       (_.)
               ||,       ,||
               ||:       :||
               ||:       :||
               ||:       :||
               ||:       :||
               ||'       '||
              ///)       (\\\
            .///`         `\\\.
           `//`             `\\`

     Courtesy of http://ascii-art.com.
-}

