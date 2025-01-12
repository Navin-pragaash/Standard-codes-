#include <SPI.h>
#include <LoRa.h>
// Set the pins for LoRa module
int ss = 10; // NSS pin
int reset = 9; // Reset pin
int dio0 = 2; // DIO0 pin (optional)

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to connect
  LoRa.setPins(ss, reset, dio0); // Set the pins
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initialization Successful");
  LoRa.setSignalBandwidth(125E3);
  LoRa.setSpreadingFactor(10);
  LoRa.setCodingRate4(5);
  LoRa.beginPacket();
  LoRa.print("Hello, World!");
  LoRa.endPacket();
  Serial.println("Message Sent: Hello, World!");
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
