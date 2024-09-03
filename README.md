# Deleteknop

Combine with an Arduino Leonardo or DFRobot Beetle and a Big Red Button.

Beetle available at [DFRobot](http://www.dfrobot.com/wiki/index.php/Beetle_SKU:DFR0282  "Beetle"). 
Button at [Okaphone](http://www.okaphone.com/artikel.asp?id=469347&id=469347 "button") (Netherlands) or [Rapid](https://www.rapidonline.com/hylec-1de-sp-21nr-ip66-red-palm-foot-switch-control-station-78-2113 "button") (UK).

## Wiring
Wiring is quite simple, I don't have a diagram for it but it goes as follows for the DFRobot Beetle: one connection of the button goes to A0 and the other connection goes to GND (- on the silkscreen of the PCB). THAT'S IT! 

## Code
The code is a bit convoluted, this is becasuse I avoided using a library for the button debounce. Large buttons like these tend to be quite "noisy", so they absolutely need debounce. 

## If I would do it again
Since I wanted my customers to be able to modify the code themselves as easily as possible I chose to implement the logic without libraries. This still requires the Arduino IDE. Nowadays I might have used CircuitPython to achieve this without even needing to install software.
