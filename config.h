#pragma once

#include <Arduino.h>

// ============================================================================
// config.h - Configuracion global unica del proyecto (Semana 03.2)
// Sistema Embebido ESP32 - Expresiones oculares OLED (RoboEyes) y FSM de arranque
//
// Un solo archivo de configuracion por proyecto: aqui viven los parametros
// fisicos de hardware y los tiempos del sistema. Ningun modulo los redefine.
// ============================================================================

// --- Bus I2C (compartido por todos los perifericos del sistema) -------------
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22
#define I2C_FREQUENCY_HZ 400000
#define I2C_PANEL_ADDR 0x3C

// --- Pantalla OLED SSD1306 (unica pantalla del sistema) ---------------------
#define OLED_I2C_ADDRESS 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET_PIN -1

// --- Modulo de ojos (RoboEyes) ---------------------------------------------
#define EYES_MAX_FPS 60

// --- Maquina de estados de arranque (FSM BOOT -> RUN) ----------------------
#define LOGO_TIME_MS 3000
