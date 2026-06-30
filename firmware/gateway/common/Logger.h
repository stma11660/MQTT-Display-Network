#pragma once

namespace mdn::logger
{
    void begin();

    void banner();

    void info(const char* text);

    void warn(const char* text);

    void error(const char* text);
}