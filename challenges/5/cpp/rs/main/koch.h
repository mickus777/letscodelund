#ifndef KOCH_H
#define KOCH_H

#include <string>

#include "bildaria.h"

class koch
{
    std::string m_str = "F";
public:
    ~koch();


    void make_str(int in);
    int rita();

    BildAria m_aria;
};

#endif // KOCH_H
