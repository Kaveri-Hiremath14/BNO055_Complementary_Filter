#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

float roll = 0.0;  
float pitch = 0.0;  
float alpha = 0.98; 
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

  Serial.println("BNO055 Complementary Filter Roll & Pitch");
}

void loop() {
  sensors_event_t accelEvent, gyroEvent;
  bno.getEvent(&accelEvent, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno.getEvent(&gyroEvent, Adafruit_BNO055::VECTOR_GYROSCOPE);

  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0; 
  lastTime = currentTime;

  
  float roll_acc  = atan2(accelEvent.acceleration.y, accelEvent.acceleration.z) * 180.0 / PI;
  float pitch_acc = atan2(-accelEvent.acceleration.x,
                          sqrt(accelEvent.acceleration.y * accelEvent.acceleration.y +
                               accelEvent.acceleration.z * accelEvent.acceleration.z)) * 180.0 / PI;

  
  float roll_gyro  = roll + gyroEvent.gyro.x * dt * 180.0 / PI;
  float pitch_gyro = pitch + gyroEvent.gyro.y * dt * 180.0 / PI;


  roll  = alpha * roll_gyro  + (1 - alpha) * roll_acc;
  pitch = alpha * pitch_gyro + (1 - alpha) * pitch_acc;

  
  Serial.print(roll);
  Serial.print(" ");
  Serial.println(pitch);

  delay(20); 
}
