{:title "hackerdeenbot v2"
:layout :post
:tags ["irc" "tech" "57N" "python" "code"]
}

In the dim and distant past I made an [IRC bot](https://github.com/ormiret/spacebot) for what was then hackerdeen hackspace. It was written in clojure and had become more hassle than it worth to keep running. This was a combination of friction from JVM (it'll eat *all* the memory if you're not careful, has it's own SSL cert handling etc.) and my code not being very good at handling disconnects so regularly needing to be manually restarted. 

I wanted to move to something that would have a more complete IRC client (handling authentication, reconnects etc.) and giving me an interface to send messages from external things happening (e.g. space is opened/closed) and respond to commands. 

Options I know of for this are [suckless ii](https://tools.suckless.org/ii/) and [irccat](https://github.com/irccloud/irccat). I plumped for irccat, mostly because I had used it before so already kind of knew what I was doing to configure it and the approach to commands is a bit easier there: irccat will call a command handler executable with some env variables to give context of the command trigger and that executable just needs to print to console for response where with ii you'd have to parse the stream of messages for all channels watching for commands (I didn't get as far as figuring out how that would work for PRIVMSG commands) then write response to appropriate file. 

I didn't port over all of the "features" of original hackerdeenbot - some of them connected to other systems that don't exist any more and some were silly jokes that even I think have run their course now. 

[commands](https://github.com/ormiret/misc/blob/main/command_handler.py) I did implement:
```
 !gary: summon gary
 !ping: pong
 !membership: how many members have paid?
 !histogram: graph of how many members have paid
 !rules: space rules
 !rule <n>: the nth rule
```

Plus messages when the space is [opened or closed](https://github.com/ormiret/misc/blob/main/watch_status.py).
