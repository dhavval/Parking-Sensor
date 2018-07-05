/*
  Parking Sensor

  This sketch reads a ultrasonic rangefinder
  and returns the distance to the closest object
  in range. To do this, it sends a pulse to the
  sensor to initiate a reading, then listens for
  a pulse to return.  The tone of the buzzer is
  proportional to the distance of the object from
  the sensor.
  
  https://github.com/sreenidhijayapal/rcse-ss2018-ces-parking-sensor
  
  Schematic is available on the Github link.
*/

long readUltrasonicDistance(int pin) //Initializing PINs used
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

int trigPin = 5; // defining PIN as Trigger pin of Ultrasonic sensor
int echoPin = 6; //defining PIN as Echo pin of Ultrasonic sensor

void setup() //PIN setup
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7, OUTPUT); // output for buzzer
  pinMode(8, OUTPUT); //output for Green LED
  pinMode(9, OUTPUT); //output for Yellow LED
  pinMode(10, OUTPUT); //output for RED LED
}

void loop()
{
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //EchoPin is used to read the signal, a high Pulse,
  //whose duration is in microseconds from the sending
  //of the pulse to the reception of its echo off of an object
  pinMode(echoPin, INPUT);
  int duration = pulseIn(echoPin, HIGH); //reading pulse duration
  int distance = (duration/2)/29.1; //converting microseconds to centimeters

  delay(1000); // Wait for 1000 millisecond(s) for delayed reading
  
  if (distance <= 20) {
  tone(7, 800, 500);
  digitalWrite(10, HIGH); //red
  delay(500);
  digitalWrite(10, LOW); //red
  } 
  else if (distance >20 && distance <=60)
  {
  tone(7, 500, 600);  
  digitalWrite(9, HIGH); //yellow
  delay(600);
  digitalWrite(9, LOW); //yellow
  }
  else if (distance >60 && distance <=100)
  {
  tone(7, 400, 800);  
  digitalWrite(8, HIGH); //green
  delay(800);
  digitalWrite(8, LOW); //green
  }
}
