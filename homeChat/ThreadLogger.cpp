#include "ThreadLogger.h"

ThreadLogger::ThreadLogger(const char* filename): Logger(filename)
{
;
}


void ThreadLogger::secureWrite(Message& str)
{
    mutex_.lock();
    
    write(str);

    mutex_.unlock();
}

void ThreadLogger::secureRead(int& countMsg)
{
    mutex_.lock_shared();
    
    read(countMsg);

    mutex_.unlock_shared();

}