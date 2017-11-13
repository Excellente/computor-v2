#include "input/map.hpp"

Maps::Maps(){
    _len = 0;
}
Maps::~Maps(){}

int Maps::length(){
    return (_len);
}

vector<string>::iterator Maps::end(){
    return (_k.end());
}

vector<string>::iterator Maps::begin(){
    return (_k.begin());
}

string Maps::value_at(const string &s)
{
    vector<string>::const_iterator end_key_i = _k.end();
    vector<string>::const_iterator begin_key_i = _k.begin();
    vector<string>::const_iterator eval_i = _v.end();
    vector<string>::const_iterator bval_i = _v.begin();

    while (s.compare(*begin_key_i) != 0 && begin_key_i != end_key_i)
    {
        begin_key_i++;
        bval_i++;
    }
    return (*bval_i);
}

string Maps::value_at(const int &s)
{
    int i = 0;
    vector<string>::const_iterator eval_i = _v.end();
    vector<string>::const_iterator bval_i = _v.begin();

    if (s == _len)
    {
        cerr << "IndexOutOfBounds" << endl;
        exit(EXIT_FAILURE);
    }
    while (i++ < s) bval_i++;
    return (*bval_i);
}

Maps &Maps::operator[](const string &s)
{
    _len++;
    _k.push_back(s);
    return (*this);
}

string Maps::operator[](const int &s){
    return (value_at(s));
}

void Maps::operator=(const string &s){
    _v.push_back(s);
}

void Maps::operator=(const char &s)
{
    string I(1, s);
    _v.push_back(I);
}

void Maps::insert(string &k, string &v)
{
    _len++;
    _k.push_back(k);
    _v.push_back(v);
}

void Maps::print()
{
    vector<string>::iterator kit = _k.begin(); 
    vector<string>::iterator vit = _v.begin(); 
    for (; kit != _k.end() && vit != _v.end(); kit++, vit++)
        cout << *kit << " -> " << *vit << endl;
}