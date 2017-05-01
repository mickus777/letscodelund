#include <iomanip>
#include <fstream>
#include <locale>         // std::locale, std::tolower
#include <string.h>
#include <stdlib.h>  // rand
#include <time.h>    // time

#include "ord.h"

using namespace std;

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
    for(auto &a : m_list)
    {
        if(a.m_name == old)
        {
            a.m_list.push_back(now);
            return;
        }
    }

//    WordList w(old, now);
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
    std::locale loc;

    int dot=0;
    for(int x=0 ; x<str.length() ;)
    {
        str[x] = tolower(str[x],loc);

        if('.' == str[x])
            ++dot;
//        if(!kasta_char(a))
//            str[i++] = a; erase
        if(kasta_char(str[x]))
            str.erase(x,1);
        else
            ++x;
    }
//    str[i]='\0';
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

/*        try
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
*/
    }

    return 0;
}

string ord::getAWord(const string &sin)
{
    for(auto &a : m_list)
    {
        if(sin != a.m_name)
            continue;
//        auto &s = a.m_list[rand() % a.m_list.size()];
//        cout << "\n" << sin << " ->  %" << a.m_list.size() << " = " << s << "\n";
//        return s;
        return a.m_list[rand() % a.m_list.size()];
    }
    return sin;
}

void ord::write()
{
    string s=".";
    srand(time(0));

    for(int i=0;i<80;++i)
    {
        s=getAWord(s);
        cout << s << " ";
    }
    cout << "\n";
}
