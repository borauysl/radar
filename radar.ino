#include <Servo.h> 

const int trigPin = A1; 
const int echoPin = A0; 

long duration; 
int distance; 
Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); // seri iletişimi başlatır
  myServo.attach(10); // servoyu 10 numaralı pine bağlar
}

void loop() {
  for (int i = 15; i <= 165; i++) {  
    myServo.write(i); // servoyu i derecesine döndürür
    delay(30); // kısa bir süre bekler
    distance = calculateDistance(); // mesafeyi hesaplar
    
    // açı ve mesafeyi seri porttan gönderir
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance);
    Serial.print(".");
  }

  for (int i = 165; i > 15; i--) {  
    myServo.write(i); 
    delay(30); /
    distance = calculateDistance(); 
    
    // açı ve mesafeyi seri porttan gönderir
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance() { 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // yankı süresini ölçer
  distance = duration * 0.034 / 2; // mesafeyi hesaplar (cm cinsinden)
  return distance;
}
