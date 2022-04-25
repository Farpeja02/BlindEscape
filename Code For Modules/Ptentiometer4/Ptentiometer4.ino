#include <Servo.h>
/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

    Servo myservo;  // create servo object to control a servo

const int buttonPin = 3;     // the number of the pushbutton pin
int buttonState = 1;         // variable for reading the pushbutton status
int ledPinBot = 2;


int ledPinBot5 = 13;
int ledPinBot6 = 12;



int failed = 0;

int solved = 0;
// the setup routine runs once when you press reset:
void setup() {
  ServoFailed();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(ledPinBot, OUTPUT);

  pinMode(ledPinBot5, OUTPUT);
  pinMode (ledPinBot6, OUTPUT);


  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPinBot, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(buttonPin);

  
  
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);

    
  
//if the bottom is pressed and the analog values are within the margins, the modules is complete, else it fails.
  if (buttonState == LOW) {

    if (sensorValue1 > 800 && sensorValue1 < 1000 && sensorValue2 < 140 && sensorValue2 > 0 && sensorValue3 > 900  && sensorValue4 < 950 && sensorValue4 >800) {

      digitalWrite(ledPinBot, LOW);
    digitalWrite(ledPinBot5, HIGH);
    
    ServoComplete();
    }

    else { digitalWrite(ledPinBot6, HIGH); }
    


    
  }
}


    void ServoComplete(){

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
    myservo.attach(11);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }


    void ServoFailed(){


// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
    myservo.attach(11);  // attaches the servo on pin 9 to the servo object



         myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }
