#include <iostream>
#include <iomanip>
#include <fstream>

#include "list.h"
#include "help.h"

using namespace std;


list::list(const char *name)
{
    if(name)
        load(name);
}


int list::load(const char *filnamn)
{
    int i,val;
    fstream file(filnamn);
    if(!file.is_open())
        error_end("Can't open file argv");

    for(i=0 ; !file.eof() ; ++i)
    {
        try
        {
            file >> val;
            if(!file.eof())
            {
//                cout << i << " ) " << filnamn << "  " << val << "\n";
                m_list.push_back(val);
            }
        }
        catch(const exception &e)
        {
            cout << i << " >>> " << val << "\n";
            break;
        }
    }

    return 0;
}
