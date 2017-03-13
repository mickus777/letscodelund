#ifndef LIST_H
#define LIST_H

#include <vector>

class list
{
public:
    list(const char *name = nullptr);

    int load(const char *);

    std::vector<int> m_list;
};

#endif // LIST_H
