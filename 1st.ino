/*
Автоматична врата
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzPin = 11;
const int motPinA = 2;
const int motPinB = 3;
const int openPin = 4;
const int closePin = 5;

// defines variables
long duration;
int distance;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(motPinA, OUTPUT);
  pinMode(motPinB, OUTPUT);
  pinMode(openPin, INPUT);
  pinMode(closePin, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzPin, OUTPUT);
  //Serial.begin(9600); // Starts the serial communication
}

// the loop function runs over and over again forever

void loop() {
/*
// LED  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
*/
  
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

if(distance>50){
    while(!digitalRead(closePin)){
      digitalWrite(motPinB, LOW);
      digitalWrite(motPinA, HIGH);
    }  
  digitalWrite(motPinB, LOW);
  digitalWrite(motPinA, LOW);
}
if(distance<=50){
  while(!digitalRead(openPin)){
    digitalWrite(motPinB, HIGH);
    digitalWrite(motPinA, LOW);
  }
  digitalWrite(motPinB, LOW);
  digitalWrite(motPinA, LOW);
  tone(buzzPin, 1000);
  delay(2000);
  noTone(buzzPin);
  delay(1000);
}

/*  
//buzzer
  tone(buzzPin, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzPin);     // Stop sound...
  delay(1000);   
*/
/*
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
*/

}
