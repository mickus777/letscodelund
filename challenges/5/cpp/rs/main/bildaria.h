#ifndef BILDARIA_H
#define BILDARIA_H

#include <bitset>


#define USE_NEW

extern int rgb_r;
extern int rgb_g;
extern int rgb_b;

//struct ram;

struct ram
{
    unsigned int ystar = 0;
    unsigned int yend = 0;

    unsigned int xstar = 0;
    unsigned int xend = 0;
    void print() const;
};


class BildAria
{
    ram GetRam() const;
    bool TomX(unsigned int iny) const;
    bool TomY(unsigned int inx) const;
public:
    BildAria();
    ~BildAria();

    static const unsigned int s_x = 90000, s_y = 34000;

    static inline auto OkPoss(auto nx, auto ny)
    {
        if((nx < 2) || (ny < 2) || (nx > (BildAria::s_x - 2)) || (ny > (BildAria::s_y - 2)))
            return false;
        return true;
    }

    int save(const char *pc) const;

    inline void ResetRam(u_int32_t x, u_int32_t y)
    {
        FirstWrite = false;
        m_ram.xstar = m_ram.xend = x;
        m_ram.ystar = m_ram.yend = y;
    }

    /// Hitta ytter kanter
    inline void SetRam(u_int32_t x, u_int32_t y)
    {
        if(m_ram.xstar > x)
            m_ram.xstar = x;
        else if(m_ram.xend <= x)
            m_ram.xend = x+1;

        if(m_ram.ystar > y)
            m_ram.ystar = y;
        else if(m_ram.yend <= y)
            m_ram.yend = y+1;
    }

    inline void Set(u_int32_t x, u_int32_t y)
    {
        if(FirstWrite)
            ResetRam(x,y);

        SetRam(x,y);

        m_data[(y * s_x)+x] = 1;
    }

    inline auto Get(auto x, auto y) const
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

    ram m_ram;
    bool FirstWrite = true;
};

#endif // BILDARIA_H
