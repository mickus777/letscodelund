#ifndef ORD_H
#define ORD_H

#include <iostream>
#include <vector>

/*
struct StringNum
{
    StringNum() = default;
    StringNum(const std::string &str)
        : m_str(str)
    {  }

    int m_num = 1;
    std::string m_str;
};
*/

struct WordList
{
    WordList(const std::string &old, const std::string &ny)
        : m_name(old)
    {
        m_list.push_back(ny);
    }

    std::string m_name;
    std::vector<std::string> m_list;
};

class ord
{
public:
    std::vector< WordList > m_list;

    ord() = default;
    ~ord();

    void AddWord(const std::string &old, const std::string &now);

    int load(const char *filnamn);

    void write();
    std::string getAWord(const std::string &sin);
};

#endif // ORD_H
