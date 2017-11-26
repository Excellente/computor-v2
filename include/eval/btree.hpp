#ifndef BTREE_HPP
#define BTREE_HPP

#include "common.hpp"
#include "input/map.hpp"

class BTree{

    public:
        BTree *_left;
        BTree *_right;

        BTree();
        ~BTree();
        BTree(const BTree &);
        BTree(string op = "", int sign = 1);

        int pow(int, int);
        int getSign() const;
        int getValue() const;
        string getName() const;
        BTree *getLeft() const;
        BTree *getRight() const;
        Maps getOperand1() const;
        Maps getOperand2() const;
        int operator+(BTree const &);
        int operator-(BTree const &);
        int operator*(BTree const &);
        int operator/(BTree const &);
        BTree &operator=(BTree const &);

        void visit();
        void print();
        void setName(string);
        void setValue(float);
        void tostring(string);
        void set_operands(Maps);

    private:
        int _sign;
        int _value;
        string _name;
        Maps _oprnd1;
        Maps _oprnd2;
        float _value1;
};

#endif