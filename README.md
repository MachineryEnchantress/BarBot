# Naomi Wu's BarBot
An Automated Bartender powered by Arduino  
<img src="https://imgur.com/1c3MjcF.jpg" width="800" height="454" alt="BarBot">

Based on the work of Lukas Šidlauskas:  
https://create.arduino.cc/projecthub/sidlauskas/barbot-cocktail-mixing-robot-0318aa  
https://github.com/sidlauskaslukas/barbot

## About

For my BarBot I wanted to make sure it was rock-solid reliable in a crowded bar environment so eliminated the touchscreen menus and wireless connectivity present in other versions of this project. Nearly any error can be dealt with by simply power cycling the device. Since there is no Raspberry Pi or SBC there is no risk of corruption when this is done. 

16 popular drinks (15 alcoholic and 1 non-alcoholic for non-drinkers and so that children can participate with supervision) are available from 16 arcade style buttons. A printed menu lists what button number corresponds to which drink.

Since the BarBot is designed for a working bar- and yes even in Shenzhen we are subject to surprise health inspections I had to do without pumps or difficult to clean feed lines. All of the components that require nightly cleaning are the same that bar staff are already accustomed to cleaning- spirit measures and bar mats. All drive components and bearings have been moved from under the pour spouts to well above or behind so there is no risk of an accumulation of sugar-rich liquids gumming up hard to clean moving parts of the machine or attracting vermin.

This BarBot is a functional novelty- it's something fun for visitors to play with. Perfect for my home city of Shenzhen where a large number of patrons are tech professionals. It is not secured for true commercial use- and with a bar full of half-drunk hardware engineers it would be pointless to try. In this case, it's better to rely on good faith then pretend you could stop them if challenged. Patrons could still manually press their cups to the spirit measures to manually dispense alcohol if they wanted to- but they could also reach over the bar and steal liquor while the bartender's back was turned. So far none have because why ruin the fun when there's no "hack" in doing so? If you really wanted to, a clear acrylic panel could be added to the front to prevent any manual dispensing, but it's really a lot less fun that way.

Portion control and payment is handled via an inexpensive arcade token acceptor. A customer can pay the bartender for a cup of ice and a token. When the correct token is inserted into the BarBot a contact is momentarily closed. The customer then has 60 seconds to press a drink selection button. That same contact can be closed with the key switch, in which case no tokens are needed for any orders while the switch is in that position.

Barbots of this configuration typically use either a servo or a stepper motor with a lead screw to depress the spirit measure spout depending on the type of dispenser it is. My code changes allow for either as RAMPS boards can control both steppers and a servo.

In the build and demonstration videos, you'll see that the full 25ml "shot" the spirit measure contains is usually only partially dispensed. This is because the actual shot size is defined in the code as a function of how long the spout is depressed. This allows for finer tuning of the drink flavor and portion size which would not be possible if only 25ml increments were used.

This BarBot was designed to be easy to build with off-the-shelf OpenBuilds components, V-Slot aluminum extrusion, and low-cost 3D printer parts. The heart of the BarBot is a standard Arduino Mega, RAMPS 1.4/1.5 and A4988 stepper driver combination as used in many 3D printers.

<img src="https://i.imgur.com/Lqtft5d.jpg" width="800" height="565" alt="BarBot"><BR>
See [Build Guide](https://github.com/sexycyborg/BarBot/blob/master/BarBotDrwMk01.PDF). 
  *Guide and SolidWorks CAD drawings courtesy of [Vexelius](https://www.thingiverse.com/Vexelius/).*

## BOM
[1x Arduino Mega 2560](http://reprap.org/wiki/Arduino_Mega)  
[1x RAMPS 1.4](http://reprap.org/wiki/RAMPS_1.4)/[1.5](http://reprap.org/wiki/RAMPS_1.5)  
[2x A4988 Stepper Driver](http://reprap.org/wiki/A4988)  
[Available as a kit](https://www.gearbest.com/kits/pp_228312.html?lkid=11066669)

1x [RAMPS 1.4/1.5 SD Card Reader](http://amzn.to/2EYiyeb)

[10x10 Drag Chain](http://amzn.to/2ECHM3W)  
 2 Meters 

[V-Slot® 20x80 Linear Rail](http://openbuildspartstore.com/v-slot-20x80-linear-rail/)  
 3x1200mm (Two vertical risers and one horizontal carriage rail)  
 2x1160mm (Lower brace, shelf for bar mat)

[V-Slot® 20x40 Linear Rail](http://openbuildspartstore.com/v-slot-20x40-linear-rail/)  
1x 1200mm (Horizontal rail for drag chain)  
2x 600mm (Horizontal legs)

30x [Black Angle Corner Connector](http://openbuildspartstore.com/black-angle-corner-connector/)

60x M5*8 [Openbuilds Low Profile Screws](http://openbuildspartstore.com/low-profile-screws-m5/)

50x [Tee Nuts](http://openbuildspartstore.com/tee-nuts-25-pack/)

50x [Drop In Tee Nuts](http://openbuildspartstore.com/drop-in-tee-nuts/)

#### Control Box
[V-Slot® 20x20 Linear Rail](http://openbuildspartstore.com/v-slot-20x20-linear-rail/)  
530mm x 4  
165mm x 5  
130mm x 4  
(All with 5mm threaded ends)

8x [Cube Corner Connector](http://openbuildspartstore.com/cube-corner-connector/)  
25x M5*15 [Openbuilds Low Profile Screws](http://openbuildspartstore.com/low-profile-screws-m5/)
