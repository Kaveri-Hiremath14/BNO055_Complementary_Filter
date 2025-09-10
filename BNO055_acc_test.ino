#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup() {
  Serial.begin(9600);
  delay(1000);

  if (!bno.begin()) {
    Serial.println("BNO055 not detected. Check wiring!");
    while (1);
  }

  delay(1000);
  bno.setExtCrystalUse(true);

  Serial.println("BNO055 Raw Accelerometer Roll & Pitch");
}

void loop() {
  sensors_event_t accelEvent;
  bno.getEvent(&accelEvent, Adafruit_BNO055::VECTOR_ACCELEROMETER);

  
  float roll  = atan2(accelEvent.acceleration.y, accelEvent.acceleration.z) * 180.0 / PI;
  float pitch = atan2(-accelEvent.acceleration.x,
                      sqrt(accelEvent.acceleration.y * accelEvent.acceleration.y +
                           accelEvent.acceleration.z * accelEvent.acceleration.z)) * 180.0 / PI;

  
  Serial.print(roll);
  Serial.print(" ");
  Serial.println(pitch);

  delay(50); 
}
