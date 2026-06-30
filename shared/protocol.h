#pragma once

/*
 * MQTT Display Network
 * Shared communication protocol
 */

#include <Arduino.h>

/*----------------------------------------------------------
  Protocol Version
----------------------------------------------------------*/
namespace mdn
{
    constexpr uint8_t PROTOCOL_VERSION = 1;
}

/*----------------------------------------------------------
  Packet Command IDs
----------------------------------------------------------*/
enum class PacketType : uint8_t
{
    SENSOR_DATA = 0x01,
    PING        = 0x02,
    ACK         = 0x03
};

/*----------------------------------------------------------
  Sensor packet
  All values are transmitted as integers.
----------------------------------------------------------*/
struct SensorPacket
{
    int16_t  temperature;   // °C x10
    uint16_t humidity;      // %RH x10
    uint16_t pressure;      // hPa

    uint16_t crc;
};

static_assert(sizeof(SensorPacket) == 8,
              "SensorPacket size must be exactly 8 bytes.");