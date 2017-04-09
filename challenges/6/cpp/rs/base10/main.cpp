#include <iostream>

#include <math.h>

using namespace std;

uint64_t tal_in;

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

    auto i = tal_in;

    for(i=1 ; i <= tal_in ; ++i)
    {
        if(is_tidy(i))
            svar=i;
    }

    return svar;
}

//#define GUI_DEBUG

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
