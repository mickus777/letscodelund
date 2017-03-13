#include <iostream>
#include <limits>
#include <map>

#include <stdlib.h>

#include "list.h"
#include "help.h"
#include "system.h"

using namespace std;

auto d(auto a, auto b)
{
    if(a>b)
        return a-b;
    return b-a;
}

auto minimum(auto a, auto b, auto c)
{
    return min(a, min(b,c));
}

struct myarry
{
    myarry(int y, int x)
        : m_y(y)
    {
        m_ary = new int*[y];
        for(int i=0 ; i < m_y ; ++i)
            m_ary[i] = new int[x];
    }

    ~myarry()
    {
        for(int i=0 ; i < m_y ; ++i)
            delete m_ary[i];
        delete m_ary;
    }

    int** m_ary = nullptr;
    int m_y;

    myarry& operator=(const myarry&) = delete;
    myarry(const myarry&) = delete;
    myarry() = delete;
};

/*
int DTWDistance(s: array [1..n], t: array [1..m]) {
    DTW := array [0..n, 0..m]
    for i := 1 to n
    DTW[i, 0] := infinity
    for i := 1 to m
    DTW[0, i] := infinity
    DTW[0, 0] := 0
    for i := 1 to n
      for j := 1 to m
        cost := d(s[i], t[j])
        DTW[i, j] := cost + minimum(DTW[i-1, j ],
              DTW[i , j-1],
              DTW[i-1, j-1])
    return DTW[n, m]
}
 */

int DTWDistance(list &s, list &t)
{
    static unsigned int n=s.m_list.size();
    static unsigned int m=t.m_list.size();

//    vector<vector<int>> DTW(n);
//    multimap<int, int> DTW(n,m);
//    DTW = new[n * m];
    myarry DTW(n+1, m+1);
//    int &DTW[n][m] = ;

//    DTW := array [0..n, 0..m];
    for (unsigned int i = 1 ; i <= n ; ++i)
        DTW.m_ary[i][0] = numeric_limits<int>::max();
    for (unsigned int i = 1 ; i <= m ; ++i)
        DTW.m_ary[0][i] = numeric_limits<int>::max();
    DTW.m_ary[0][0] = 0;

    for(unsigned int i = 1 ; i <= n ; ++i)
    {
        for(unsigned int j = 1 ; j <= m ; ++j)
        {
            const auto cost = d(s.m_list[i], t.m_list[j]);

            DTW.m_ary[i][j] = cost + minimum(DTW.m_ary[i-1][j], // insertion
                    DTW.m_ary[i][j-1],                          // deletion
                    DTW.m_ary[i-1][j-1]);                       // match
        }
    }

    return DTW.m_ary[n][m];
}

int DTWDistance(list &s, list &t, int w)
{
    static int n=s.m_list.size();
    static int m=t.m_list.size();

    w = max(w, abs(n-m)); // adapt window size (*)

    myarry DTW(n+1, m+1);

    for(int i = 0 ; i <= n ; ++i)
        for(int j = 0 ; j <= m ; ++j)
            DTW.m_ary[i][j] = numeric_limits<int>::max();
    DTW.m_ary[0][0] = 0;

    for(int i = 1 ; i <= n ; ++i)
    {
//        for(unsigned int j = 1 ; j <= m ; ++j)
        for(int j = max(1, i-w) ; j <= min(m, i+w) ; ++j)
        {
            const auto cost = d(s.m_list[i], t.m_list[j]);

            DTW.m_ary[i][j] = cost + minimum(DTW.m_ary[i-1][j], // insertion
                    DTW.m_ary[i][j-1],                          // deletion
                    DTW.m_ary[i-1][j-1]);                       // match
        }
    }

    return DTW.m_ary[n][m];
}


int main(int argc, char *argv[])
{
#ifndef SKRIPT_RUN
    argc += 2;
#endif
    if(argc <= 2)
        error_end("No argv");

#ifndef SKRIPT_RUN
    argv[1]="sample_1.txt";
    argv[2]="sample_5.txt";
#endif

    list l1(argv[1]);
    list l2(argv[2]);

    int dtw1, dtw2;

    {
//        DURATION_TIMER;
        dtw1 = DTWDistance(l1, l2);
    }

    {
//        DURATION_TIMER;
        dtw2 = DTWDistance(l1, l2, 0);
    }

    cout << "dtw1: " << dtw1 << "   dtw2: " << dtw2 << "\n";

    return 0;
}
