/****************************************************
 * ESP8266_Master.ino ist der dazugehörige MQTT Receiver
 * MQTT Display Node - Arduino Nano (ST7735)
 * I2C Slave + Smooth UI + Offline Detection
 ****************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

/* ================= CONFIG ================= */

#define I2C_ADDRESS   0x10   // pro Nano ändern
#define TIMEOUT_MS    30000

#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

/* ================= DATA ================= */

struct SensorData
{
    int16_t temperature;   // x10
    uint16_t humidity;     // x10
    uint16_t pressure;     // hPa
};

/* ================= CRC16 ================= */

uint16_t crc16(const uint8_t* data, uint8_t len)
{
    uint16_t crc = 0xFFFF;

    for (uint8_t i = 0; i < len; i++)
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

/* ================= DISPLAY ================= */

class Display
{
private:
    Adafruit_ST7735 tft;

    SensorData current{};
    SensorData target{};

    bool hasData = false;

    unsigned long lastUpdate = 0;
    uint8_t fade = 0;

public:
    Display()
        : tft(TFT_CS, TFT_DC, TFT_RST)
    {}

    void begin()
    {
        tft.initR(INITR_BLACKTAB);
        tft.setRotation(1);
        tft.fillScreen(ST77XX_BLACK);

        drawHeader();
    }

    void drawHeader()
    {
        tft.setTextColor(ST77XX_WHITE);
        tft.setTextSize(2);
        tft.setCursor(10, 5);
        tft.print("Sensor");
    }

    void setData(const SensorData& d)
    {
        target = d;
        hasData = true;
        lastUpdate = millis();
        fade = 0;
    }

    void tick()
    {
        if (hasData)
            animate();

        if (millis() - lastUpdate > TIMEOUT_MS)
            offline();
    }

private:

    /* ===== Smooth Animation ===== */

    int16_t step(int16_t cur, int16_t tgt)
    {
        int16_t diff = tgt - cur;

        if (diff > 10) return 5;
        if (diff < -10) return -5;

        return diff;
    }

    void animate()
    {
        current.temperature += step(current.temperature, target.temperature);
        current.humidity    += step(current.humidity, target.humidity);
        current.pressure    += step(current.pressure, target.pressure);

        render();
    }

    /* ===== Render ===== */

    void render()
    {
        tft.fillRect(0, 30, 160, 90, ST77XX_BLACK);

        tft.setTextSize(2);

        tft.setTextColor(ST77XX_WHITE);

        tft.setCursor(10, 35);
        tft.print(current.temperature / 10.0);
        tft.print(" C");

        tft.setCursor(10, 55);
        tft.print(current.humidity / 10);
        tft.print(" %");

        tft.setCursor(10, 75);
        tft.print(current.pressure);
        tft.print(" hPa");
    }

    /* ===== OFFLINE MODE ===== */

    void offline()
    {
        fade++;

        if (fade < 5)
        {
            tft.fillScreen(ST77XX_BLACK);
            delay(40);
            return;
        }

        tft.fillScreen(ST77XX_BLACK);

        tft.setTextColor(ST77XX_RED);
        tft.setTextSize(2);

        tft.setCursor(15, 40);
        tft.print("NO SIGNAL");

        tft.setCursor(20, 70);
        tft.print("WAITING");
    }
};

/* ================= I2C ================= */

volatile SensorData buffer;
volatile bool newData = false;

Display display;

void receiveEvent(int len)
{
    if (len < (int)sizeof(SensorData) + 2)
        return;

    uint8_t raw[32];

    uint8_t i = 0;
    while (Wire.available() && i < sizeof(raw))
        raw[i++] = Wire.read();

    SensorData d;
    memcpy(&d, raw, sizeof(SensorData));

    uint16_t receivedCRC;
    memcpy(&receivedCRC, raw + sizeof(SensorData), 2);

    uint16_t calc = crc16((uint8_t*)&d, sizeof(SensorData));

    if (calc == receivedCRC)
    {
        buffer = d;
        newData = true;
    }
}

/* ================= SETUP / LOOP ================= */

void setup()
{
    Wire.begin(I2C_ADDRESS);
    Wire.onReceive(receiveEvent);

    display.begin();
}

/*
void loop()
{
    if (newData)
    {
        newData = false;
        display.setData(buffer);
    }

    display.tick();
}
*/
void loop()
{
    if (newData)
    {
        noInterrupts();

        SensorData data = buffer;
        newData = false;

        interrupts();

        display.setData(data);
    }

    display.tick();
}