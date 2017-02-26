{:title "VNC extra monitors"
:layout :post
:tags ["tech" "linux"]
}

A couple of times in the past I've thought about using other computers/tablets as additional displays for my main computer. 

This time I actually found a [way to do it](https://bbs.archlinux.org/viewtopic.php?id=191555). 

`xrandr` can be used to create a new monitor without the need for an actual monitor, I used the `VIRTUAL1` output and was pleased to see a `VIRTUAL2` pop into existence when I did. Then `x11vnc` with an appropriate `-clip` can make a VNC server for that bit of the virtual desktop. 

I tried both a spare laptop and my tablet as extra displays and it seems to work well with either.

The tablet as extra screen will be quite nice when I'm travelling. 

