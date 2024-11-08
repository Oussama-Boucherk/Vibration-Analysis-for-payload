#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
    Serial.begin(9600);
    Wire.begin();  // SDA on GPIO 21, SCL on GPIO 22
    mpu.initialize();

    if (mpu.testConnection()) {
        Serial.println("MPU6050 connection successful");
    } else {
        Serial.println("MPU6050 connection failed");
    }
}

void loop() {
  
    // Your main data logging code here
    for(int i=0;i<1000;i++){
   uint16_t Ax = mpu.getAccelerationX();
   uint16_t Ay = mpu.getAccelerationY();
   uint16_t Az = mpu.getAccelerationZ();
   
   Serial.print(Ax)
   Serial.print(Ay)
   Serial.print(Az)
   
   delay(60);
   }
   while(1){delay(10);};
}
