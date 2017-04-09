#include <iostream>

/*
 * Försök att skippa vissa recrusiva anrop genom
 * check_data_pint() och om de blir sämre, avsluta. Skapa andra fel.. :(
 */

using namespace std;

string the_input;

inline unsigned int check_data_pint(const string &data)
{
    unsigned int ratt=0;
    for(auto &a : data)
        if('+' == a)
            ++ratt;

    return ratt;
}

inline bool check_data(const string &data)
{
    for(auto &a : data)
        if('-' == a)
            return false;

    return true;
}

inline void flip(string &data, auto pos, auto pank_size)
{
//    cerr << "in: " << data << "\n";
    for(auto i=pos ; i<pos + pank_size ; ++i)
    {
        if('-' == data[i])
            data[i] = '+';
        else
            data[i] = '-';
    }
//    cerr << "ou: " << data << "\n";
}

int solve_rec(const string &data_in, auto pank_size , int deep)
{
    int myret=-1;
    if(deep<=0)
        return (check_data(data_in)) ? 0 : -1;

    auto in_pint = check_data_pint(data_in);
    unsigned int tot_pint=0;

//    cout << "deep: " << deep << "  data: " << data_in << "\n";

    for(unsigned int i=0; i <= data_in.size()-pank_size ; ++i)
    {
        string data(data_in);
        flip(data, i, pank_size);
        if(data == the_input)
        {
            continue;
//            return -1;
        }
/*
        if(data.size() != data_in.size())
        {
            cout << "dataOrg: " << data_in << "\n";
            cout << "data cp: " << data << "\n";
        }
//        cout << "i: " << i << "  deep: " << deep << "  data: " << data << "\n";
*/

        if(check_data(data))
            return 0;
/*        tot_pint += check_data_pint(data);
        if(i>2)
        {
            if(tot_pint/(i+1) < (in_pint-pank_size))
                return -2;
        }
*/
        auto ret = solve_rec(data,pank_size,deep-1);
        if(0 == ret)
            return ret;
        if(ret < -1)
            return ret+1;
    }

    return myret;
}

int solve(const string &data, unsigned int pank_size)
{
//    const auto loop_to = min(pank_size * 2 + 2, (unsigned int)16);
    const auto loop_to = 10;
//    cout << "To: " << loop_to << " Data: " << data << "\n";

    for(int i=0; i < loop_to ; ++i)
    {
        auto svar=solve_rec(data, pank_size, i);
        if(0 == svar)
            return i;
    }

    return -1;
}

//#define GUI_DEBUG

int main()
{
    int antal;
    unsigned int pank_size=0;
#ifdef GUI_DEBUG
    antal=1;
#else
    cin >> antal;
#endif

    for(int loop=1 ; loop <= antal ; ++loop)
    {
#ifdef GUI_DEBUG
        // Lång tid 10
        the_input="+-+-+-+-+-";
        pank_size=2;
        // 1 som blir fel :(
//        the_input="---+-++-";
//        pank_size=3;
#else
        cin >> the_input;
        cin >> pank_size;
#endif
/*
        vector<unsigned char> data;
        for(auto &d : in)
            data.push_back('+' == d);
*/

//        cout << loop << ") " << the_input << " <-> " << pank_size << "\n";

        if(29 == loop || 77 == loop)
        {
            auto svar = solve(the_input, pank_size);
            cout << "Case #" << loop << ": ";
            if(svar < 0)
                cout << "IMPOSSIBLE\n";
            else
                cout << svar << "\n";
        }
    }

    return 0;
}

