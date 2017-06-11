#include "bruijn.h"

ostream& operator<< (ostream& os, Bruijn& obj)
{
    obj.db(1,1);

    if(0 == obj.alphabet.size())
    {
        for(const auto &a : obj.sequence)
            os << '0'+a;
    }
    else
    {
        for(const auto &a : obj.sequence)
            os << obj.alphabet[a];
    }

    return os;
}

void Bruijn::db(unsigned int t, unsigned int p)
{
    if(t>n)
    {
        if(0==(n%p))
        {
            for(unsigned int i=1;i<p+1;++i)
                sequence.push_back(a[i]);
        }
    }
    else
    {
        a[t] = a[t - p];
        db(t + 1, p);

        for(unsigned int j = a[t - p] + 1; j < k ; ++j)
        {
            a[t] = j;
            db(t + 1, t);
        }
    }
}
