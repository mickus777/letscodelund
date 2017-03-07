#include <iostream>
#include <iomanip>

#include "help.h"
#include "plan.h"
#include "system.h"

using namespace std;

//#define SEARCH_COUNT
//#define TABLE_PRINT

#ifdef SEARCH_COUNT
uint64_t search_count = 0;
#endif

/*
 *  https://en.wikipedia.org/wiki/Iterative_deepening_A*
 *

 node              current node
 g                 the cost to reach current node
 f                 estimated cost of the cheapest path (root..node..goal)
 h(node)           estimated cost of the cheapest path (node..goal)
-> 1 stega kvar att gå + 2 stget...
 cost(node, succ)  step cost function
-> i detta fall alltid 1
 is_goal(node)     goal test
 successors(node)  node expanding function, expand nodes ordered by g + h(node)
-> Möjliga vägar att gå

 procedure ida_star(root)
   bound := h(root)
   loop
     t := search(root, 0, bound)
     if t = FOUND then return bound
     if t = ∞ then return NOT_FOUND
     bound := t
   end loop
 end procedure

 function search(node, g, bound)
   f := g + h(node) // ** bättre / sämre
   if f > bound then return f
   if is_goal(node) then return FOUND
   min := ∞
   for succ in successors(node) do
     t := search(succ, g + cost(node, succ), bound)
     if t = FOUND then return FOUND
     if t < min then min := t
   end for
   return min
 end function
*/

static inline int search(plan node, int g, int bound, int last_pos = e_error)
{
    auto f = g + node.Point();

#ifdef SEARCH_COUNT
    ++search_count;
#endif

    if (f > bound)
        return f;
    else if (f == g && node.Correct())
        return FOUND;

    plan tmp;
    auto min = NOT_FOUND;
    for(int i=e_upp ; i < e_end ; ++i)
    {
        if(last_pos == i)
            continue;

        tmp = node;
        if(0 == tmp.move((enum emove)i))
        {
            auto t = search(tmp, g + 1, bound, plan::ReverseMove((enum emove)i));
            if(FOUND == t)
                return FOUND;
            if (t < min)
                min = t;
        }
    }
    return min;
}

static inline int ida_star(plan root)
{
    auto bound = root.Point();
    while(true)
    {
        auto t = search(root, 0, bound);
//        cout << "t = " << t << "\n";
        if (t == FOUND)
            return bound;
        else if (t == NOT_FOUND)
            return NOT_FOUND;
        bound = t;
    }
}

int main(int argc, char *argv[])
{
#ifndef SKRIPT_RUN
    ++argc;
#endif
    if(argc <= 1)
        error_end("No argv");

#ifndef SKRIPT_RUN
    argv[1]="47.txt";
#endif

    plan s(argv[1]);
//    s.print_bug();

//    cout << "| File (moves) | States searched | Time (ms) | States/sec  |\n";
#ifdef TABLE_PRINT
    auto time_first = GetMilliSec();
#endif
    int ret;
    {
#ifndef SEARCH_COUNT
        DurationTimer time("IDA*");
#endif
        ret = ida_star(s);
    }
#ifdef TABLE_PRINT
    auto time_end = GetMilliSec();

    const auto search_count1000 = search_count * 1000;
    const auto time = (time_end - time_first);

    cout << "| " << argv[1] << "       | " << setw(13) << search_count << " | " << setw(9) << time << " | " << setw(9) << search_count1000 / time << " | \n";
#else
#ifdef SEARCH_COUNT
    cout << "Search count: " << search_count << "\n";
#endif
    cout << "Antal steg: " << ret << "\n";
#endif

    return 0;
}
