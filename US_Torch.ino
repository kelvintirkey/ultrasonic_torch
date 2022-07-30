#define trigPin 3
#define echoPin 2
#define buzzer 6
#define motorPin 13
#define buttonPin 7

int count=4;
int buttonState = 0; 
long duration;
int distance;
int safeDistance;


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(motorPin, OUTPUT);
pinMode(buttonPin, INPUT); 
Serial.begin(9600); 
}


void loop() {

buttonState = digitalRead(buttonPin);
    
if (buttonState == HIGH) {
  if (count<9){
    count ++;
    for (int i=0; i<(count-3); i++){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
    }
  }
  else{
    count=4;
    for (int i=0; i<(count-3); i++){
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }
  }
}  

digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;
safeDistance = count*10;


if (distance <= safeDistance){
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
