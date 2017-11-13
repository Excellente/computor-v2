#ifndef MAP_HPP
#define MAP_HPP

#include "common.hpp"

class Maps{
    public:
        Maps();
        ~Maps();

        void print();
        void insert(string &k, string &v);
        // mymap["stuff"] = "things";
        string value_at(const string &s);
        void operator=(const string &s);

    private:
        vector<string> _k;
        vector<string> _v;
};

#endif