# 1 "C:\\Users\\PC_14\\AppData\\Local\\Temp\\tmptd_dr25l"
#include <Arduino.h>
# 1 "C:/Users/PC_14/Desktop/03_Soporte/03.2-ojos-roboeyes/main.ino"






#include "config.h"
#include "i2c_manager.h"
#include "display.h"
#include "logo.h"
#include "logboot.h"
#include "eyes.h"
#include "debug_serial.h"


bool bootComplete = false;
unsigned long bootTime = 0;
void setup();
void loop();
#line 19 "C:/Users/PC_14/Desktop/03_Soporte/03.2-ojos-roboeyes/main.ino"
void setup() {
    Serial.begin(115200);
    Serial.println(F("[BOOT] sistema de ojos OLED"));
# 38 "C:/Users/PC_14/Desktop/03_Soporte/03.2-ojos-roboeyes/main.ino"
}

void loop() {





}