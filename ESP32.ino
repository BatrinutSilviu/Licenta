#include <WiFi.h>
const char* ssid     = "BanatRobot";
const char* password = "diferential2016";
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output15State = "off";
String output5State = "off";
String output2State="off";
String output18State="off";
String output23State="off";
String output19State="off";
String output22State="off";

// Assign output variables to GPIO pins
const int output15 = 15;
const int output5 = 5;
const int output2 =2;
const int output18 =18;
const int output23 =23;
const int output19 =19;
const int output22 =22;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output15, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output18, OUTPUT);
  pinMode(output23, OUTPUT);
  pinMode(output19, OUTPUT);
  pinMode(output22, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output15, LOW);
  digitalWrite(output5, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output18, LOW);
  digitalWrite(output23, LOW);
  digitalWrite(output19, LOW);
  digitalWrite(output22, LOW);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /15/on") >= 0) {
              Serial.println("GPIO 15 on");
              output15State = "on";
              digitalWrite(output15, HIGH);
              delay(5000);
              digitalWrite(output15, LOW);
            } 
            
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
              delay(5000);
              digitalWrite(output5, LOW);
            } 

          if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(output2, HIGH);
            } 
           if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            } 
           if (header.indexOf("GET /18/on") >= 0) {
              Serial.println("GPIO 18 on");
              output18State = "on";
              digitalWrite(output18, HIGH);
              delay(5000);
              digitalWrite(output18, LOW);
            } 
            if (header.indexOf("GET /23/on") >= 0) {
              Serial.println("GPIO 23 on");
              output23State = "on";
              digitalWrite(output23, HIGH);
              delay(5000);
              digitalWrite(output23, LOW);
            } 
            if (header.indexOf("GET /19/on") >= 0) {
              Serial.println("GPIO 19 on");
              output19State = "on";
              digitalWrite(output19, HIGH);
              delay(3500);
              digitalWrite(output19, LOW);
            } 
            if (header.indexOf("GET /22/on") >= 0) {
              Serial.println("GPIO 22 on");
              output22State = "on";
              digitalWrite(output22, HIGH);
              delay(3500);
              digitalWrite(output22, LOW);
            } 
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 15  
            client.println("<p>GPIO 15 - State " + output15State + "</p>");
            // If the output15State is off, it displays the ON button       
            if (output15State=="off") {
              client.println("<p><a href=\"/15/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/15/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>GPIO 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
