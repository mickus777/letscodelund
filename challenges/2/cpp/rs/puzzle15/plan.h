#ifndef PLAN_H
#define PLAN_H

#include <string.h>

#define FOUND 0
#define NOT_FOUND 0x7fffffff

enum emove
{
    e_error = -1,
    e_upp = 0,
    e_ner,
    e_hog,
    e_ven,
    e_end
};


struct XY
{
    inline XY(int iny = -1, int inx = -1)
        : x(inx)
        , y(iny)
    {}

    inline bool ok() const
    {
        return (x >= 0 && y >= 0);
    }

    short x;
    short y;
};

class plan
{
public:
    static const int s_x = 4;
    static const int s_y = 4;
    static const int s_ant = s_x * s_y;

private:
    int m_puzz[s_y][s_x];
    XY m_emty;

public:

    inline plan()
        : m_puzz { 0 }
    {
    }

    explicit inline plan(const char *p)
        : plan()
    {
        load(p);
    }

    void load(const char *);

    XY findEmty() const;
    XY okmove(enum emove m) const;
    int move(emove m);
    static inline int okpos(int x, int y)
    {
        if(x<0 || x>=s_x || y<0 || y>=s_y)
            return 0;
        return 1;
    }

    static inline enum emove ReverseMove(enum emove m)
    {
        switch (m)
        {
        case e_upp:
            return e_ner;

        case e_ner:
            return e_upp;

        case e_ven:
            return e_hog;

        case e_hog:
            return e_ven;

        default:
            return e_error;
        }
    }


    void print_bug() const;
    void print_box(int step = -1) const;

    inline bool Correct() const
    {
        int *puzz = (int *) m_puzz;
        for(int i=0 ; i < (s_ant - 1) ; ++i)
            if(puzz[i] != (i+1))
                return false;
        return true;
    }

    int Point() const;
};

#endif // PLAN_H
