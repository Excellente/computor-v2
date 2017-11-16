#include "input/map.hpp"

Maps::Maps(){
    _len = 0;
}

Maps::~Maps(){}

int Maps::length(){
    return (_len);
}

mapit_t Maps::end(){
    return (_k.end());
}

mapit_t Maps::begin(){
    return (_k.begin());
}

bool Maps::search(string const s)
{
    string ret_s = value_at(s);

    if (ret_s == _EOF_)
        return (false);
    return (true);
}

string Maps::value_at(const string &s) throw (IndexOutOfBounds)
{
    IndexOutOfBounds iob;
    const_i_t end_key_i = _k.end();
    const_i_t begin_key_i = _k.begin();
    const_i_t bval_i = _v.begin();
    const_i_t eval_i = _v.end();

    if (!_len)
        throw iob;
    while (s != *begin_key_i && begin_key_i != end_key_i)
    {
        begin_key_i++;
        bval_i++;
    }
    if (bval_i == eval_i)
        return (_EOF_);
    return (*bval_i);
}

string Maps::value_at(const int &s) throw (IndexOutOfBounds)
{
    int i = 0;
    IndexOutOfBounds iob;
    const_i_t eval_i = _v.end();
    const_i_t bval_i = _v.begin();

    if (s == _len || _len == 0)
        throw iob;
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

Maps &Maps::operator=(const Maps &rhs)
{
    _k = rhs._k;
    _v = rhs._v;
    _len = rhs._len;
    return (*this);
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