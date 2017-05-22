grammar edu:umn:cs:melt:exts:ableC:goConcurrency:abstractsyntax;

-- Obtain the type of the values stored in a given channel.
abstract production channelSubType
top::Type ::= ch::Type e::Decorated Env
{
  --TODO: errors! recv on non-channels will puke errors right now
  forwards to case ch of 
   pointerType(_, tagType(_, refIdTagType(_,_,id))) -> 
       head(lookupValue("v", head(lookupRefId(id,e)).tagEnv)).typerep 
  | _ -> errorType()
  end;
} 