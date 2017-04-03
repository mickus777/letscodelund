#ifndef BILDARIA_H
#define BILDARIA_H

#include <bitset>


#define USE_NEW

extern int rgb_r;
extern int rgb_g;
extern int rgb_b;

struct ram;


class BildAria
{
    ram GetRam() const;
    bool TomX(unsigned int iny) const;
    bool TomY(unsigned int inx) const;
public:
    BildAria();
    ~BildAria();

//    static const unsigned int s_x = 92000, s_y = 72000;  // För stor
    static const unsigned int s_x = 90000, s_y = 24000;
//    static const unsigned int s_x = 44000, s_y = 44000;
//    static const unsigned int s_x = 3800, s_y = 2000;
//    static const unsigned int s_x = 4000, s_y = 1200;

    static auto OkPoss(auto nx, auto ny)
    {
        if((nx < 2) || (ny < 2) || (nx > (BildAria::s_x - 4)) || (ny > (BildAria::s_y - 4)))
            return false;
        return true;
    }

    int save(const char *pc) const;

    inline void Set(auto x, auto y)
    {
        m_data[(y * s_x)+x] = 1;
    }

    auto Get(auto x, auto y) const
    {
       return m_data[(y * s_x)+x];
    }

    int save_ppm_p1(FILE *) const;
    int save_ppm_p3(FILE *) const;

#ifdef USE_NEW
    unsigned char *m_data = 0;
#else
    std::bitset<s_x * s_y> m_data;
#endif

};

struct ram
{
    unsigned int ystar = 0;
    unsigned int yend = BildAria::s_y;

    unsigned int xstar = 0;
    unsigned int xend = BildAria::s_x;
    void print() const;
};

#endif // BILDARIA_H
