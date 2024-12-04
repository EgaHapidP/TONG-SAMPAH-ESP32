#include <ESP32Servo.h>

#define TRIG_PIN 4
#define ECHO_PIN 5
#define SERVO_PIN 2

Servo myServo;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0); // posisi awal servo
}

void loop() {
  long duration, distance;

  // memicu sensor ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW);

  // membaca durasi pulsa echo 
  duration = pulseIn(ECHO_PIN, HIGH);

  // Menghitung jarak 
  distance = (duration / 2) / 29.1; // jarak dalam cm 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // jika jarak kurang dari atau sama dengan 10 cm, putar servo 90 derajat
  if (distance <=10) {
    myServo.write(90);
  } else {
    myServo.write(0); // kembali ke posisi awal 
  }

  delay(500); // menunggu sebelum pembacaan berikutnya 
}