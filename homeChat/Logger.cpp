#include "Logger.h"


Logger::Logger(const char* filename) : file(filename,std::ios_base::app)
{
  
        if (!file.is_open())
    {
        throw "file open error";
    }
}

Logger::~Logger()
{
    file.close();
}

void Logger::write(Message& str)
{
   file << str.getFrom() << '\n' << str.getTo() << '\n'<< str.getText() << std::endl;
}

void Logger::read(int& countMsg)

{
    string s; 
    for (int i=0; i < countMsg; i++)
        {
            getline(file,s); 
            std::cout << s << std::endl;
        }  
}