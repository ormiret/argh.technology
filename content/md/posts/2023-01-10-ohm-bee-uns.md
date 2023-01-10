{:title "Ω 🐝 🥁"
:layout :post
:tags ["tech" "nim" "web" "code"]
}

I have had vague thoughts for a while to make a thing to display random gifs, videos, or other animations as a thing to do with my various screens when they aren't needed to be displaying other things. Kind of like the old days when we used screensavers, but controlled over the network.

I finally got around to [making it](https://github.com/ormiret/ohm.bee.uns). 

I wanted this to be a web thing so that I only need a browser on whatever displays I want to use. [Nim](https://nim-lang.org/) with [Jester](https://github.com/dom96/jester) and [Karax](https://github.com/karaxnim/karax) are my current favourite approach to web dev. I came across a [nice example](https://arhamjain.com/2021/11/22/nim-simple-chat.html) using this stack that also introduced me to [htmx](https://htmx.org/) that makes the "open a websocket and display whatever html blobs you get from it" that I wanted for the client side really easy. 

The code itself isn't much use without a collection of animations for it to be serving up. My collection has been built up by saving things I've come across in various places online. Most of which I don't have rights to redistribute (and even the ones that are under licenses that would allow that I haven't kept note of that). [Beeple's VJ loops](https://www.beeple-crap.com/vjloops) are a good start with CC license (though I couldn't find anything saying which CC license). The collection should be in `public/img/` in `ohm.bee.uns` checkout (or relative to working directory for executable if that is a different place). 

The current version just gives each client a new random animation every 60 seconds. Some way to stop that and blank all the clients is probably the next thing I'll add. After that I'd like to add some administration to add tags to animations in the collection, and then set selection of animations to limit to exclude animations that match a list of tags. Would like to be able to set config for all displays or subsets of them. I would like to try making a (crappy) video wall by sending the same html blob to multiple clients but setting viewport so they only display a part of it. Should really move styling to a CSS file rather than a load of `style=` all over the place. 

I can imagine using this (with a couple more features implemented) on displays for a confrence. During talks displays could be set to stream of presenter or screenshare (or output of vision mixer to have someone switching between those or PiP of both) and between talks could be schedule info and/or random animations. 
