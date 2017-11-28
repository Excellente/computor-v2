#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "common.hpp"

class Matrix{
    private:
        map<string, string> rows;
        map<string, string> columns;
    public:
        Matrix();
        ~Matrix();

        map<string, string> getRows() const;
        map<string, string> getColumns() const;
};

#endif