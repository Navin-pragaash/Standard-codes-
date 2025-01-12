#include <WiFi.h>

// WiFi credentials
const char* ssid = "Hider";
const char* password = "navin003";

// TCP parameters
WiFiClient client;
const char* tcpAddress = "192.168.79.128";  // Server IP address (your PC)
const int tcpPort = 80;                    // TCP port number (use any open port)

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Connect to server
  if (client.connect(tcpAddress, tcpPort)) {
    Serial.println("Connected to server");
  } else {
    Serial.println("Connection to server failed");
  }
}

void loop() {
  // Send data over TCP
  if (client.connected()) {
    String message = "Hello from ESP32 over TCP!";
    client.println(message);
    Serial.println("TCP packet sent");
  } else {
    Serial.println("Disconnected from server");
  }

  delay(2000);  // Send every 2 seconds
}
