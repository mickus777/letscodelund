#include <iostream>

#include "bildaria.h"
#include "koch.h"
#include "help.h"

using namespace std;

int rgb_r = 255;
int rgb_g = 0;
int rgb_b = 0;

int main(int argc, char *argv[])
{
    int NivaLoop = 2;
    auto arg = InitArgv(argc, argv);

    arg=1;
    Global::P_Type=1;

    if(argv[arg])
        NivaLoop = atoi(argv[arg]);

    koch k;
    k.make_str(NivaLoop);
    k.rita();

    return Global::ReturnStatus;
}

