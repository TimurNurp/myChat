#pragma once
#include <fstream>

class Logger
{
   public:
       Logger(const char* filename);

       ~Logger();
     

        // ��������� ����������� � ������������
       Logger(const Logger&) = delete;
       Logger& operator=(const Logger&) = delete;

       void write(const char* str);


    private:
        FILE* file;
 };

