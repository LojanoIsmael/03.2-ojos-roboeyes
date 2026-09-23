// i2c_manager.h
// ============================================
// RESPONSABILIDAD: Hablar con el bus I2C (pines, velocidad, escaneo y verificacion).
// No sabe nada de: OLED, logos, ojos ni comandos del Monitor Serie.
// ============================================

#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include "config.h"

inline void initI2C() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    Wire.setClock(I2C_FREQUENCY_HZ);
}

inline void scanI2C() {
    byte error, address;
    int cont=0;
    for (address = 1; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error=Wire.endTransmission();
        if (error=0)
        {
            Serial.print("Dispositivo encontrado en la dirección 0x");
            if (address<16)Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");
            cont++;
        }
        
    }
    Serial.print("Total de dispositivos I2C encontrados: ");
    Serial.println(cont);
    
}

inline void testI2CDevice() {
    Wire.beginTransmission(I2C_PANEL_ADDR);
    byte error = Wire.endTransmission();
    if (error==0){
        Serial.println("I2C panel encontrado y respondiendo");
    }else{
        Serial.println("I2C panel no responde. Arranque detenido");
        while (1); 
    }
}

#endif
