#include <Servo.h>
#define RED  A0   // pin that red led is connected to    
#define GREEN  A1 // pin that green led is connected to     

Servo myservo;  // create servo object to control a servo

const int buttonPin = 3;     // the number of the pushbutton pin
int buttonState = 1;         // variable for reading the pushbutton status
int ledPinBot = 2;

const int buttonPin2 = 5;     // the number of the pushbutton pin
int buttonState2 = 1;         // variable for reading the pushbutton status
int ledPinBot2 = 4;

const int buttonPin3 = 7;     // the number of the pushbutton pin
int buttonState3 = 1;         // variable for reading the pushbutton status
int ledPinBot3 = 6;

const int buttonPin4 = 9;     // the number of the pushbutton pin
int buttonState4 = 1;         // variable for reading the pushbutton status
int ledPinBot4 = 8;


int ledPinBot5 = 11;
int ledPinBot6 = 12;


int Failed = 0;

int Solved = 0;

int Correct1 =0;
int Correct2 =0;
int Correct3 =0;
int Correct4 =0;

void setup() {
  ServoFailed();

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  // put your setup code here, to run once:
  // declare the ledPin as an OUTPUT:

 pinMode(ledPinBot, OUTPUT);
 pinMode(ledPinBot2, OUTPUT);
 pinMode(ledPinBot3, OUTPUT);
 pinMode (ledPinBot4, OUTPUT);
  pinMode (ledPinBot5, OUTPUT);
  pinMode (ledPinBot6, OUTPUT);
        

  // initialize the pushbutton pin as an input:
    
  digitalWrite(ledPinBot, HIGH);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  digitalWrite(ledPinBot2, HIGH);

  pinMode(buttonPin3, INPUT_PULLUP);
  digitalWrite(ledPinBot3, HIGH);

  pinMode(buttonPin4, INPUT_PULLUP);
  digitalWrite(ledPinBot4, HIGH);


  digitalWrite(ledPinBot5, LOW);
  digitalWrite(ledPinBot6, LOW);



}

void loop() {
  // put your main code here, to run repeatedly:
//Turns on the RGB lamp.
analogWrite(RED, LOW); // red initially ON
    analogWrite(GREEN, LOW); // green initially OFF


  buttonState = digitalRead(buttonPin);
  
  buttonState2 = digitalRead(buttonPin2);

  
  buttonState3 = digitalRead(buttonPin3);

  
  buttonState4 = digitalRead(buttonPin4);

//If the first bottom is pressed correct1 is set to 1, and it turns on the light in the bottom
  if (buttonState == LOW && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH && Failed == 0 ) {
    Correct1 = 1;
      digitalWrite(ledPinBot, LOW);

  }

  
//If second bottom is pressed and correct1 = 1, correct2 = 1, else Failed = 1
  if (buttonState == HIGH && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == HIGH && Failed == 0) {
    
    if (Correct1== 1) {    
    Correct2 = 1;
    digitalWrite(ledPinBot2, LOW);}
    else { Failed = 1;}
  }

//If third bottom is pressed and correct1 = 1 and correct2 = 1, correct3 = 1, else Failed = 1
   if (buttonState == HIGH && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == HIGH && Failed == 0) {   
    if (Correct1== 1 && Correct2 == 1) {
    Correct3 = 1;
    digitalWrite(ledPinBot3, LOW);}

    else { Failed = 1;}}
  

//If forth bottom is pressed and correct1 = 1, correct2 = 1 and correct3 = 1, correct4 = 1 and the module is complete., else Failed = 1
   if (buttonState == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == LOW && Failed == 0) {
    if (Correct1== 1 && Correct2 == 1 && Correct3 == 1 ) {
    Correct4 = 1;
    digitalWrite(ledPinBot4, LOW);
    digitalWrite(ledPinBot5, HIGH);
    ServoComplete();}
    else {Failed = 1;}
    
    }


//if any other bottom is pressed in the beggining, the module is failed  

if (buttonState == HIGH && buttonState2 == LOW && buttonState3 == HIGH && buttonState4 == HIGH && Correct1 == 0 ) {

  Failed = 1;
}
if (buttonState == HIGH && buttonState2 == HIGH && buttonState3 == LOW && buttonState4 == HIGH && Correct1 == 0) {
  Failed = 1;
}
if (buttonState == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == LOW && Correct1 == 0) {
  Failed = 1;
}


//if the module is failed, the red LED is turned on.
if (Failed == 1) {digitalWrite(ledPinBot6, HIGH);}

    }


    void ServoComplete(){


// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }


    void ServoFailed(){

// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }

 
