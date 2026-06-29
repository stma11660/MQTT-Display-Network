#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define WIFI_SSID "EG"
#define WIFI_PASS "Die_Matrix@Neu-Isenburg"

#define MQTT_SERVER "192.168.2.26"
#define MQTT_PORT 1883

const char MQTT_CLIENT[] = "ESP_DisplayMaster";

struct DisplayNode
{
    const char* topic;
    uint8_t address;
};

static DisplayNode nodes[] =
{
    { "haus/wohnzimmer", 0x10 },
    { "haus/aussen",     0x11 },
    { "haus/heizung",    0x12 }
};

static const uint8_t NODE_COUNT =
    sizeof(nodes) / sizeof(nodes[0]);

#endif