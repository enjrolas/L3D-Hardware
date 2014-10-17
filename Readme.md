This repository contains all the hardware files we use to make our cubes.  It's organized in two directories 
for the two sizes of cubes we make, a 8x8x8 cube and a 16x16x16 cube.  Each directory includes the eagle files
for the baseboard that goes at the bottom of the cube, and the thin LED stick PCBs that hold the LED themselves.
The 8x8x8 cube has 64 LED sticks, and the 16x16x16 cube has a whopping 256 LED sticks.  Electrically, the cubes 
are quite simple.  They're based around the popular WS2812B addressable LED and the Spark Core processor.  Our BOM
has Chinese sources, but you can also source the WS2812B LEDs from any number of sources, such as [Adafruit](https://www.adafruit.com/products/1655) and our 
friends [at Seeed Studios](http://www.seeedstudio.com/depot/WS2812B-RGB-LED-with-Integrated-Driver-Chip-10-PCs-pack-p-1675.html).
The other components are a few common passives detailed in the BOM.