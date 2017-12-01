#include "eval/matrix.hpp"

Matrix::Matrix(){}
Matrix::~Matrix(){}

void Matrix::tomatrix(string m)
{
    string mat_str;
    vector<string> vals;
    size_t np = m.find("[");
    size_t pe = m.find("]");

    np = m.find("[", np + 1) + 1;
    mat_str = m.substr(np, pe - np);
    cout << "np: " << np << "\npe: " << pe << "\n" << mat_str << endl;
}

void Matrix::row(string n, vector<string> m)
{
    m = strsplit(";", n);
}