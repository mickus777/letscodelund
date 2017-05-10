#include <iostream>
#include <vector>

#include "ord.h"

using namespace std;

int main(int argc, char *argv[])
{
#ifndef SKRIPT_RUN
    argc += 1;
#endif
    if(argc <= 1)
    {
        cerr << "no argv" << argc << "\n";
        return -1;
    }

#ifndef SKRIPT_RUN
//    argv[1]="test.txt";
    argv[1]="alice.txt";
//    argv[1]="bible.txt";
#endif

    ord o;
    for(int i=1;i<argc ; ++i)
    {
//        cout << i << ") " << argv[i] << "\n";
        o.load(argv[i]);
    }
    o.write();

    return 0;
}

