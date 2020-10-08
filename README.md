## vMix Tally Light for m5Stack's ATOM Matrix

This project is based on Guido Visser's Tally Light for the m5Stack mStick-C.  I can't thank Guido enough for the work he put into the base code.  This version adds on to that code to allow the code to run on m5Stack's ATOM Matrix.  The ATOM Matrix has the same basic core as the m5Stick, but has fewer buttons and no battery, but the big difference is the display.  The ATOM Matrix trades the LCD for a 5x5 RGB LED Matrix.  The advantage of the ATOM is that it is much brighter and more easily visible over a long distance. 

This code can run on either the m5Stick-C or the ATOM Matrix without any changes.  Since the ATOM Matrix lacks a text display, I had to change the basic "user interface" from text-rich to text-light.  These changes are documented in the Usage section below.

## Installation

For the primary information on how to upload the code to the ATOM Matrix, follow the directions provided by Guido Visser in the original project.  His original readme is provided here, or you can check out https://github.com/guido-visser/vMix-M5Stick-Tally-Light.  Note that you will need to tell the Arduino IDE that you have an M5Stick-C as there is no specific ATOM board type yet.  Not to worry, the M5Stick-C setting works fine.  In addition to Guido's excellent instructions you will need to do a few extra steps:

You'll need some additional libraries.  Use the Library Manager to install them, as detailed in Guido's readme.  You will need:

Adafruit_NEO_Matrix

Adafruit_NEO_Pixel

Adafruit_GFX

You will also need to replace one file in the Adafruit_GFX library.  Copy the glcdfont.c file to the Adafruit GFX library folder (you'll find it at \Documents\Arduino\libraries\Adafruit_GFX_Library) to overwrite the existing file with the same name.  This is a custom 5x5 font file provided by @lukasmaximus89.  Many thanks to him for this file and for the inspiration for my scrolling text code.

## Usage

1.	Plug the Tally Light into a USB power source.  This can be a charger or any other source of USB power.  USB data is not used.  
2.	The Tally Light will power up and the screen will initially be blank but will then display a green “P” to show that it is powered up and running.  (Note:  If you’ve already configured the Tally Light, this green P may not stay up very long and might switch to display something else.  See further down for what might also be displayed.)
3.	If this is the first time you have powered up the Tally Light and/or it hasn’t been configured for a WiFi connection, it will begin searching for an active WiFi network.  Since you haven’t configured it or if it can’t find the previously configured network, the Tally Light will drop into Access Point mode and display a blue “A”.  Using a WiFi enabled device, such as a smartphone, connect to the WiFi network named: “vMix-M5tick-Tally” and use “12345678” as the password (both without quotes). Once the Tally Light connects to your device, it will display a green “W”.
4.	On that same device, bring up a web browser and go to http://192.168.4.1.  That will display the configuration screen. On that screen, enter the real WiFi information for your network, the IP address of the computer where vMix is running and at least the initial Tally Number.  You can find the IP address of the vMix computer by going to the vMix settings page and clicking the Web Controller option.  This will show you the IP address plus the port number after the colon (:).  DO NOT enter the port number or the colon.  The Tally Numbers correspond to the Input Numbers in vMix, which are displayed in the upper left-hand corner of the input’s thumbnail screens.  If you have created any virtual inputs then add those in the Multi Input field, separated by commas.  Note that the Brightness field won’t have any effect so don’t worry about it.  Save the settings.
5.	Once you save the settings, the connection to the Access Point will be lost and if you’ve correctly configured the Tally Light it should be connected to Wifi and immediately begin searching for an active connection to vMix.  While it’s searching it will display a red V.  
6.	The Tally Light will continue to search for vMix for several minutes.  (During this time, you will not be able to access the Tally Light via its web interface.)  If it can’t find vMix, it will display a blue C.  The C is telling you to either Connect to vMix or reConfigure your settings.  At this point you can connect to the Tally Light via its web interface.
7.	To connect to the web interface of the Tally Light once it’s connected to your real WiFi network, you will need to know what IP address your router has assigned to the Tally Light.  If you have access to your router’s admin interface, you can find the assigned web address in its list of attached devices.  Or, once you have established a Wifi connection and the Tally Light is showing the blue C or is connected to vMix (and not any other time), press the screen of the Tally Light (it’s a button) and it will display the IP address it has been assigned.  Write it down!  The address will be displayed one digit at a time and use a dash (-) where the periods would normally go.  Be sure to use the periods when entering the IP address in your browser.  Also note that when the digits are displayed, there will be a tiny interval of a blank screen in between digits.  This is to help you see any repeated digits.  You can keep pressing the button if you didn’t get the address the first time or two.  (Note:  You may find it useful to assign shortcuts in your browser to the Tally Light web screens.)  After pressing the button the Tally Light will attempt to reconnect to vMix.
8.	If you had vMix up and the Tally Light correctly configured, it should start responding to tally info from vMix.  It will display a full red screen for a “live” input, a green screen if the input is in “preview” and be blank if the input is not live or in preview.  During this time you can access the Tally Light via the web interface to change its configuration (like to add or change input assignments).  You can also press the screen button to see the IP address of the Tally Light.
9.	If you didn’t have vMix up during configuration and the Tally Light is displaying the blue C, and now you want to start using the Tally Light, start up vMix.  To reconnect the Tally Light to vMix, bring up the web interface for the Tally Light and click the Reconnect to vMix button.  The Tally Light should start responding. 
10.	If for any reason you need to reset the Tally Light, the button on the side will reset it, or you can unplug and plug it back in.

## Buy Me a Coffee

If you like this project and find it useful, buy me a coffee!

<div style="text-align: center"><a href="https://www.buymeacoffee.com/MarkGaretz" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a></div>
