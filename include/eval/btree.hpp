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
        BTree(string op = "");

        int getValue() const;
        string getName() const;
        BTree *getLeft() const;
        BTree *getRight() const;
        Maps getOperand1() const;
        Maps getOperand2() const;

        void visit();
        void print();
        void setValue(float v);
        void set_operands(Maps _t);
        int operator+(BTree const &r);
        int operator-(BTree const &r);
        int operator*(BTree const &r);
        int operator/(BTree const &r);
        BTree &operator=(BTree const &r);
    
    private:
        string _name;
        int _value;
        Maps _oprnd1;
        Maps _oprnd2;
        float _value1;
};

#endif