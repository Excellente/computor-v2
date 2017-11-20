#ifndef LIB_HPP
#define LIB_HPP

#define TOK_LP '('
#define TOK_RP ')'
#define TOK_LSB '['
#define TOK_RSB ']'
#define TOK_QM '?'
#define TOK_CO ','
#define TOK_SC ';'
#define TOK_DP '.'

// ================= operator macros ===================
#define TOK_OADD '+'
#define TOK_OSUB '-'
#define TOK_ODIV '/'
#define TOK_OMUL '*'
#define TOK_OMOD '%'
#define TOK_OEXP '^'
#define TOK_OEQU '='

#define OP_ADD "OP_ADD"
#define OP_SUB "OP_SUB"
#define OP_DIV "OP_DIV"
#define OP_MUL "OP_MUL"
#define OP_MOD "OP_MOD"
#define OP_EXP "OP_EXP"
#define OP_EQU "OP_EQU"

#define _EOF_ "^:\0"
#define _NULL_ "-1\0"
#define BUFF_SIZE 1024
#define __sqrt(x) sqrt(x)

#include <map>
#include <regex>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool isop(string s);
bool isdigit(char c);
bool isalpha(char c);
bool isname(string s);
bool isnumber(string s);
string tolower(string s);
bool isfunction(string s);
bool iswhitespace(char c);
string _substr(string l, int s, int e);

// template <class T>
void print(vector<string> s);

typedef vector<string>::iterator mapit_t;

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