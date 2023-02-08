#include "Logger.h"
#include <thread>
#include <shared_mutex>

class ThreadLogger : public Logger
{
    void secureWrite(Message& str);
    void secureRead(int& countMsg);

    private:
      shared_mutex shared_mutex;
}