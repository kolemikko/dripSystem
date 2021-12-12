#include "WebServer.h"
#include "WiFi.h"
#include "wificonfig.h"

bool online = false;

// Set web server port number to 80
WebServer server(80);

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>ESP32 Server</h1>\
<p>Pump1</p>\
<p><a href=\"/pump1/on\"><button" "class=\"button\">ON</button></a></p>\
</body>\
</html>";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  WiFi.setHostname(hostname);
  WiFi.begin(ssid, password);
  displayMessage("Connecting to wifi..");
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    displayMessage("...");
    delay(1000);
  }
  online = true;
  displayMessage("Connected!");
  delay(2000);
}

void handle_root() { server.send(200, "text/html", HTML); }

void initServer() {
  if (online) {
    server.on("/", handle_root);
    server.begin();
    displayMessage("HTTP server started");
    delay(1000);
  }
}

void runServer() { server.handleClient(); }
