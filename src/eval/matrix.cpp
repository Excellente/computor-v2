#include "eval/matrix.hpp"

Matrix::Matrix(){}
Matrix::~Matrix(){}

double Matrix::getRowLen() const{
    return (_row_length);
}

double Matrix::getColLen() const{
    return (_col_length);
}

Matrix &Matrix::operator+(const Matrix &r)
{
    for (int i = 0; i < _row_length; i++)
    {
        for (int j = 0; j < _col_length; j++)
            matNN[i][j] = matNN[i][j] + r.matNN[i][j];
    }
    return (*this);
}

Matrix &Matrix::operator-(const Matrix &r)
{
    for (int i = 0; i < _row_length; i++)
    {
        for (int j = 0; j < _col_length; j++)
            matNN[i][j] = matNN[i][j] - r.matNN[i][j];
    }
    return (*this);
}

Matrix &Matrix::operator*(const double r)
{
    for (int i = 0; i < _row_length; i++)
    {
        for (int j = 0; j < _col_length; j++)
            matNN[i][j] = matNN[i][j] * r;
    }
    return (*this);
}

Matrix &Matrix::operator|(const Matrix &r)
{
    int sum;
    double res[1020][1020];

    for (int i = 0; i < _row_length; i++)
    {
        for (int j = 0; j < r.getColLen(); j++)
        {
            sum = 0;
            for (int x = 0; x < _col_length; x++)
                sum += matNN[i][x] * r.matNN[x][j];
            res[i][j] = sum;
        }
    }
    _col_length = r.getColLen();
    for (int i = 0; i < _row_length; i++)
    {
        for (int j = 0; j < _col_length; j++)
            matNN[i][j] = res[i][j];
    }
    return (*this);
}

void Matrix::tomatrix(string st)
{
    int _l;
    itstr_t ite;
    itstr_t itb;
    itstr_t rbe;
    itstr_t ren;
    vector<int> len;
    vector<string> m;
    vector<string> ret;
    vector<string> vals;

    _l = 0;
    if (st.find(";") != string::npos)
    {
        m = strsplit(";", st);
        ite = m.end();
        itb = m.begin();
        for (int i = 0; itb != ite; itb++, i++)
            getValues(*itb, vals, i);
    }
    else
    {
        m.push_back(st);
        itb = m.begin();
        getValues(*itb, vals, 0);
    }
    ite = vals.end();
    itb = vals.begin();
    _row_length = vals.size();
    for (int i = 0; i < _row_length; i++, itb++)
    {
        ret = strsplit(",", *itb);
        ren = ret.end();
        rbe = ret.begin();
        _col_length = ret.size();
        for (int j = 0; j < _col_length; j++, rbe++)
            matNN[i][j] = stod(*rbe);
    }
}

void Matrix::print_mat()
{
    for (int i = 0; i < _row_length; i++)
    {
        cout << " [";
        for (int j = 0; j < _col_length; j++)
            if (j < _col_length - 1)
                cout << matNN[i][j] << " , ";
            else 
                cout << matNN[i][j];
        cout << "]" << endl;
    }
}

string Matrix::tostring()
{
    string str = "";

    for (int i = 0; i < _row_length; i++)
    {
        str += " [";
        for (int j = 0; j < _col_length; j++)
            if (j < _col_length - 1)
                str += to_string(matNN[i][j]) + " , ";
            else 
                str += to_string(matNN[i][j]);
        str += "]";
    }
    return (str);
}

void Matrix::getValues(string &m, vector<string> &v, int f)
{
    string mat_str;
    size_t np = m.find("[");
    size_t pe = m.find("]");

    if (f == 0)
        np = m.find("[", np + 1) + 1;
    else np += 1;
    mat_str = m.substr(np, pe - np);
    v.push_back(mat_str);
}