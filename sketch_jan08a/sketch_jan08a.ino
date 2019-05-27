//void setup() { // initialize digital pin 13 as an output.
//  pinMode(16, OUTPUT);
//}
//
//// the loop function runs over and over again forever
//void loop() {
//  digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(100);              // wait for a second
//  digitalWrite(16, LOW);    // turn the LED off by making the voltage LOW
//  delay(500);              // wait for a second
//}

#include <ESP8266WiFi.h>
 
const char* ssid = "REDACTED SSID";
const char* password = "REDACTED PASSWORD";
 
//int ledPin = 13; // GPIO13
//int ledPin = 16; // GPIO16, nodemcuV2 built-in second blue led
int ledPin = 2; // GPIO02, nodemcuV2 built-in primary blue led
//int ledPin = 5;
  int value = LOW;


WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  int timems = 0;
  while(!client.available()){
    timems += 5;
    delay(5);
    if(timems > 200) {
      Serial.println("timeout reached, disconnecting.");
      client.stop();
      return;
    }
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  if (request.indexOf("/LED=ON") != -1)  {
    Serial.println("setting value to HIGH");
    //digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    Serial.println("XXX setting value to LOW");
    //digitalWrite(ledPin, LOW);
    value = LOW;
  }
  digitalWrite(ledPin, !value);

  Serial.print("value =");
  Serial.print(value);
  Serial.println("");
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
