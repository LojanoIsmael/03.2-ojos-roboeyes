// eyes.h
// ============================================
// RESPONSABILIDAD: Animar los ojos del OLED y aplicar la expresion elegida.
// No sabe nada de: bus I2C, logos de arranque, POST ni Monitor Serie.
// ============================================

#ifndef EYES_H
#define EYES_H

#include <Arduino.h>
#include "display.h"
#include "config.h"

// Arduino.h del ESP32 define DEFAULT como 1 y RoboEyes lo define como 0. Se
// limpia esa macro (sin uso en el core) para evitar el aviso de redefinicion.
#undef DEFAULT

#include <FluxGarage_RoboEyes.h>

// Instancia global: el sistema tiene un solo par de ojos
RoboEyes<Adafruit_SSD1306> roboEyes(display);

// TODO 3.1: Inicializa los ojos con las dimensiones del panel y el objetivo de cuadros por segundo de config.h.
// Pregunta Guía: ¿Qué tres números necesita la inicialización y de dónde sale cada uno?
inline void initEyes() {
    /* ESCRIBE TU CÓDIGO AQUÍ */
    RoboEyes.begin(OLED_WIDTH, OLED_HEIGHT, EYES_FPS);
    Serial.println("[Ojos] Listos a 60 fps")
}

// TODO 3.2: Avanza la animación un paso sin bloquear; nunca envuelvas este paso en borrado/presentación ni en esperas.
// Pregunta Guía: ¿Quién es dueño del borrado y la presentación del cuadro, tu código o la librería?
inline void updateEyes() {
    /* ESCRIBE TU CÓDIGO AQUÍ */
    RoboEyes.update();
}

// TODO 3.3: Aplica la expresión pedida por tecla (1 a 7) y restablece la base limpia antes de calibrar.
// Pregunta Guía: ¿Qué cambia en pantalla entre una tecla y otra si la base no se restablece?
inline void setEyesMood(char key) {
    /* ESCRIBE TU CÓDIGO AQUÍ */
    //Rango de teclas 1 al 7
    if (key < '1'||key> '7'){
        return;
    }

    //Mapeo de expresiones mediante el número de tecla
    switch (key){
        case '1':  //Neutra: Ánimo por defecto + movimiento inactivo.
        RoboEyes.setMood(DEFAULT);
        RoboEyes.setIdleMode(ON);
        break;

        case '2':  //Feliz:	Ánimo alegre + movimiento inactivo.
        RoboEyes.setMood(HAPPY);
        RoboEyes.setIdleMode(ON);
        break;

        case '3':  //Enojada: Ánimo enojado, sin movimiento.
        RoboEyes.setMood(ANGRY);
        RoboEyes.setIdleMode(OFF);
        break;

        case '4':  //Cansada: Ánimo cansado, sin movimiento.
        RoboEyes.setMood(TIRED);
        RoboEyes.setIdleMode(OFF);
        break;

        case '5':  //Soñolienta: Cansado + parpadeo lento.
        RoboEyes.setMood(TIRED);
        RoboEyes.setAutoblinker(ON, 6, 4);
        RoboEyes.setIdleMode(OFF);
        break;

        case '6':  //Temible: Enojado + parpadeo apagado + temblor vertical.
        RoboEyes.setMood(ANGRY);
        RoboEyes.setAutoblinker(OFF);
        RoboEyes.setVFlicker(ON, 2);
        RoboEyes.setIdleMode(OFF);
        break;

        case '7':  //Curiosa: Neutro + curiosidad + movimiento inactivo rápido.
        RoboEyes.setMood(DEFAULT);
        RoboEyes.setCuriosity(ON);
        RoboEyes.setIdleMode(ON, 2, 2);
        break;

    }

    Serial.print("Expresión aplicada: ")
    Serial.println(key);
}

#endif
