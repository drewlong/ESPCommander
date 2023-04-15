
# ESPCommander

This is a short and sweet implementation of my other project, [Nanoterm](https://github.com/drewlong/Nanoterm) (a microcontroller terminal emulator). It strives to include all* of the basic classes of the ESP8266WiFi library. Currently tested on ESP-01/S and NodeMCU 0.9 ESP8266. Will test on ESP32 soon. 

\*As of the last commit, this project is at 80% coverage

Download the project and build with:
```
pio run -e esp01 -t upload
```

To get into terminal (after building), run:
```
pio device monitor -b 115200
```

You may need to hit enter a couple of times to get into the 'shell'. 

Current commands:
```
help            Prints help 
clear           Clears screen
scan            Scans for Wifi networks

start_ap        Create a soft AP

                        -s SSID

                        -p Password

                        -s Channel

stop_ap         Create a soft AP
```

