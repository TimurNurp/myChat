#pragma once
#include <fstream>

class Logger
{
   public:
       Logger(const char* filename);

       ~Logger();
     

        // «апрещаем копирование и присваивание
       Logger(const Logger&) = delete;
       Logger& operator=(const Logger&) = delete;

       void write(const char* str);


    private:
        FILE* file;
 };

