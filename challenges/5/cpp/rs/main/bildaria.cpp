#include <iostream>

#include <stdio.h>
#include <string.h>

#include "bildaria.h"
#include "help.h"

using namespace std;

BildAria::BildAria()
{
#ifdef USE_NEW
    m_data=new unsigned char[(s_x * s_y) + 100];
    memset(m_data, 0, s_x * s_y);
#endif
}

BildAria::~BildAria()
{
#ifdef USE_NEW
    delete[] m_data;
#endif
}

int BildAria::save(const char *pc) const
{
    FILE *fd = fopen(pc, "w");

    if(!fd)
        return -1;

    m_ram.print();

    if(3==Global::P_Type)
        save_ppm_p3(fd);
    else
        save_ppm_p1(fd);

    fclose(fd);

    return 0;
}

int BildAria::save_ppm_p1(FILE *fd) const
{
    static const char *print_str[2][2] =
    {
        " 0",
        " 1",
        "\n0",
        "\n1"
    };
/*
    for(int i1 = 0 ; i1 < 2 ; ++i1)
        for(int i2 = 0 ; i2 < 2 ; ++i2)
            cout << "i1 = " << i1 << "  i2 = " << i2 << " -> \"" << print_str[i1][i2] << "\"\n";
*/

    fprintf(fd, "P1\n" \
           "# TEXT $Date: " __DATE__  "  " __TIME__ " $ \n" \
           "%u %u", m_ram.xend-m_ram.xstar, m_ram.yend-m_ram.ystar);  // s_x, s_y
    for(unsigned int iy=m_ram.ystar; iy < m_ram.yend ; ++iy)
    {
        for(unsigned int ix=m_ram.xstar ; ix < m_ram.xend ; ++ix)
            fprintf(fd, print_str[(ix == m_ram.xstar)][Get(ix,iy)]);
    }

    return 0;
}

int BildAria::save_ppm_p3(FILE *fd) const
{
/*
    ram tmp = GetRam();
    cout << "--- --- --- --- --- tmp --- \n";
    tmp.print();
*/
    fprintf(fd, "P3\n" \
           "# TEXT $Date: " __DATE__  "  " __TIME__ " $ \n" \
           "%u %u\n" \
           "255\n", m_ram.xend-m_ram.xstar, m_ram.yend-m_ram.ystar);  // s_x, s_y
    for(unsigned int iy=m_ram.ystar; iy < m_ram.yend ; ++iy)
    {
        for(unsigned int ix=m_ram.xstar ; ix < m_ram.xend ; ++ix)
        {
            if(ix != m_ram.xstar)
                fprintf(fd, " ");
            if(Get(ix,iy))
                fprintf(fd, "%d %d %d", rgb_r, rgb_g, rgb_b);
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
