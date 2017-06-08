#include <iostream>
#include <stdlib.h>

using namespace std;

static inline unsigned int countd(unsigned int i1 , unsigned int i2)
{
    return i1 / i2;
}
static inline unsigned int countp(unsigned int i1 , unsigned int i2)
{
    return i1 + i2;
}
static inline unsigned int countg(unsigned int i1 , unsigned int i2)
{
    return i1 * i2;
}

int main (int argc, char *argv[])
{
    u_int32_t sum = 0;
    srand(time(0));
    auto f = countp;

    if(argc < 1)
        return -1;

    switch (*argv[1]) {
    case '/':
        f = countd;
        break;
    case '+':
        f = countp;
        break;
    case 'x':
        f = countg;
        break;

    default:
        return -2;
        break;
    }

    for(unsigned int loop = 1 ; 0!=loop ; ++loop)
    {
        sum += f(rand() + 1, rand() + 1);
    }

    cout << sum << "\n";
    return 0;
}

