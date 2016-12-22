#ifndef CURRENT_TIME_H
#define CURRENT_TIME_H

#include <chrono>
#include <cstdint>

class CurrentTime {
    std::chrono::high_resolution_clock m_clock;

public:
    uint64_t milliseconds();
    uint64_t microseconds();
    uint64_t nanoseconds();
};

uint64_t CurrentTime::milliseconds() 
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
              (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::microseconds() 
{
    return std::chrono::duration_cast<std::chrono::microseconds>
              (m_clock.now().time_since_epoch()).count();
}

uint64_t CurrentTime::nanoseconds()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>
              (m_clock.now().time_since_epoch()).count();
}    

#endif  /* CURRENT_TIME_H */