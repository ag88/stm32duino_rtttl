# RTTTL player for stm32duino 
This is a [RTTTL](https://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language) player for stm32duino [*libmaple*](https://github.com/rogerclarkmelbourne/Arduino_STM32) core.

This implemention is targeted on the [maple mini](https://www.leaflabs.com/maple/) STM32F103CB (and [compatibles](https://www.ebay.com/sch/i.html?_from=R40&_nkw=maple+mini&_sacat=0)) board

## Credits
The RTTTL player implementation is from [arduino-rtttl-player](https://github.com/ponty/arduino-rtttl-player)

This is ported to run on the stm32duino libmaple core.
It uses the tone() function to drive the beeper/speaker hence to port this to other platforms/cores you'd need to use one that has the tone() function.

## Key things 

The beeper/speaker pin used in the code is PB7.  
This pin needs to be a Timer/PWM pin.  
STM32F103 pins can only drive 20ma max (based on specs) hence one should use a transistor (e.g. in a [emitter follower](https://en.wikipedia.org/wiki/Common_collector)) setup to drive the beeper / speaker.  
Beepers / speakers commonly draw much more currents than 20ma. e.g.  
![schematic](speaker_transistor.svg "speaker and transistor")


In addition, don't get a 'active' buzzer/beeper that beeps at a *fixed* frequency, you would only hear a single (mono)tone if you are lucky with that. Actual speakers, and 'passive' beepers and piezos likely works.

It uses LED_BUILTIN macro for the board led pin

## Use 
Build the sketch based on the [Arduino_STM32](https://github.com/rogerclarkmelbourne/Arduino_STM32) core. [more info](https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki)  
And install the sketch on the board e.g. maple mini (it may possibly work on [blue pill](https://hackaday.com/2017/03/30/the-2-32-bit-arduino-with-debugging/) but i've not tested it)

Copy and paste an RTTTL source into the serial console and hit enter/send it to the mcu and it plays the song

[![youtube](http://img.youtube.com/vi/uUC695nTkXw/0.jpg)](http://www.youtube.com/watch?v=uUC695nTkXw)

