{:title "Save chrome eating battery life"
:layout :post
:tags ["linux" "tech" "notes"]
}

I seem to collect chrome tabs. I usually have a few dozen open, often many more if I haven't cleaned them out for a while. Once upon a time reboots would clear them out but these days I reopen the previous session when I boot so tabs don't go away unless I actually tell them to. Lots of them do stuff in the background so chrome ends up using a decent chunk of CPU time. It is almost always at the top of the list in powertop. 

Most of the time I don't care about this. If my computer is plugged in then it's fine. When I'm running on battery though I care a lot more. Then when I'm doing something that I don't need the web I put chrome to sleep with `killall -STOP chrome` and then when I want it back: `killall -CONT chrome`. Bind those two commands to keys and I can stop and start chrome as needed, and when I don't need it it doesn't get to eat my precious battery life. 
