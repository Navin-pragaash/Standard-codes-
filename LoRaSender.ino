#include <SPI.h>
#include <LoRa.h>


int counter = 0;
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
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(2000);
}
