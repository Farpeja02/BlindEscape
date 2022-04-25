
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>




uint8_t state = 0;

String SSID = "IOT"; //Internet Name and Password
String PSK = "mrfunkfunk";

// Initialize the wifi Udp library
WiFiUDP Udp;
const unsigned int localPort = 1400;    // local port to listen for UDP packets
const int UDP_PACKET_SIZE = 1;     
byte packetBuffer[ UDP_PACKET_SIZE ]; //buffer to hold incoming and outgoing packets



const int buttonPin = D2;     // the number of the pushbutton pin

int buttonState = 1;         // variable for reading the pushbutton status
int buttonState2 = 1;         // variable for reading the pushbutton status
int ledPinBot = D3;

int Timer = 1; //Keeps track of how long the user has pressed the bottom
int Complete = 0; //Used to check if the module is complete

int ledPinBot5 = D7;
int ledPinBot6 = D0;

void setup() {
  ServoFailed();
  // put your setup code here, to run once:
  // declare the ledPin as an OUTPUT:

  pinMode(ledPinBot, OUTPUT);

  
  pinMode(ledPinBot5, OUTPUT);
  pinMode(ledPinBot6, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPinBot, HIGH);


    digitalWrite(ledPinBot5, LOW);
  digitalWrite(ledPinBot6, LOW);


  Serial.begin(115200);

  //Connects to the wifi, and stands by until it does
  WiFi.hostname("UDPRX");
  WiFi.mode(WIFI_STA);
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
  
  Udp.begin(localPort);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(buttonPin); //Reads bottomState  from bottom


  if (Udp.parsePacket()) UDPrx();{

yield();}

//Takes the value from the other module and assigns bottom state to it.
if(state!=0){
  buttonState2 = LOW;}

 if(state==0){
  buttonState2 = HIGH;}

  //If both bottoms pressed, the module is solved and green light turns on
  if (buttonState == LOW)  {
    if  (buttonState2 == LOW) {
    // turn LED on:
    digitalWrite(ledPinBot5, HIGH);
    Serial.println("Solved!");
    ServoComplete();
    Complete = 1;



    } }


  
  if (buttonState == HIGH)  {
    digitalWrite(ledPinBot, HIGH);}


  if  (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPinBot, HIGH);

    } 





 //If either bottom is pressed without the other, timer goes up
   if (buttonState == HIGH)  {
    if  (buttonState2 == LOW) {
    Timer +=1 ;
    Serial.println("Their Press");
    delay(50);

    }}

      if (buttonState == LOW)  {
    if  (buttonState2 == HIGH) {
      Serial.println("My press");
      digitalWrite(ledPinBot, HIGH);
    Timer +=1 ;
    delay(50);

    }}

//If timer is over 40 and the module isnt complete, the module fails and the red light turns on
  if (Timer > 40 && Complete == 0)  {
    Serial.println("Failed");
    digitalWrite(ledPinBot6, HIGH);

  }

 

}


//The functio to take the packet from other module
void UDPrx()
{
// We've received a packet, read the data from it
  Serial.println("udpRX!");
    memset(packetBuffer, 0, UDP_PACKET_SIZE); //reset packet buffer
    int read_bytes=Udp.read(packetBuffer,UDP_PACKET_SIZE);  // read the packet into the buffer

  state = packetBuffer[0];
}
