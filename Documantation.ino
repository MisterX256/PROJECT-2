/*
Автоматична врата
*/

// defines pins numbers
const int trigPin = 9; //Connects the UltraSonic Sensor's Trigger with Arduino .
const int echoPin = 10;//Connects the UltraSonic Sensor's Echo with Arduino. 
const int buzzPin = 11;//Connects the Buzzer with Arduino. 
const int motPinA = 2; // Magnet 1;
const int motPinB = 3; // Magnet 2;
const int openPin = 4; // Opened door;
const int closePin = 5; // Closed door;
long duration;
int distance; 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(motPinA, OUTPUT); // Sets the motPinA as an Output;
  pinMode(motPinB, OUTPUT); //Sets the motPinB as an Output;
  pinMode(openPin, INPUT); //Sets the openPin as an Input;
  pinMode(closePin, INPUT);//Sets the closePin as an Input;
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output;
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input;
  pinMode(buzzPin, OUTPUT); //Sets the buzzPin as an Output;
}

// the loop function runs over and over again forever

void loop() {
  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // After what it has to respond;
digitalWrite(trigPin, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH); // Calculating the distance.It always multiple to 0.034.
distance= duration*0.034/2;

if(distance>50){ // if the distance is over 50 cm  the first Magnet stops but the second is working and stops the DC MOTOR. The door is closed.
    while(!digitalRead(closePin)){
      digitalWrite(motPinB, LOW); 
      digitalWrite(motPinA, HIGH);
    }  
  digitalWrite(motPinB, LOW);
  digitalWrite(motPinA, LOW);
}
if(distance<=50){
  while(!digitalRead(openPin)){ //if the distance is under 50 cm  the first Magnet is working abd stops the DC MOTOR but second Magnet stops working. The door is opened.
    digitalWrite(motPinB, HIGH);
    digitalWrite(motPinA, LOW);
  }
  digitalWrite(motPinB, LOW); 
  digitalWrite(motPinA, LOW);
  tone(buzzPin, 1000); // After the door is opened creates a sound that last a few seconds.
  delay(2000);  // After what it has to respond;
  noTone(buzzPin); //The sound stops;
  delay(1000);  // After what it has to respond;
}


}
