/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <rickard@letscodelund> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Rickard S
 * ----------------------------------------------------------------------------
 */
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
    // Test reboot
    //int ReturnStatus = 99;

    bool RunCarriedas = true;

    UnionSettings BitSettings;

    // För test av bildfel
    unsigned int TestBildError=0;

    // Kolla att inte UnionSettings blir för stor..
    static_assert(sizeof(union UnionSettings) == sizeof(unsigned int),
                  "UnionSettings to big!?");
}

void help_end(const char *pc)
{
    if(pc)
        fprintf(stderr, "ERROR: \"%s\"\n", pc);

    fprintf(stderr, "Opt:\n"
                 " -m    Alloc img mem from new (fejk)\n"
                 " -a    Generate test raw picture(mem: abcdef...)\n"
                 " -o    Start or stop writing to stdout, change the default\n"
                 " -n    Null Img mem\n"
                 " -c    Start with ImageSensor in Continuous mode\n"
                 " -H    Horizontal Flip\n"
                 " -V    Vertical Flip\n"
                 " -t[x] Image Sensor test bild, num 1-6\n"
                 " -h    This help\n"
                 "\n"
                 " Compile time: " __DATE__ "  " __TIME__ "\n"
            );

    exit(pc ?  EXIT_FAILURE : EXIT_SUCCESS);
}

int InitArgv(int argc, char *argv[])
{
    int option_char;

#ifdef BUILD_RELEASE
    Global::BitSettings.stdoutError = 0;
#else
    Global::BitSettings.stdoutError = 1;
#endif

    while((option_char = getopt(argc,argv,"hanmsocHVt:")) != -1)
    {
        switch(option_char)
        {
        case 'h':
            help_end(NULL);
            break;

        case 'a':
            Global::BitSettings.MemABC = 1;
            Global::BitSettings.testPictur = 1;    // RM
            break;

        case 'n':
            Global::BitSettings.MemNull = 1;
            Global::BitSettings.NullMem = 1;    // RM
            break;

        case 'm':
            Global::BitSettings.newMem = 1;
            break;

        case 'c':
            Global::BitSettings.ImageContinuous = 1;
            break;

        case 'H':
            Global::BitSettings.FlipHorizontal = 1;
            break;

        case 'V':
            Global::BitSettings.FlipVertical = 1;
            break;

        case 'o':
            Global::BitSettings.stdoutError = !Global::BitSettings.stdoutError;
            break;

        case 't':
            {
                if(optarg)
                {
                    auto value = atoi(optarg);
//                    cout << "optarg:" << optarg << " -> " << value << "\n";
                    if(value > 0 && value <= 6) // OBS: TestBild är bara 3 bitar
                        Global::BitSettings.TestBild = value;
                }
            }
            break;

        default:
            help_end("Bad argv opt");
            break;
        }
    }

    /// System setup

    // Stoppar en signal(SIGPIPE) som kunde komma vid error i nätverks kommunikation
    signal(SIGPIPE, SIG_IGN);

    // Set defult mask, defult write chmod 666  fungerar tvärt om.
    umask(0);

    return 0;
}


void debug_print_error_nocall(const char *file, int line, int status)
{
    if(0 == status)
        return;

    fprintf(stderr, "ERROR: Status:%d - File:%s - Line:%3d\n", status, file, line);
    exit(EXIT_FAILURE);
}
