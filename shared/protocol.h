// protocol.h

#pragma once

#define PROTOCOL_VERSION 1

struct SensorPacket
{
    int16_t temperature;
    uint16_t humidity;
    uint16_t pressure;
    uint16_t crc;
};