#include <iostream>
#include <limits>

#include <stdlib.h>

using namespace std;

template <class T>
inline void error_end_nocall(const char *file, int line, const T &v)
{
    std::cerr << "ERROR: \"" <<  v << "\" - File:" << file << " - Line:" << line << "\n";
    exit(EXIT_FAILURE);
}
#define error_end(S)   error_end_nocall(__FILE__, __LINE__, S)

int main(int argc, char *argv[])
{
    int i, step=300, r_mod=1;

    if(argc > 1)
    {
        if('h' == argv[1][0])
            step=600;
        else if('r' == argv[1][0])
            r_mod=9;
    }

    srand(step); // Fel, men att få samma tal kan vara en fördel

    for(i=0 ; i < 50000 - step ; i+=step)
        cout << i + (rand() % r_mod) << "\n";

    for(; i < 0 ; i-=step)
        cout << i + (rand() % r_mod) << "\n";

    return 0;
}
