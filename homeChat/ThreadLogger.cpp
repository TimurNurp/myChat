#include "ThreadLogger.h"

void ThreadLogger::secureWrite(Message& str)
{
    shared_mutex_.lock();
    
    write(str);

    shared_mutex_.unlock();
}

void ThreadLogger::secureRead(int& countMsg)
{
    shared_mutex_.shared_lock();
    
    read(countMsg);

    shared_mutex_.shared_unlock();
}