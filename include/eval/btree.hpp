#ifndef BTREE_HPP
#define BTREE_HPP

#include "common.hpp"
#include "input/map.hpp"
#include "eval/matrix.hpp"
#include "eval/complex.hpp"

class BTree{

    public:
        Matrix *_mat;
        Complex *_com;
        BTree *_left;
        BTree *_right;

        BTree();
        ~BTree();
        BTree(const BTree &);
        BTree(string op = "", int sign = 1);

        int getSign() const;
        string getName() const;
        BTree *getLeft() const;
        Matrix *getMat() const;
        double getValue() const;
        Complex *getCom() const;
        BTree *getRight() const;
        Maps getOperand1() const;
        Maps getOperand2() const;
        double pow(double, double);
        double operator+(BTree const &);
        double operator-(BTree const &);
        double operator*(BTree const &);
        float operator/(BTree const &);
        BTree &operator=(BTree const &);

        void visit();
        void print();
        void setName(string);
        void setValue(float);
        void setMat(Matrix *);
        void tostring(string);
        void setCom(Complex *);
        void set_operands(Maps);

    private:
        int _sign;
        string _name;
        Maps _oprnd1;
        Maps _oprnd2;
        float _value1;
        float _value;
};

#endif