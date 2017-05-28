#include <iostream>
#include <bitset>

using namespace std;

#define BIT_LEN 10


template<typename T>
T myplus(T t1, T t2)
{
    T myand(t1 & t2);

    do
    {
        myand <<=1;

        t2 = t1 ^ t2;

        t1=myand;

        myand = t1 & t2;
//        cout << "t1: " << t1 << "  t2: " << t2 << "\n";
    }
    while(!myand.none());

    return (t1 | t2);
}

template<typename T>
T myminus(T t1, T t2)
{
    do
    {
//        cout << __LINE__ << ") t1: " << t1 << "  t2: " << t2 << "\n";

        t1 = t1 ^ t2;
        t2 = t1 & t2;
        t2 <<=1;

//        cout << __LINE__ << ") t1: " << t1 << "  t2: " << t2 << "\n";
    }
    while(!T(t2).none());

    return t1;
}



int main()
{
    srand(time(0));
    static const int loop_to = 50000;

    for(int i=0 ; i < loop_to ; ++i)
    {
        //    int it1=9, it2=3;
        //    int it1=15, it2=8;
        //    int it1=27, it2=13;
        int it1=rand(), it2=rand();

        bitset<BIT_LEN> t1(it1);
        bitset<BIT_LEN> t2(it2);

        {
            auto mytal = myplus(t1, t2);
            bitset<BIT_LEN> ratt_tal(it1 + it2);
            if(mytal != ratt_tal)
                cout << "Fel + Ska vara: " << ratt_tal << "  mytal: " << mytal << "\n";
            if(false && (loop_to % (loop_to/10)) == 0)
                cout << i << ") " << it1 << " + " << it2 << " = " << it1 - it2 << "  t1: " << t1 << "  t2: " << t2 << "\n";
        }


        {
            auto mytal = myminus(t1, t2);
            bitset<BIT_LEN> ratt_tal(it1 - it2);
            if(mytal != ratt_tal)
                cout << "Fel - Ska vara: " << ratt_tal << "  mytal: " << mytal << "\n";
            if(false && (loop_to % (loop_to/10)) == 0)
                cout << i << ") " << it1 << " - " << it2 << " = " << it1 - it2 << "  t1: " << t1 << "  t2: " << t2 << "\n";
//            cout << myminus(t1, t2) << "\n";
//            cout << bitset<BIT_LEN>(it1-it2) << "\t  RÄTT -\n";
        }

    }

    return 0;
}
