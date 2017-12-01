#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "common.hpp"

typedef vector<string>::iterator itstr_t;

class Matrix{
    private:
        double _col_length;
        double _row_length;
        double matNN[1020][1020];

    public:
        Matrix();
        ~Matrix();

        double getColLen() const;
        double getRowLen() const;
        Matrix &operator*(const double);
        Matrix &operator+(const Matrix &);
        Matrix &operator-(const Matrix &);
        Matrix &operator|(const Matrix &);

        void print_mat();
        void tomatrix(string);
        void getValues(string &, vector<string> &, int);
};

#endif