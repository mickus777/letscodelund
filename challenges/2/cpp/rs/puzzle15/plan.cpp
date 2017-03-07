#include <iostream>
#include <iomanip>

#include "help.h"
#include "plan.h"

using namespace std;

void plan::load(const char *fil_name)
{
    string val;
    int *puzz=(int *) m_puzz;

    fstream file(fil_name);
    if(!file.is_open())
        error_end("Can't open file argv");

    for(int i=0;!file.eof() && i < (s_x * s_y) ; ++i)
    {
        file >> val;
//        cout << i << " ) " << val << "\n";
        try {
            *puzz++ = stoi(val);
        } catch(const exception &e)
        {
//            cout << i << " >>> " << val << "\n";
        }
    }
    m_emty = findEmty();
}

XY plan::findEmty() const
{
    int y,x;
    for(y=0;y<s_y;++y)
    {
        for(x=0;x<s_x;++x)
        {
            if(0 == m_puzz[y][x])
                return XY(y, x);
        }
    }

    return XY();
}

XY plan::okmove(enum emove m) const
{
    XY xy = m_emty;

    if(!xy.ok())
        return xy;

    switch (m)
    {
    case e_upp:
        --xy.y;
        break;

    case e_ner:
        ++xy.y;
        break;

    case e_ven:
        --xy.x;
        break;

    case e_hog:
        ++xy.x;
        break;

    default:
        break;
    }

    if(!okpos(xy.x, xy.y))
        return XY();

    return xy;
}

int plan::move(enum emove m)
{
    XY xyNy = okmove(m);

    if(!xyNy.ok())
        return -1;

    m_puzz[m_emty.y][m_emty.x] = m_puzz[xyNy.y][xyNy.x];
    m_puzz[xyNy.y][xyNy.x] = 0;
    m_emty = xyNy;

    return 0;
}

static inline int diff_int(int i1, int i2)
{
    if(i1>i2)
        return i1-i2;
    return i2-i1;
}

int plan::Point() const
{
    static const struct XY xy_diff[plan::s_y * plan::s_x] =
    {
        XY(0,0) ,
        XY(0,1) ,
        XY(0,2) ,
        XY(0,3) ,

        XY(1,0) ,
        XY(1,1) ,
        XY(1,2) ,
        XY(1,3) ,

        XY(2,0) ,
        XY(2,1) ,
        XY(2,2) ,
        XY(2,3) ,

        XY(3,0) ,
        XY(3,1) ,
        XY(3,2) ,
        XY(3,3)
    };
    int sum=0, tal, x;

    for(int y=0 ; y < plan::s_y ; ++y)
    {
        for(x=0 ; x < plan::s_x ; ++x)
        {
            tal = m_puzz[y][x] - 1;
            if(tal < 0) // Tom pos är 0 & blir därmed -1
                continue;
            sum += diff_int(xy_diff[tal].y, y) + diff_int(xy_diff[tal].x, x);
        }
    }

    return sum;
}

void plan::print_bug() const
{
    int y,x;

    for(y=0;y<s_y;++y)
    {
        for(x=0;x<s_x;++x)
        {
            cout << "y = " << y << "  x = " << x << " = " << m_puzz[y][x] << "\n";
        }
    }
}

void plan::print_box(int step) const
{
    int y,x;

    if(step >= 0)
        cout << "Step: " << step << "\n";
    for(y=0;y<s_y;++y)
    {
        for(x=0;x<s_x;++x)
        {
            cout << " " << setw(2) << m_puzz[y][x];
        }
        cout << "\n";
    }
    cout << "\n--------------\n\n";
}
