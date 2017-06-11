#include <iostream>
#include <vector>

#include <stdlib.h>
#include <string.h>

#include "bruijn.h"

using namespace std;


char* uniq_char(char *to, const char *from)
{
    int ito=0;
    to[0]='\0';

    for(int i=0;from[i];++i)
    {
        if(nullptr == strchr(to, from[i]))
            to[ito++]=from[i];
    }
    to[ito]='\0';

    return to;
}

int main(int argc, char *argv[])
{
#ifndef SKRIPT_RUN
    argc += 2;
#endif

    if(argc <= 2)
    {
        cerr << "no argv" << argc << "\n";
        return -1;
    }

#ifndef SKRIPT_RUN
    argv[1]="AaAbAa";
    argv[2]="4";
#endif

    auto arr=strtol(argv[1],0,10);
    auto len=strtol(argv[2],0,10);

    if(0 == arr)
    {
        char tmp[0xff];
        Bruijn b(uniq_char(tmp, argv[1]), len);
        cout << b << "\n";
    }
    else
    {
        Bruijn b(arr, len);
        cout << b << "\n";
    }

    return 0;
}
