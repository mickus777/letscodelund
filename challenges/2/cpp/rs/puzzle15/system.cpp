#include <iostream>

#include "system.h"

using namespace std;

void DurationTimer::Print(std::chrono::duration<double, std::milli> elapsed) const
{
    if(m_Line)
        cerr << m_Name << "  Line:" << m_Line << " - Timer took " << elapsed.count() << " ms\n";
    else
        cerr << m_Name << " - Timer took " << elapsed.count() << " ms\n";
}
