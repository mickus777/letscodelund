#include <iostream>

#include "koch.h"

using namespace std;

koch::~koch()
{
    m_aria.save("koch.ppm");
}

void koch::make_str(int in)
{
    string from="",to="";

    for(int loop=0;loop<in;++loop)
    {
        from=move(to);
        if(0 == from.size())
            to="F";
        else
            to="";
//        for(unsigned int i=0 ; i < from.size() ; ++i)
        for(const auto &a : from)
        {
//            cout << i << ")  MakeNow: " << a << "\n";
            if('F' == a)
                to+="F+F-F-F+F";
            else
                to+=a;
        }
//        cout << "To: " << to << "\n";
    }

    m_str=to;
}

int koch::rita()
{
//    unsigned int nx = BildAria::s_x/2;
    unsigned int nx = 4;
    int stepx = 1, stepy=0;
    unsigned int ny = BildAria::s_y - 12;

    cout << "STR: " << m_str << "\n";

    for(const auto &a : m_str)
    {
//        cout << "Now: " << a << "\n";

        switch (a)
        {
        case 'F':
            for(int i = 0 ; i < 4 ; ++i)
            {
                if(!BildAria::OkPoss(nx,ny))
//                if((nx < 2) || (ny < 2) || (nx > (BildAria::s_x - 4)) || (ny > (BildAria::s_y - 4)))
                    cerr << "x: " << nx << "  y: " << ny << "\n";
                m_aria.Set(nx, ny);
                nx+=stepx;
                ny+=stepy;
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

//        cout << "a: " << a << "  stepx: " << stepx << "  stepy: " << stepy << "\n";
    }
    return 0;
}
