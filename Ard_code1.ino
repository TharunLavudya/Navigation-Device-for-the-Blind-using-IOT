
#define echoPin 2
#define trigPin 3
const int buzzer = 9;
long duration;
long distance;
void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;

  if(distance<=40 && distance>0)
  {
    int d=map(distance,1,100,10,2000);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(d);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}








