/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <rickard@letscodelund> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Rickard S
 * ----------------------------------------------------------------------------
 */
#include <iostream>
#include <algorithm>    // För std::sort

#include "group.h"

using namespace std;

void person::print()
{
    cout << "num: " << num << "  point: " << point << "\n";
}

group::group(const person &p)
{
    m_all.push_back(p);
}

handelGroups::~handelGroups()
{
#ifdef PRINT_GROUP_SETUP
    int ng=0, total=0;
    for(auto &g : m_all)
    {
        int np=0;
        total += g.m_all.size();
        cout << "--------------------\nnum: " << ng << " Size: " << g.m_all.size() << "\n";
        for(auto &p : g.m_all)
        {
            cout << ng << " - " << np << " PerNum: " << p.num << "  PerPoint: " << p.point << "\n";
            ++np;
        }
        ++ng;
    }
    cout << "Total: " << total << "\n";
#endif
}

int handelGroups::find(const person &per)
{
    int gnum=0;
    for(auto &g : m_all)
    {
        for(auto &p : g.m_all)
        {
            if(p.num == per.num)
                return gnum;
        }
        ++gnum;
    }

    return -1;
}

void handelGroups::rm(const person &per)
{
    for(auto &g : m_all)
    {
        for(auto p = g.m_all.begin() ; p != g.m_all.end() ;)
        {
            if(*p == per)
                g.m_all.erase(p);
            else
                ++p;
        }
    }
}

int handelGroups::addExist(const person &per)
{
    int add=0;

    for(auto &g : m_all)
    {
        for(auto &p : g.m_all)
        {
            if(p.num == per.num || p.point == per.num || p.num == per.point)
            {
                add=1;
                g.m_all.push_back(per);
                break;
            }
            else
                p.num = p.num;
        }
        if(add)
            break;
    }

    return add;
}

void handelGroups::add(const person &per)
{
    ++m_ant;
    if(addExist(per))
       return;
    m_all.push_back(per);
}

bool mysort(int i1, int i2)
{
    return i1 > i2;
}

vector <int> handelGroups::getList()
{
    vector <int> list(m_all.size());

    for(unsigned int i=0 ; i < m_all.size() ; ++i)
        list[i] = m_all[i].m_all.size();

    // Där är en reverse() med som bara ska göra en sort åt andra hållet. Men fungera inte..?
    sort(list.begin(), list.end(), mysort);

    return list;
}

handelGroups g_handelGroups;
