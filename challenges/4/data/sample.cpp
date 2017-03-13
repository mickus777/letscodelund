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
        switch (argv[1][0])
        {
        case 'h':
            step=600;
            break;

        case 'R':
            r_mod = 900;
            break;

        case 'r':
            r_mod = 90;
            break;

        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            r_mod = argv[1][0] - '0';
            break;

        default:
            error_end("Bad argv");
        }
    }

    srand(step); // Fel, men att få samma tal kan vara en fördel

    for(i=0 ; i < 50000 - step ; i+=step)
        cout << i + (rand() % r_mod) << "\n";

    for(; i < 0 ; i-=step)
        cout << i + (rand() % r_mod) << "\n";

    return 0;
}
