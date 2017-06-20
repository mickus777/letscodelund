#ifndef BRUIJN_H
#define BRUIJN_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Bruijn
{
    unsigned int n, k;
    string alphabet;
    vector<unsigned int> a;
    list<unsigned int> sequence;

protected:
    void db(unsigned int t, unsigned int p);
public:
    Bruijn() = delete;
    Bruijn(const string &ins, unsigned int inn)
        : n(inn)
        , k(ins.size())
        , alphabet(ins)
        , a(k*n)
    {}

    Bruijn(unsigned int inar, unsigned int inn)
        : n(inn)
        , k(inar > 10 ? 10 : inar)
        , a(k*n)
    {
    }

    friend std::ostream& operator<<(std::ostream&, Bruijn&);
};

#endif // BRUIJN_H
