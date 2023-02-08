#include "Logger.h"
#include <thread>
#include <shared_mutex>
#include <mutex>

class ThreadLogger : public Logger
{
    void secureWrite(Message& str);
    void secureRead(int& countMsg);

    private:

      mutable std::shared_mutex shared_mutex_;
}