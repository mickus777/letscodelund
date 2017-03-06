/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <rickard@letscodelund> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Rickard S
 * ----------------------------------------------------------------------------
 */
#ifndef GROUP_H
#define GROUP_H

#include <vector>

//#define PRINT_GROUP_SETUP

using namespace std;

struct person
{
    person()
        : num(0)
        , point(0)
    { }
    int num;
    int point;

    bool operator ==(const person &in)
    {
        return (num == in.num && point == in.point);
    }
    void print();
};

class group
{
public:
    group() = default;
    group(const person &);

    vector <person>m_all;
};

class handelGroups
{
    int addExist(const person &per);

public:
    ~handelGroups();

    void add(const person &);
    void rm(const person &per);

    int find(const person &per);

    vector <int> getList();

    vector <group>m_all;
    int m_ant = 0;
};

extern handelGroups g_handelGroups;

#endif // GROUP_H
