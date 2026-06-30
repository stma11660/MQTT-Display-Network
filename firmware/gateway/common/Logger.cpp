#include "Logger.h"

#include <Arduino.h>

namespace mdn::logger
{

void begin()
{
    Serial.begin(SERIAL_BAUDRATE);
}

void info(const char* text)
{
    Serial.print("[INFO ] ");
    Serial.println(text);
}

void warn(const char* text)
{
    Serial.print("[WARN ] ");
    Serial.println(text);
}

void error(const char* text)
{
    Serial.print("[ERROR] ");
    Serial.println(text);
}

void banner()
{
    Serial.println();
    Serial.println(F("========================================"));
    Serial.println(F(" MQTT Display Network"));
    Serial.println(F(" Distributed MQTT TFT Display System"));
    Serial.println(F(""));

    Serial.print(F(" Version  : "));
    Serial.println(MDN_VERSION_STRING);

    Serial.print(F(" Platform : "));
    Serial.println(mdn::PLATFORM);

    Serial.println(F(""));
    Serial.println(F(" Open Source Project"));
    Serial.println(F(" Started 2026"));
    Serial.println(F("========================================"));
    Serial.println();
}

}