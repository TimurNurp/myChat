#include "Logger.h"
#include <thread>
#include <mutex>
#include <shared_mutex>


class ThreadLogger : public Logger
{   
  public:
    ThreadLogger(const char* filename);

    void secureWrite(Message& str);
    void secureRead( int& countMsg);

  private:
      mutable std::shared_mutex mutex_;
};
