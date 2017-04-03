#include "help.h"

#include <iostream>

#include <getopt.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

#include <fstream>


void error_end_nocall_test(const string &v, const string &file)
{
    cerr << "ERROR: \"" <<  v << "\" - File:" << file << "\n";
    exit(EXIT_FAILURE);
}

namespace Global
{
    int ReturnStatus = EXIT_SUCCESS;
    int P_Type = 3;
}

void help_end(const char *pc)
{
    if(pc)
        fprintf(stderr, "ERROR: \"%s\"\n", pc);

    fprintf(stderr, "Opt:\n"
                 " -1    ppm typ 1\n"
                 " -h    This help\n"
                 "\n"
                 " Compile time: " __DATE__ "  " __TIME__ "\n"
            );

    exit(pc ?  EXIT_FAILURE : EXIT_SUCCESS);
}

int InitArgv(int argc, char *argv[])
{
    int option_char;

    while((option_char = getopt(argc,argv,"1h")) != -1)
    {
        switch(option_char)
        {
        case 'h':
            help_end(NULL);
            break;

        case '1':
            Global::P_Type=1;
            break;


        default:
            help_end("Bad argv opt");
            break;
        }
    }

    /// System setup

    return 0;
}


void debug_print_error_nocall(const char *file, int line, int status)
{
    if(0 == status)
        return;

    fprintf(stderr, "ERROR: Status:%d - File:%s - Line:%3d\n", status, file, line);
    exit(EXIT_FAILURE);
}
