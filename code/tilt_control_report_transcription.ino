
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int controlPin = 2;

void setup() {
  Wire.begin();
  mpu.initialize();
  pinMode(controlPin, OUTPUT);
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // ONLY RIGHT tilt
  if (ax > 5000) {
    digitalWrite(controlPin, LOW);  // RUN
  }
  else {
    digitalWrite(controlPin, HIGH); // STOP
  }

  delay(100);
}

