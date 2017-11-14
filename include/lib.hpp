#ifndef LIB_HPP
#define LIB_HPP

#include <map>
#include <regex>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool isalpha(char c);
bool isname(string &s);
bool isnumber(string &s);
string tolower(string s);
bool iswhitespace(char c);
static vector<string> strsplit(string del, string _exp);

#endif