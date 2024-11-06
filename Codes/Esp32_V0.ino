#include <EEPROM.h>

int address = 0;

void setup() {
    Serial.begin(115200);
    EEPROM.begin(512);
}

void loop() {
    while (address < 512 - 6) {  // Read in chunks (each 6 bytes for 3 axes)
        int16_t ax, ay, az;

        // Read each axis value from EEPROM
        EEPROM.get(address, ax); address += 2;
        EEPROM.get(address, ay); address += 2;
        EEPROM.get(address, az); address += 2;

        // Print the data for each axis
        Serial.print("X: "); Serial.print(ax);
        Serial.print(" Y: "); Serial.print(ay);
        Serial.print(" Z: "); Serial.println(az);

        delay(10);  // Small delay to allow serial reading
    }
    while (1);  // Stop after all data is read
    
}
