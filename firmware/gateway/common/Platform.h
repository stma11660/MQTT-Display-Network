#pragma once

namespace mdn
{
    constexpr char PLATFORM[] = PLATFORM_NAME;
}

#if defined(ESP8266)

#include <ESP8266WiFi.h>

constexpr char PLATFORM_NAME[] = "ESP8266";

#elif defined(ESP32)

#include <WiFi.h>

constexpr char PLATFORM_NAME[] = "ESP32";

#else

#error Unsupported platform

#endif