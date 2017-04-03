#include <iostream>

#include <stdio.h>
#include <string.h>

#include "bildaria.h"
#include "help.h"

using namespace std;

BildAria::BildAria()
{
//    auto size = ((s_x * s_y) + 100) / 1024;
#ifdef USE_NEW
    m_data=new unsigned char[(s_x * s_y) + 100];
    memset(m_data, 0, s_x * s_y);
#endif
}

BildAria::~BildAria()
{
#ifdef USE_NEW
    delete m_data;
#endif
}

int BildAria::save(const char *pc) const
{
    FILE *fd = fopen(pc, "w");

    if(!fd)
        return -1;

    if(3==Global::P_Type)
        save_ppm_p3(fd);
    else
        save_ppm_p1(fd);

    fclose(fd);

    return 0;
}

int BildAria::save_ppm_p1(FILE *fd) const
{
    ram r = GetRam();
    r.print();

    // "$Date: " __DATE__  "  " __TIME__ " $\n"
    fprintf(fd, "P1\n" \
           "# TEXT $Date: " __DATE__  "  " __TIME__ " $ \n" \
           "%u %u\n", r.xend-r.xstar, r.yend-r.ystar);  // s_x, s_y
    for(unsigned int iy=r.ystar; iy < r.yend ; ++iy)
    {
        for(unsigned int ix=r.xstar ; ix < r.xend ; ++ix)
        {
            if(ix != r.xstar)
                fprintf(fd, " ");
            fprintf(fd, "%c", (0 != Get(ix,iy)) ? '1' : '0');
        }
        fprintf(fd, "\n");
    }

    return 0;
}

int BildAria::save_ppm_p3(FILE *fd) const
{
    ram r = GetRam();
    r.print();

    // "$Date: " __DATE__  "  " __TIME__ " $\n"
    fprintf(fd, "P3\n" \
           "# TEXT $Date: " __DATE__  "  " __TIME__ " $ \n" \
           "%u %u\n" \
           "255\n", r.xend-r.xstar, r.yend-r.ystar);  // s_x, s_y
    for(unsigned int iy=r.ystar; iy < r.yend ; ++iy)
    {
        for(unsigned int ix=r.xstar ; ix < r.xend ; ++ix)
        {
            if(ix != r.xstar)
                fprintf(fd, " ");
            if(Get(ix,iy))
                fprintf(fd, "%u %u %u", rgb_r, rgb_g, rgb_b);
            else
            {
//                fprintf(fd, "255 255 255");
                fprintf(fd, "0 0 0");
            }
        }
        fprintf(fd, "\n");
    }

    return 0;
}

ram BildAria::GetRam() const
{
    ram r;

    for(unsigned int x=0 ; x < BildAria::s_x ; ++x)
    {
        if(!TomY(x))
            break;
        r.xstar = x;
    }
    ++r.xstar;
    for(unsigned int x=BildAria::s_x-1 ; x > 0 ; --x)
    {
        if(!TomY(x))
            break;
        r.xend = x;
    }

    for(unsigned int y=0 ; y < BildAria::s_y ; ++y)
    {
        if(!TomX(y))
            break;
        r.ystar = y;
    }
    ++r.ystar;
    for(unsigned int y=BildAria::s_y-1 ; y > 0 ; --y)
    {
        if(!TomX(y))
            break;
        r.yend = y;
    }

    return r;
}

bool BildAria::TomX(unsigned int iny) const
{
    for(unsigned int x=0 ; x < BildAria::s_x ; ++x)
        if(Get(x,iny))
            return false;

    return true;
}

bool BildAria::TomY(unsigned int inx) const
{
    for(unsigned int y=0 ; y < BildAria::s_y ; ++y)
        if(Get(inx, y))
            return false;

    return true;
}

void ram::print() const
{
    cout << "xstar: " << xstar << "  ystar: "  << ystar << "  xend: " << xend << "  yend: " << yend << "\n";
}
