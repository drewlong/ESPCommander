#include <Arduino.h>
#include <Commands.h> // lib/Commands/Commands.h
#include "Nanoterm.h"

void setup() {
  Serial.begin(115200);
  std::vector<std::string> keys = {
    "help", "start_ap", "stop_ap", "scan"
  };
  std::vector<CommandPointer> functions = {
    help, startAP, stopAP, scanNetworks
  };
  buildMap(keys, functions);
}

void loop() {
  getInput();
}
