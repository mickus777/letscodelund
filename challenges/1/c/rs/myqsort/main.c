#include <stdio.h>
#include "help.h"

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
#endif

int data[]=
{
//    {7,2,1,6,8,5,3,4}
//    {6,5,1,3,8,4,7,9,2}
#include "data_50000.inc"
};

#ifdef MY_PRINT
void pi_print(int *pi, int size)
{
    int i;
    for(i=0;i<size;++i)
        printf("%d , ", pi[i]);
    printf("\n");
}
#endif

inline void pi_flip(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

inline int* myqflip(int *pstart, int *pend)
{
    int *piv = pend, *pindex = pstart;

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

static void myqsort_r(int *pstart, int *pend)
{
    int *pindex;
    if(pend <= pstart)
        return;

    pindex = myqflip(pstart, pend);

    myqsort_r(pstart, pindex-1);
    myqsort_r(pindex+1, pend);
}

static inline void myqsort(int *pi, size_t size)
{
    myqsort_r(pi, &pi[size-1]);
}

int main(void)
{
    unsigned int time, i;

    time = GetMilliSec();
#ifdef TEST_QSORT
    qsort(data,sizeof(data)/sizeof(data[0]),sizeof(data[0]), func_comp);
#else
    myqsort(data,sizeof(data)/sizeof(data[0]));
#endif
    time = GetMilliSec() - time;

    for(i=0;i < sizeof(data)/sizeof(data[0]);++i)
#ifdef MY_PRINT
        printf("%d) %d\n", i, data[i]);
#else
        printf("%d\n", data[i]);
#endif

    fprintf(stderr, "Time: %u\n", time);

    return 0;
}
