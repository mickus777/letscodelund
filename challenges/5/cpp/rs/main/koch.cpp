#include <iostream>

#include "koch.h"

using namespace std;

koch::~koch()
{
    m_aria.save("koch.ppm");
}

void koch::make_str(int in)
{
    --in;
    if(in < 1)
        return;

    string from,to="F";

    for(int loop=0;loop<in;++loop)
    {
        from=move(to);
        to="";

        for(const auto &a : from)
        {
            if('F' == a)
                to+="F+F-F-F+F";
            else
                to+=a;
        }
//        cout << "To: " << to << "\n";
    }

    m_str=move(to);
}

int koch::rita()
{
    unsigned int nx = 4;
    unsigned int ny = BildAria::s_y - 120;
    int stepx = 1, stepy=0;

    cout << "STR: " << m_str << "\n";

    m_aria.Set(nx, ny);

    for(const auto &a : m_str)
    {
//        cout << "Now: " << a << "\n";

        switch (a)
        {
        case 'F':
            for(int i = 0 ; i < 3 ; ++i)
            {
                if(!BildAria::OkPoss(nx,ny))
                    cerr << "x: " << nx << "  y: " << ny << "\n";

                nx+=stepx;
                ny+=stepy;
                m_aria.Set(nx, ny);
            }
            break;

        case '-':
            if(0==stepx)
            {
                stepx = (stepy > 0) ? -1 : 1;
                stepy = 0;
            }
            else
            {
                stepy = (stepx > 0) ? 1 : -1;
                stepx = 0;
            }
            break;

        case '+':
            if(0==stepx)
            {
                stepx = (stepy > 0) ? 1 : -1;
                stepy = 0;
            }
            else
            {
                stepy = (stepx > 0) ? -1 : 1;
                stepx = 0;
            }
            break;

        default:
            cerr << "ERROR: Okänd: " << a << "\n";
            return -1;
            break;
        }
    }

    return 0;
}
