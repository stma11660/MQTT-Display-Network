#ifndef CRC16_H
#define CRC16_H

#include <Arduino.h>

class CRC16
{
public:
    static uint16_t compute(const uint8_t* data, size_t len)
    {
        uint16_t crc = 0xFFFF;

        for (size_t i = 0; i < len; i++)
        {
            crc ^= data[i];

            for (uint8_t b = 0; b < 8; b++)
            {
                if (crc & 1)
                    crc = (crc >> 1) ^ 0xA001;
                else
                    crc >>= 1;
            }
        }

        return crc;
    }
};

#endif