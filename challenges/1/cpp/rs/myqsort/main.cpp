#include <iostream>

using namespace std;

#include "system.h"

//define MY_PRINT
//#define TEST_QSORT

#ifdef TEST_QSORT
#include <stdlib.h>

static int func_comp(const void *p1, const void *p2)
{
    if(*(const int*)p1 < *(const int*)p2)
        return -1;
    if(*(const int*)p1 > *(const int*)p2)
        return 1;
    return 0;
}

int

#else

int64_t

#endif

 data[]=
{
//    {7,2,1,6,8,5,3,4}
//    {6,5,1,3,8,4,7,9,2}
#include "data_50000.inc"
};

template<class T>
inline void pi_flip(T *p1, T *p2)
{
    T tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

template<class T>
inline T* myqflip(T *pstart, T *pend)
{
    T *piv = pend, *pindex = pstart;

    for(; pstart <= pend ; ++pstart)
    {
        if(*pstart <= *piv)
        {
            pi_flip(pstart,pindex);
            if(pstart != pend)
                ++pindex;
        }
    }
    return pindex;
}

template<class T>
static void myqsort_r(T *pstart, T *pend)
{
    if(pend <= pstart)
        return;

    T *pindex = myqflip(pstart, pend);

    myqsort_r(pstart, pindex-1);
    myqsort_r(pindex+1, pend);
}

template<class T>
static inline void myqsort(T *pi, size_t size)
{
    myqsort_r(pi, &pi[size-1]);
}

int main()
{
    unsigned int i;

    {
        DurationTimer tid("Qsort");
#ifdef TEST_QSORT
        qsort(data, ARRAY_SIZE(data), sizeof(data[0]), func_comp);
#else
        myqsort(data, ARRAY_SIZE(data));
#endif
    }

    for(i=0 ; i < ARRAY_SIZE(data) ; ++i)
    {
#ifdef MY_PRINT
        cout << i << ") " << data[i] << "\n";
#else
        cout << data[i] << "\n";
#endif
    }

    return 0;
}
