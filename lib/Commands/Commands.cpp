#include <ESP8266Wifi.h>
#include "Nanoterm.h"

// Commands
void help(){
  String msg;

  msg += "\n";
  msg += "\nESP8266 Terminal by @drewlong\n";
  msg += "\n-------------------------------\n";
  msg += "\nCommands:\n";
  msg += "\n\tconnect\t\tConnect to network\n";
  msg += "\n\t\t\t\t-s SSID\n";
  msg += "\n\t\t\t\t-p Password\n";
  msg += "\n\tmonitor\t\tMonitor as client (requires 'connect')\n";
  msg += "\n\tmonitor_ap\tMonitor as AP (requires 'start_ap')\n";
  msg += "\n\tscan\t\tScans for Wifi networks\n";
  msg += "\n\tstart_ap\tCreate a soft AP\n";
  msg += "\n\t\t\t\t-s SSID\n";
  msg += "\n\t\t\t\t-p Password\n";
  msg += "\n\t\t\t\t-s Channel\n";
  msg += "\n\tstop_ap\t\tCreate a soft AP\n";

  Serial.println(msg);
}

void startAP(){ 
  std::string SSID = "ESP_NET";
  std::string passwd = "WeakPassword123";
  int channel = 6;
  bool default_pass = true;

  if(ARGM.find("-s") != ARGM.end()){
    SSID = ARGM["-s"];
  }

  if(ARGM.find("-p") != ARGM.end()){
    passwd = ARGM["-p"];
    default_pass = false;
  }

  if(ARGM.find("-c") != ARGM.end()){
    channel = std::stoi(ARGM["-c"]);
  }

  Serial.println(F("\nStarting Access Point..."));

  WiFi.softAP(SSID.c_str(), passwd.c_str(), channel);

  Serial.print(F("SSID: "));
  Serial.println(SSID.c_str());
  if(default_pass){
    Serial.printf_P(PSTR("Default password: %s\n"), passwd.c_str());
  }
  Serial.print(F("AP IP address: "));
  Serial.println(WiFi.softAPIP());
  Serial.printf_P(PSTR("AP Channel: %i\n"), channel);
  Serial.printf_P(PSTR("MAC address: %s\n"), WiFi.softAPmacAddress().c_str());  
}

void stopAP(){
  WiFi.softAPdisconnect (true);
  Serial.println(F("\nWifi Access Point Stopped"));
}

void scanNetworks(){
  Serial.println(F("\nScanning for nearby Wifi networks..."));
  String networks[128];
  
  // TODO: SSIDs are being stored in 'networks', 
  // create a method to connect to a network by array index

  int numberOfNetworks = WiFi.scanNetworks();
  
  for(int i =0; i<numberOfNetworks; i++){
      Serial.printf_P(PSTR("Index: %d\n"), i);
      Serial.printf_P(PSTR("SSID: %s\n"), WiFi.SSID(i).c_str());
      networks[i] = WiFi.SSID(i);
      Serial.printf_P(PSTR("BSSID: %s\n"), WiFi.BSSIDstr(i).c_str());
      Serial.printf_P(PSTR("Channel: %i\n"), WiFi.channel(i));
      Serial.printf_P(PSTR("Signal strength: %d\n"), WiFi.RSSI(i));
      Serial.printf_P(PSTR("Hidden: %s\n"), WiFi.isHidden(i) ? "Yes" : "No");
      Serial.println(F("===================================="));
  }
  ARGM.clear();
}