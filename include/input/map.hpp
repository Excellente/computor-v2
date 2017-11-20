#ifndef MAP_HPP
#define MAP_HPP

#include "common.hpp"

#define _npos_ -1

typedef vector<string>::const_iterator const_i_t;

class IndexOutOfBounds : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw()
        {
            return ("Error: IndexOutOfBoundsException");
        }
};

class Maps{
    public:
        Maps();
        ~Maps();

        int length();
        string value_at(const int &s) throw (IndexOutOfBounds);
        string value_at(const string &s) throw (IndexOutOfBounds);

        mapit_t end();
        mapit_t begin();

        int length() const;
        Maps _submap(int e);
        Maps _submap(int s, int e);
        bool search(string const s);
        int index_of(string const s);
        Maps &operator=(const Maps &s);
        string operator[](const int &s);
        Maps &operator[](const string &s);

        void print();
        void delete_m();
        void operator=(const char &s);
        void operator=(const string &s);
        void insert(string &k, string &v);

    private:
        int _len;
        vector<string> _k;
        vector<string> _v;
};

#endif