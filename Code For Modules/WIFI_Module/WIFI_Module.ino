#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>

String SSID = "IOT";
String PSK = "mrfunkfunk";

//UDP stuff:
WiFiUDP Udp;
const unsigned int udpPort = 1400;

const int UDP_PACKET_SIZE = 1; //change to whatever you need.
byte txBuffer[ UDP_PACKET_SIZE ]; //buffer to hold outgoing packets
IPAddress broadCastIP; //broadcast IP is determined dynamically from localIP() after successfull wifi connection.

const int buttonPin = D3;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int ledPinBot = D2;

void setup(void) {

  
 pinMode(ledPinBot, OUTPUT);

   pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPinBot, HIGH);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  
  Serial.println("Hello!");
  WiFi.hostname("John");
  WiFi.begin(SSID, PSK);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  
  Udp.begin(udpPort);

  //Broadcast IP should be the same as local IP but ending in 255:
  broadCastIP = WiFi.localIP();
  broadCastIP[3] = 255;

}


uint8_t status = 0;

void loop(void) {
 buttonState = !digitalRead(buttonPin);

//HERE IS WHERE YOU CAN CHANGE STATUS SOMEHOW (uint8_t goes from 0 to 255)

if (buttonState == 1) {status = 1; digitalWrite(ledPinBot, LOW); Serial.print("CLicked"); delay(500);}
if (buttonState == 0) {status = 0; digitalWrite(ledPinBot, HIGH);Serial.print(" not clicked"); delay(50);}

if(status!=0) {
  broadcast();
  status=1;
  delay (100);
}

}


void broadcast()
{
  txBuffer[0] = status;
  //txBuffer[1] = '\n'; //change UDP_PACKET_SIZE if you want to send more!

  // Prints data to be transmitted in serial monitor
  Serial.println("Transmitting: " + String((char*) txBuffer));

  // Sends packet
  Udp.beginPacket(broadCastIP, udpPort);
  Udp.write(txBuffer, UDP_PACKET_SIZE);
  Udp.endPacket();
}
