//This example make as scan for all available wifi nentwork with esp32 CAM module

// Including wifi libraries
#include "WiFi.h"

void setup() {

  // Initializing the serial monitor
  Serial.begin(115200);

  // Setting wifi to station mode
  WiFi.mode(WIFI_STA);
  // Disconnecting wifi from AP if was previous connected
  WiFi.disconnect();
  delay(100);

  Serial.print("Setup is done");
}

void loop() {
  // Start scanning for wifi
  Serial.println("Wifi scanning initialized---");

  // Storing scanned wifi into a variable
  int n = WiFi.scanNetworks();

  // When no networks found
  if (n == 0) {
    Serial.println("No network found");
  }

  else {
    // Printing available networks
    Serial.print("Available networks are ");
    Serial.println(n);

    // Printing the nertwork SSID and PASSWORD
    for (int i = 0; i < n; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print("(");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") : ");
      /* Getting wifi encryption
      TKIP(WPA) = 2
      WEP = 5
      CCMP(WPA) = 4
      NONE = 7
      AUTO = 8
      */
      Serial.println(WiFi.encryptionType(i), HEX);
      Serial.print("");
      delay(10);
    }
  }

  // Delay for waiting another scan
  delay(5000);
}
