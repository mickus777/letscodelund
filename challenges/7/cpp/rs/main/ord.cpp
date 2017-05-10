#include <iomanip>
#include <fstream>
#include <locale>         // std::locale, std::tolower
#include <string.h>
#include <stdlib.h>  // rand
#include <time.h>    // time

#include "ord.h"

using namespace std;

std::locale loc;

/*
void WordList::add(const std::string &s)
{
    for(auto &a : m_list)
    {
        if(a.m_str == s)
        {
            ++a.m_num;
            return;
        }
    }

    StringNum ny(s);
    m_list.push_back(ny);
}
*/


ord::~ord()
{
    /*
    for(auto &a1 : m_list)
    {
        cout << a1.m_name << " -> ";
        for(auto &a2 : a1.m_list)
        {
            cout << a2 << " -> ";
        }
        cout << "||\n";
    }
    */
}

void ord::AddWord(const std::string &old, const std::string &now)
{
    if(old.empty() || now.empty())
        return;

    for(auto &a : m_list)
    {
        if(a.m_name == old)
        {
            a.m_list.push_back(now);
            return;
        }
    }

    m_list.push_back(WordList(old, now));
}

inline int kasta_char(char c)
{
    static const char *ok="abcdefghijklmnopqrstuvwxyzåäö";

    return (strchr(ok,c) == nullptr);
}

/*
static int fix_str2(string &str)
{
    std::locale loc;

    int ret=0;
    for(int x=0 ; x<str.length() ;)
    {
        str[x] = tolower(str[x],loc);

        if('.' == str[x])
            ret=1;
//        if(!kasta_char(a))
//            str[i++] = a; erase
        if(kasta_char(str[x]))
            str.erase(x,1);
        else
            ++x;
    }
//    str[i]='\0';

    return ret;
}
*/

static vector<string> fix_str(string &str)
{
    unsigned int dot=0,x=0;

    while(x<str.length())
    {
        str[x] = tolower(str[x],loc);

        if('.' == str[x])
            ++dot;
        if(kasta_char(str[x]))
            str.erase(x,1);
        else
            ++x;
    }

    vector<string> v;
    if(!str.empty())
        v.push_back(str);
    if(dot)
        v.push_back(".");

    return v;
}

int ord::load(const char *filnamn)
{
    string ReadOrd, old=".";
    fstream file(filnamn);
    if(!file.is_open())
        return -1;

    for(int i=0 ; !file.eof() ; ++i)
    {
        file >> ReadOrd;

        vector<string> FixOrden = fix_str(ReadOrd);

        for(auto &FixOrd : FixOrden)
        {
//          cout << i << ") " << ny << "\n";

            AddWord(old, FixOrd);

            old=move(FixOrd);
        }
    }

    return 0;
}

string ord::getAWord(const string &sin)
{
    for(auto &a : m_list)
    {
        if(sin == a.m_name)
            return a.m_list[rand() % a.m_list.size()];
    }
    return sin;
}

void ord::out(const string &sthis, const string &last)
{
    string nu(sthis);

    if("." == last)
        nu[0] = toupper(nu[0],loc);
    else if("." != nu)
        cout << " ";

    cout << nu;

    if("." == nu)
        cout << "\n";
}

#define ANT_ORD 100

void ord::write()
{
    string sthis=".", last=".";
    srand(time(0));

    for(int i=0;i < ANT_ORD * 2 ;++i)
    {
        sthis = getAWord(last);

        out(sthis, last);

        if(i >= ANT_ORD && "." == sthis)
            break;

        last = move(sthis);
    }
    cout << "\n";
}
