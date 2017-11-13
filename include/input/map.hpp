#ifndef MAP_HPP
#define MAP_HPP

#include "common.hpp"

class Maps{
    public:
        Maps();
        ~Maps();

        void print();
        void insert(string &k, string &v);
        
        void operator=(const char &s);
        void operator=(const string &s);

        string value_at(const int &s);
        string value_at(const string &s);

        vector<string>::iterator end();
        vector<string>::iterator begin();
        
        string operator[](const int &s);
        Maps &operator[](const string &s);

    private:
        int _len;
        vector<string> _k;
        vector<string> _v;
};

#endif