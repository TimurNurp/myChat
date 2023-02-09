#pragma once
#include <fstream>
#include <iostream>
#include "Message.h"


class Logger
{
   public:
       Logger(const char* filename);

       ~Logger();
     

        // 
       Logger(const Logger&) = delete;
       Logger& operator=(const Logger&) = delete;

       void write(Message& str);
       void read(int& countMsg);

    private:
        std::fstream file;
 };

