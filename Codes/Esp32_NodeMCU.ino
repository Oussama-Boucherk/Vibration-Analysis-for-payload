#include <Wire.h>
#include <MPU6050.h>
#include <SD.h>
#include <SPI.h>

MPU6050 mpu;
const int chipSelect = 5;  // Chip Select pin for SD card module

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();

    // Initialize SD card
    if (!SD.begin(chipSelect)) {
        Serial.println("SD card initialization failed!");
        while (1);
    }
    Serial.println("SD card initialized.");

    // Check MPU6050 connection
    if (mpu.testConnection()) {
        Serial.println("MPU6050 connection successful.");
    } else {
        Serial.println("MPU6050 connection failed.");
        while (1);
    }

    // Create a new data file
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if (dataFile) {
        dataFile.println("Time,Accel_X,Accel_Y,Accel_Z");  // CSV headers
        dataFile.close();
    }
}

void loop() {
    int16_t ax, ay, az;

    // Read accelerometer values
    mpu.getAcceleration(&ax, &ay, &az);

    // Get the current time (could use millis or a custom timer)
    unsigned long currentTime = millis();

    // Open file to append data
    File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if (dataFile) {
        // Write data in CSV format
        dataFile.print(currentTime); dataFile.print(",");
        dataFile.print(ax); dataFile.print(",");
        dataFile.print(ay); dataFile.print(",");
        dataFile.println(az);

        dataFile.close();
        Serial.println("Data written to SD card.");
    } else {
        Serial.println("Failed to open file for writing.");
    }

    delay(10);  // Adjust delay for your sampling rate needs
}
