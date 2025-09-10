#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

float roll = 0.0;   
float pitch = 0.0;  
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);

  if (!bno.begin()) {
    Serial.println("BNO055 not detected. Check wiring!");
    while (1);
  }

  delay(1000);
  bno.setExtCrystalUse(true);
  lastTime = millis();

  Serial.println("BNO055 Gyroscope Roll & Pitch");
}

void loop() {
  sensors_event_t gyroEvent;
  bno.getEvent(&gyroEvent, Adafruit_BNO055::VECTOR_GYROSCOPE);

  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0; // seconds
  lastTime = currentTime;

  
  roll  += gyroEvent.gyro.x * dt * 180.0 / PI;
  pitch += gyroEvent.gyro.y * dt * 180.0 / PI;

  
  Serial.print(roll);
  Serial.print(" ");
  Serial.println(pitch);

  delay(20); 
}

