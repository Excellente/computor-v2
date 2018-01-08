#include "input/map.hpp"

Maps::Maps(){
    _len = 0;
    _index = 0;
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

int Maps::length() const{
    return (_len);
}

string Maps::look_back(int l)
{
    int i;
    mapit_t bgin;

    i = l;    
    bgin = _bgn + 1;

    while (i-- && bgin != begin()) bgin--;
    if (bgin == begin() || (_index - l) < 0)
        return (_EOF_);
    return (value_at(_index - l));
}

string Maps::look_ahead(int l)
{
    int i = _index;
    mapit_t bgn = begin();

    while (i-- && bgn != _end) bgn++;
    if (bgn == _end || (_index + l) >= _len)
        return (_EOF_);
    return (value_at(_index + l));
}

string Maps::getNextToken()
{
    string ret;
    int i = _index;
    _end = end();
    _bgn = begin();

    while (i-- && _bgn != _end) _bgn++;
    if (_bgn == _end) return (_EOF_);
    ret = value_at(_index);
    _index++;
    return (ret);
}

int Maps::index_of(string const s)
{
    int ret = 0;
    mapit_t _end = end();
    mapit_t _bgn = begin();

    if (value_at(s) == _EOF_) return (-1);
    for (; *_bgn != s && _bgn != _end; _bgn++) ret++;
    return (ret);
}

bool Maps::search(string const s)
{
    string ret_s = value_at(s);

    if (ret_s == _EOF_)
        return (false);
    return (true);
}

Maps Maps::_submap(int s)
{
    int i = s;
    Maps retmap = Maps();
    mapit_t _end = end();
    mapit_t _beg = begin();

    if (s < 0) exit(EXIT_FAILURE);
    while (i--) _beg++;
    for (; _beg != _end; _beg++)
    {
        retmap._len++;
        retmap._k.push_back(this->_k[s]);
        retmap._v.push_back(this->_v[s++]);
    }
    return (retmap);
}

Maps Maps::_submap(int start, int fin)
{
    int i = start;
    Maps retmap = Maps();
    mapit_t _end = end();
    mapit_t _beg = begin();

    if (start < 0)
        exit(EXIT_FAILURE);
    while (i--) _beg++;
    if (fin == -1)
    {
        retmap._len++;
        retmap._k.push_back("NUMBER");
        retmap._v.push_back("0");
        return (retmap);
    }
    if (start > fin) exit(EXIT_FAILURE);
    for (int j = start; j <= fin; j++)
    {
        retmap._len++;
        retmap._k.push_back(this->_k[j]);
        retmap._v.push_back(this->_v[j]);
    }
    return (retmap);
}

string Maps::value_at(string const &s) throw (IndexOutOfBounds)
{
    IndexOutOfBounds iob;
    const_i_t eval_i = _v.end();
    const_i_t bval_i = _v.begin();
    const_i_t end_key_i = _k.end();
    const_i_t begin_key_i = _k.begin();

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

Maps &Maps::operator=(const Maps &rhs)
{
    _k = rhs._k;
    _v = rhs._v;
    _len = rhs._len;
    return (*this);
}

void Maps::delete_m()
{
    const_i_t eval_i = _v.end();
    const_i_t bval_i = _v.begin();
    const_i_t end_key_i = _k.end();
    const_i_t begin_key_i = _k.begin();

    if (!_v.empty() && !_k.empty())
    {
        _len = 0;
        _index = 0;
        _v.erase(bval_i, eval_i);
        _k.erase(begin_key_i, end_key_i);
    }
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

void Maps::check_funct(string &t)
{
    int i;
    bool ret;

    ret = look_ahead(0) == _EOF_ | look_ahead(1) == _EOF_ | look_ahead(2) == _EOF_;
    if (!ret)
    {
        if (isname(t) && look_ahead(0) == "(" && (isname(look_ahead(1))
            || isnumber(look_ahead(1))) && look_ahead(2) == ")")
        {
            for (i = 0; i < 3; i++)
                t = t + look_ahead(i);
            _index += i;
        }
    }
}

void Maps::check_matrix(string &t)
{
    int i;
    int sbrace;
    // [[1,2];[2,3]]
    for (i = 0, sbrace = 1; i < _len; i++)
    {
        if (look_ahead(i) == "[")
            sbrace++;
        if (look_ahead(i) == "]")
            sbrace--;
        if (!sbrace)
            break;
        t += look_ahead(i);
    }
    t += look_ahead(i++);
    if (ismatrix(t)) _index += i;
}