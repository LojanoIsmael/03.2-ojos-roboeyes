// debug_serial.h
// ============================================
// RESPONSABILIDAD: Leer comandos del Monitor Serie y mostrar la ayuda.
// No sabe nada de: bus I2C, OLED, logos ni animacion interna de los ojos.
// ============================================

#ifndef DEBUG_SERIAL_H
#define DEBUG_SERIAL_H

#include <Arduino.h>
#include "config.h"
#include "eyes.h"

// TODO 4.1: Publica el bloque de ayuda con las 7 expresiones y la tecla de ayuda.
// Pregunta Guía: ¿Qué debe ver un compañero que abre el monitor por primera vez?
inline void printHelp() {
    /* ESCRIBE TU CÓDIGO AQUÍ */
    Serial.println("[DEBUG] 1=Neutra 2=Feliz 3=Enojada 4=Cansada")
    Serial.println("[DEBUG] 5=Soñolienta 6=Temible 7=Curiosa ")
}

// TODO 4.2: Atiende el puerto sin bloquear: una tecla, respuesta inmediata; teclas 1 a 7 cambian la expresión, h repite la ayuda, los caracteres de control se ignoran en silencio.
// Pregunta Guía: ¿Qué pasa con una tecla desconocida y qué pasa con un carácter de control?
inline void debugSerialTick() {
    /* ESCRIBE TU CÓDIGO AQUÍ */
    while (Serial.available()>0){
        char p = Serial.read();

        if (p == '\n' || p == '\r' || p == ''){
            continue;
        }
        if (p>= '1' && p<='7'){
            setEyesMood(p);
        }
        else if (p == '\n' || p == 'H'){
            printHelp();
        }else{
            Serial.print("[DEBUG] comando desconocido: ");
            Serial.println(p);
        }

    }
}

#endif
