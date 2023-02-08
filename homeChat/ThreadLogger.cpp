#include "ThreadLogger.h"

void ThreadLogger::secureWrite(Message& str)
{
    shared_mutex.lock();
    
    write(str);

    shared_mutex.unlock();
}

void ThreadLogger::secureRead(int& countMsg)
{
    shared_mutex.shared_lock();
    
    read(countMsg);

    shared_mutex.shared_unlock();
}