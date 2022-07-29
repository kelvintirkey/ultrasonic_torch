#define trigPin 3
#define echoPin 2
#define buzzer 6
#define motorPin 7


long duration;
int distance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(motorPin, OUTPUT);
Serial.begin(9600); 
}


void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;

if (distance <= 30){
  digitalWrite(buzzer, HIGH);
  digitalWrite(motorPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(motorPin, LOW);
}


Serial.print("Distance: ");
Serial.println(distance);
}
