#ifndef HELP_H
#define HELP_H

#include <time.h>

/*
 * Ger ett svara med milli sec upplösning
 * Påverkas inte om man ändrar systemklockan
 *
 * Både C och C++ varianten ger samma värde, även när man testar
 * med CLOCK_REALTIME och chrono::high_resolution_clock::now()
 *
 * C varianten är ca 3 gånger snabbare än C++11
 */
inline unsigned int GetMilliSec()
{
    struct timespec re;
    // ANVÄND EJ: CLOCK_REALTIME ändras med systemklockan
    if(clock_gettime(CLOCK_MONOTONIC_RAW, &re) < 0)
        return 0;
    return re.tv_nsec / 1000000 + re.tv_sec * 1000;

    // C++ varianten
    // ANVÄND EJ: chrono::high_resolution_clock::now()  ändras med systemklockan
//    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

#endif // HELP_H
