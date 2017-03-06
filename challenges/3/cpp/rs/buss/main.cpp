/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <rickard@letscodelund> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Rickard S
 * ----------------------------------------------------------------------------
 */
#include <iostream>
#include <iomanip>

#include "help.h"
#include "group.h"

using namespace std;

int s_buss_size=0, s_total=0;

void load(const char *fil_name)
{
    fstream file(fil_name);
    if(!file.is_open())
        error_end("Can't open file argv");

    file >> s_total;
    file >> s_buss_size;

    cout << "Ant: " << s_total << "  Buss: " << s_buss_size << "\n";

    for(int i=1;!file.eof() && i <= s_total ; ++i)
    {
        person per;
        file >> per.point;
        per.num = i;
//        per.print();
        if(per.point)
            g_handelGroups.add(per);
    }

//    cout << "s_total: " << s_total << "  all.size: " << g_handelGroups.m_all.size() << "\n";
    if(s_total != g_handelGroups.m_ant)
        error_end("read ant != s_total");
}

int match_buss(auto pos, auto end)
{
    int total=0, best = -1;

    for(; pos != end ; ++pos)
    {
        total += *pos;
        if(total > s_buss_size)
            break;
        best = total;
//        cout << "best: " << best << "  total: " << total << "\n";
    }

    return best;
}

int totola_list_sum(const vector <int> &list)
{
    int sum=0;
    for(const auto &s : list)
        sum += s;
    return sum;
}

int main(int argc, char *argv[])
{
#ifndef SKRIPT_RUN
    ++argc;
#endif
    if(argc <= 1)
        error_end("No argv");

#ifndef SKRIPT_RUN
    argv[1]="1000_666_one_big_string.txt";
#endif

    load(argv[1]);

    vector <int> list = g_handelGroups.getList();

    if(s_total != totola_list_sum(list))
        error_end("if(all.size() != mtotal)");

    int best=0;
    for(auto start = list.begin() ; start != list.end() ; ++start)
    {
        auto tmatch = match_buss(start, list.end());
        if(tmatch > best)
            best = tmatch;

        if(best == s_buss_size)
            break;
    }

    if(best == s_buss_size)
        cout << "Bussen gick att fylla till max: " << best << "\n";
    else
        cout << "Bäst fylnadsgrad blev: " << best << "\n";

    return 0;
}

