#ifndef HELP_H
#define HELP_H

#include <iostream>
#include <fstream>
#include <atomic>

#include <stdlib.h>


//using namespace std;

/*
 * Good macro
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef _DEBUG
# define DEBUG_STR(S)      printf("[File: %-10s, Line: %3d] " #S " =  %s\n", __FILE__, __LINE__,S);
# define DEBUG_INT(S)      printf("[File: %-10s, Line: %3d] " #S " =  %8d\n", __FILE__, __LINE__,S);
# define DEBUG_HEX(S)      printf("[File: %-10s, Line: %3d] " #S " = 0x%08X\n", __FILE__, __LINE__, S);
#else
# define DEBUG_STR(S)      { }
# define DEBUG_INT(S)      { }
# define DEBUG_HEX(S)      { }
#endif

#ifdef __cplusplus
template <class T>
inline void error_end_nocall(const char *file, int line, const T &v)
{
    std::cerr << "ERROR: \"" <<  v << "\" - File:" << file << " - Line:" << line << "\n";
    exit(EXIT_FAILURE);
}
#else

void error_end_nocall(const char *file, int line, const char *pc);
/*
{
#ifdef USE_FCGI
    output_fastcgi();
#endif
    fprintf(stderr, "ERROR: \"%s\" - File:%s - Line:%3d\n", pc, file, line);
    exit(EXIT_FAILURE);
}
*/
#endif  // __cplusplus

#define error_end(S)   error_end_nocall(__FILE__, __LINE__, S)


#define STATIC_NUMBER2STRING(a) # a

#define FILE_LINE_STR_PART(x,y) { x ", line " STATIC_NUMBER2STRING(y) ": "}
#define FILE_LINE_STR  FILE_LINE_STR_PART(__FILE__, __LINE__)

// Test no num 2 string..
void error_end_nocall_test(const std::string &, const std::string &);
#define error_end_test(S)     error_end_nocall_test(S, FILE_LINE_STR);


void debug_print_error_nocall(const char *file, int line, int status);
#define DEBUG_CHECK(S)     debug_print_error_nocall(__FILE__, __LINE__, S);

void status_nocall(const char *file, int line);
//#define STATUS()     status_nocall(__FILE__, __LINE__);
#define STATUS()  {}

constexpr unsigned int ConstCharHash(const char *pc)
{
    // | 1 PGA man inte vill det ska kunna bli 0
    return (pc[0] ? (ConstCharHash(&pc[1]) | 1) * (unsigned int)pc[0] : (unsigned int)1048583);
}


namespace Global
{
    extern int ReturnStatus;
    extern int P_Type;
}

void help_end(const char *pc);
int InitArgv(int argc, char *argv[]);

#endif // HELP_H
