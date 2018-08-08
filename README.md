# WiFi-Door-Lock
A door lock that's controlled by a bot that reads Facebook's messenger system.
The bot looks for whether or not a key word ('open' or 'close') is written inside its message system. If so, then it updates Google's Firebase and lets the ESP8266 know whether to turn on the Servo motor or not. 

The libraries used in this program are fbchat along with pyrebase. 
