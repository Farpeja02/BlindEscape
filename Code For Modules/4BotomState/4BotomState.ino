#include <Servo.h>
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


int ledPinBot5 = 13;
int ledPinBot6 = 12;

// These are the varriables for keeping track of the state of the module
int failed = 0;

int solved = 0;

void setup() {
  ServoFailed();
  
  // put your setup code here, to run once:
  // declare the ledPin as an OUTPUT:

 pinMode(ledPinBot, OUTPUT);
 pinMode(ledPinBot2, OUTPUT);
 pinMode(ledPinBot3, OUTPUT);
 pinMode (ledPinBot4, OUTPUT);


 pinMode(ledPinBot5, OUTPUT);
 pinMode (ledPinBot6, OUTPUT);
        

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPinBot, HIGH);

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

  buttonState = digitalRead(buttonPin);
  
  buttonState2 = digitalRead(buttonPin2);

  
  buttonState3 = digitalRead(buttonPin3);

  
  buttonState4 = digitalRead(buttonPin4);

//Checks if the correct bottom is pressed, if it is the module is complete
  if (buttonState == LOW) {

    if (failed == 0) {
    // turn LED on:
    digitalWrite(ledPinBot, LOW);
    digitalWrite(ledPinBot5, HIGH);
    
    solved = 1;
    ServoComplete();
    } 
  }


//These all check if the user presses the wrong bottom, if they due the red LED turns on, and the module is failed
  if (buttonState2 == LOW) {
        if (solved == 0) {
      // turn LED on:
    digitalWrite(ledPinBot2, LOW);
    digitalWrite(ledPinBot6, HIGH);

    failed = 1;
    ServoFailed();
    } }

  if (buttonState3 == LOW) {
    if (solved == 0) {
    // turn LED on:

    digitalWrite(ledPinBot3, LOW);
    digitalWrite(ledPinBot6, HIGH);

    failed = 1;
    ServoFailed();
    } }

   if (buttonState4 == LOW) {
        if (solved == 0) {
   
    // turn LED on:

    digitalWrite(ledPinBot4, LOW);
    digitalWrite(ledPinBot6, HIGH);
    failed = 1;
    ServoFailed();
    } }











    }

    void ServoComplete(){



int pos = 0;    // variable to store the servo position
    myservo.attach(11);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }


    void ServoFailed(){

    


int pos = 90;    // variable to store the servo position
    myservo.attach(11);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }

 
