# WirelessLGJoystick
A Wireless Joystick Controller for Liquid Galaxy built with Arduino and uses the UDP protocol.

## Files
- Videos: https://1drv.ms/u/s!AsvVMX2LdYhb5GNH315JzhiQzh2g?e=WuPuW3
- Python UDP Server on Master (UDPServer.py)
- Arduino Client Code (LG_WiFi_Joystick.ino)

## Prerequisite
- keyboard lib for python.
- ESP8266 WiFi module for Arduino.
- A buttons setup with breadboard.

## USAGE
- Update the IPs in Arduino and Python codes.
- Run the UDP server on the master machine.
- Upload the Arduino code.
- Click a button and lg should move!

## WORKING
The Arduino sends UDP messages to the Server. The server upon reading presses a key which moves lg.<br>
BUTTON INTERFACE: Since I don't have access to tactile push buttons, I am using Jumper wires connected to GND.
