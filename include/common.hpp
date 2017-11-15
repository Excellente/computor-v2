#ifndef COMMON_H
#define COMMON_H

#define __sqrt(x) sqrt(x)


#include "lib.hpp"

#define __sqrt(x) sqrt(x)

#define _EOF_ "^\0"
#define BUFF_SIZE 1024

using namespace std;

typedef vector<string>::iterator maper_t;

static vector<string> strsplit(string del, string _exp)
{
    int len;
    size_t pos;
    vector<int> delpos;
    vector<string> terms;

    len = 0;
    for (int i = 0; i != string::npos;)
    {
        delpos.push_back((i = _exp.find(del, i + 1)));
        len++;
    }
    terms.push_back(_exp.substr(0, delpos[0]));
    for (int i = 1; i < len; i++)
        terms.push_back(_exp.substr(delpos[i - 1] + 1, (delpos[i] - delpos[i - 1]) - 1));
    return (terms);
}

#endif