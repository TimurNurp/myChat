#include "Logger.h"

Logger::Logger(const char* filename) : file(std::fopen(filename, "a"))
{
    if (!file)
    {
        throw "file open error";
    }
}

Logger::~Logger()
{
    std::fclose(file);
}

void Logger::write(const char* str)
{
   std::fputs(str, file);
}