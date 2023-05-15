#include "Attack.h"

#include <ESP8266WiFi.h>

Attack attack;

void setup() {
	Serial.begin(115200);
	Serial.println("Begin");
}

void loop() {
	delay(5000);

	Serial.println("--------------------------------");
	unsigned int num_networks = WiFi.scanNetworks();
	for (unsigned int i; i < num_networks; i++) {
		Serial.println(WiFi.SSID(i));
		/* if (WiFi.SSID(i) == "FlatXGulsonCourt") { */
		/* 	Serial.println(i); */
		/* } */
		/* Serial.print("-------"); */
		/* Serial.print("Network "); */
		/* Serial.print(i); */
		/* Serial.println("-------"); */

		/* Serial.print("SSID: "); */
		/* Serial.println(WiFi.SSID(i)); */

		/* Serial.print("Channel: "); */
		/* Serial.println(WiFi.channel(i)); */

		/* Serial.print("RSSI: "); */
		/* Serial.println(WiFi.RSSI(i)); */
	}
}
