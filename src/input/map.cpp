#include "input/map.hpp"

Maps::Maps(){}
Maps::~Maps(){}

void Maps::insert(string &k, string &v)
{
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

string Maps::value_at(const string &s)
{
    vector<string>::const_iterator eci = _k.end();
    vector<string>::const_iterator bci = _k.begin();

    while (s.compare(*bci) != 0 && bci != eci);
    return (*bci);
}