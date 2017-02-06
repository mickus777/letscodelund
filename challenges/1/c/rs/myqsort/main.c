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

inline int myqflip(int *pi, int start, int end)
{   // 7,2,1,6,8,5,3,4
    int i, piv = pi[end], index=start;
#ifdef MY_PRINT
    printf("%d) start: %d end: %d piv: %d\n", __LINE__, start, end, piv);
    pi_print(pi, 8);
#endif

    for(i=start;i <= end;++i)
    {
        if(pi[i] <= piv)
        {
#ifdef MY_PRINT
            printf("%d) Index: %d pi[%d]=%d FLIP  pi[%d]=%d\n", __LINE__, index, i, pi[i], index, pi[index]);
#endif
            pi_flip(&pi[i],&pi[index]);
#ifdef MY_PRINT
            printf("%d) Index: %d pi[%d]=%d FLIP  pi[%d]=%d\n", __LINE__, index, i, pi[i], index, pi[index]);
#endif
            if(i!=end)
                ++index;
        }
    }
    return index;
}

static void myqsort_r(int *pi, int start, int end)
{
//    static int loop=1;
    int index;
    if(end<=start)
    {
#ifdef MY_PRINT
        printf("%d) %d - %d  -> END\n", __LINE__, start, end);
#endif
        return;
    }
#ifdef MY_PRINT
    else
        printf("%d) %d - %d\n", __LINE__, start, end);
#endif
//    if(++loop > 216)
//        return;
    index = myqflip(pi, start, end);
#ifdef MY_PRINT
    printf("%d) start: %d  end: %d index: %d\n", __LINE__, start, end, index);
#endif
    myqsort_r(pi, start, index-1);
    myqsort_r(pi, index+1, end);
}

static inline void myqsort(int *pi, size_t size)
{
    myqsort_r(pi, 0, size-1);
}

int main(void)
{
    unsigned int time, i;
/*
    int data[]=
    {7,2,1,6,8,5,3,4}
//    {6,5,1,3,8,4,7,9,2}
    ;
*/

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

