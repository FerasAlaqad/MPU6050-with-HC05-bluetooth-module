
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(9600);


  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print(temp.temperature);
  Serial.print("#");
  Serial.print(a.acceleration.x);
  Serial.print("#");
  Serial.println(a.acceleration.y);
  

  delay(2000);
}
