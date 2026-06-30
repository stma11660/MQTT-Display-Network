#include "Logger.h"

void setup()
{
    mdn::logger::begin();

    mdn::logger::banner();

    mdn::logger::info("Gateway starting...");
}

void loop()
{

}


/*
int main()
{
    mdn::logger::begin();

    mdn::logger::info("MQTT Display Network");

    mdn::logger::info(PLATFORM_NAME);

    while(true)
    {

    }
}
*/

