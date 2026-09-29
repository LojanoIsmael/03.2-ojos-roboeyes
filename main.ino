// main.ino
// ============================================
// RESPONSABILIDAD: Orquestar arranque y bucle principal del sistema.
// No sabe como hacer nada: solo llama a cada modulo en el orden correcto.
// ============================================

#include "config.h"
#include "i2c_manager.h"
#include "display.h"
#include "logo.h"
#include "logboot.h"
#include "eyes.h"
#include "debug_serial.h"

// Estados de la maquina de arranque y marca de tiempo de su ventana
bool bootComplete = false;
unsigned long bootTime = 0;

void setup() {
    Serial.begin(115200);
    Serial.println(F("[BOOT] sistema de ojos OLED"));

    // TODO 1.5: Escribe las llamadas de los pasos 1 a 4 para dejar el bus y el panel listos.
    // Paso 1 — Puerto serie abierto a la velocidad del monitor (verás [BOOT] sistema de ojos OLED).
    initI2C();
    // Paso 2 — Bus I2C compartido levantado (verás [I2C] bus listo SDA=21 SCL=22).
    initDisplay();
    // Paso 3 — Barrido del bus reportado (verás el dispositivo en 0x3C y el conteo final).
    scanI2C();
    // Paso 4 — Dirección del panel sondeada (verás la respuesta del POST del OLED).
    testI2CDevice();

    // TODO 2.4: Escribe las llamadas de los pasos 5 y 6 para pintar el logo y ejecutar el POST de pantalla.
    // Paso 5 — Panel inicializado (verás el panel listo de 128x64 a 400 kHz).
    testDisplay();
    // Paso 6 — Logo pintado y POST de pantalla (verás el cuadrado de pantalla y sus coordenadas).
    showLogo();
    bootTime= millis();
    // TODO 3.4: Escribe la llamada del paso 7 para dejar los ojos listos.
    // Paso 7 — Ojos inicializados (verás los ojos listos a 60 fps).
    // TODO 4.3: Escribe la llamada del paso 8, publica la ayuda y arma la ventana de arranque.
    // Paso 8 — Ayuda publicada y ventana de arranque armada (verás la ayuda de depuración; bootTime = millis()).
}

void loop() {
    // TODO 2.4 (continuación): Mientras la ventana de arranque no expire, mantén el logo
    // en pantalla; al expirar, cambia de estado y repórtalo por el monitor.
    if (!bootComplete){
        if (millis()- bootTime>=LOGO_TIME_MS){
            bootComplete = true;
            Serial.println("[FSM] BOOT -> RUN");
        }else{
            showLogo();
        }
        return;
    }

    // TODO 4.3 (continuación): Con el arranque terminado, atiende la consola en cada
    // vuelta y deja que la animación avance un paso sin bloquear el bucle.
}
