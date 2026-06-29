#include "I2CBus.h"
#include "MQTTManager.h"

I2CBus bus;
MQTTManager mqtt(&bus);

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println("\nESP8266 Display Gateway");

    bus.begin();
    mqtt.begin();
}

void loop()
{
    mqtt.loop();
}