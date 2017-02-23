#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

class DurationTimer
{
    std::string m_Name;
    const int m_Line;
    std::chrono::high_resolution_clock::time_point m_Start;
public:
    explicit inline DurationTimer(const std::string &Name)
        : m_Name(Name)
        , m_Line(0)
        , m_Start(std::chrono::high_resolution_clock::now())
    {
    }

    explicit inline DurationTimer(const std::string &Name, int Line)
        : m_Name(Name)
        , m_Line(Line)
        , m_Start(std::chrono::high_resolution_clock::now())
    {
    }

    inline ~DurationTimer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        Print(end-m_Start);
    }

    void Print(std::chrono::duration<double, std::milli> elapsed) const;
};

#define DURATION_TIMER   DurationTimer DefineTimer(__FILE__, __LINE__)

inline unsigned int GetMilliSec()
{
    struct timespec re;
    // ANVÄND EJ: CLOCK_REALTIME ändras med systemklockan
    if(clock_gettime(CLOCK_MONOTONIC_RAW, &re) < 0)
        return 0;
    return re.tv_nsec / 1000000 + re.tv_sec * 1000;
}

#endif
