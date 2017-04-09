#include <iostream>

#include <math.h>

/*
 * Är ett försök att klara högre tal,
 * försöker öka stegningen beroende på hur långt från målet jag är.
 * Blev alldrig så bra :-/
 */

using namespace std;

uint64_t tal_in;

inline unsigned int count_tidy(auto in)
{
    string s = to_string(in);
    auto step = s[0];
//    unsigned int ret = 0;

    for(unsigned int i=1 ; i < s.size() ; ++i)
    {
        auto a=s[i];
        if(a<step)
        {
            return to_string(tal_in).size() - 1;
//            return to_string(tal_in).size() - (s.size() - i);
//            return (s.size())-i;
        }
        step = a;
    }

    return 0;
}

inline bool is_tidy(auto in)
{
    string s = to_string(in);
    auto step = s[0];
    for(auto &a : s)
    {
        if(a<step)
            return false;
        step = a;
    }
    return true;
}

auto solve(auto tal_in)
{
    auto svar = tal_in;
    svar=0;

    unsigned int mycount = 0;
    auto i = tal_in;
/*    if(tal_in > 1000000000)
    {
        i=tal_in - (tal_in / 1000000);
    }
    else if(tal_in > 10000000)
    {
        i=tal_in - (tal_in / 10000);
    }
    else if(tal_in > 100000)
    {
        i=tal_in - (tal_in / 100);
    }
    else*/
        i=1;

    for(;i <= tal_in ; ++i, ++mycount)
    {
/*
        cout << i << " = " << log10((double)i) << "\n";
        cout << i << " = " << logb((double)i) << "\n";
        cout << i << " = " << exp10((double)i) << "\n";
        cout << i << " = " << exp2((double)i) << "\n";
        cout << i << " = " << ldexp(10,i) << "\n";
        cout << "- - - - - - - - - - - - - - - - - - - - - -\n";
*/

//        if(is_tidy(i))
        auto step_kvar=count_tidy(i);
        if(0 == step_kvar)
            svar=i;
        else
        {
            i+=(10^step_kvar)-2; // -1 men -2 pga ++i..?
            if((mycount & 0xfffff) == 0xfffff)
                cout << i << "  Svar: " << svar << "\n";
        }
    }

    return svar;
}

#define GUI_DEBUG

int main()
{
    int antal;
//    unsigned int pank_size=0;
#ifdef GUI_DEBUG
    antal=1;
#else
    cin >> antal;
#endif

    for(int loop=1 ; loop <= antal ; ++loop)
    {
#ifdef GUI_DEBUG
//        tal_in = 111111111111111110;
        tal_in = 1000;
#else
        cin >> tal_in;
#endif
/*
        vector<unsigned char> data;
        for(auto &d : in)
            data.push_back('+' == d);
*/

//        cout << loop << ") " << the_input << " <-> " << pank_size << "\n";

        {
            const auto svar = solve(tal_in);
            cout << "Case #" << loop << ": " << svar << "\n";
        }
    }

    return 0;
}
