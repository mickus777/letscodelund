#include <iostream>

#include "bildaria.h"
#include "koch.h"
#include "help.h"

using namespace std;

int rgb_r = 255;
int rgb_g = 0;
int rgb_b = 0;
int NivaLoop = 2;

int main(int argc, char *argv[])
{
/*
    BildAria b;
    b.save("Test.ppm");
*/
    auto arg = InitArgv(argc, argv);

    arg=1;
    Global::P_Type=1;

    if(argv[arg])
        NivaLoop = atoi(argv[arg]);

#ifndef SKRIPT_RUN
    NivaLoop = 8;
#endif

    koch k;
    k.make_str(NivaLoop);
    k.rita();

//    cout << "Hello World!" << endl;
    return Global::ReturnStatus;
}

