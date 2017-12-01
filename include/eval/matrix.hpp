#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "common.hpp"

typedef vector<string>::iterator itstr_t;

class Matrix{
    private:
        double _col_length;
        double _row_length;
        double matNN[1020][1020];
        map<string, string> rows;
        map<string, string> columns;

    public:
        Matrix();
        ~Matrix();

        map<string, string> getRows() const;
        map<string, string> getColumns() const;

        void print_mat();
        void tomatrix(string);
        void getValues(string &, vector<string> &, int);
};

#endif