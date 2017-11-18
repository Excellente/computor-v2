#ifndef BTREE_HPP
#define BTREE_HPP

#include "common.hpp"
#include "input/map.hpp"

class BTree{

    public:
        ~BTree();
        BTree(string op = "");

        BTree *getLeft() const;
        BTree *getRight() const;
        Maps getOperand1() const;
        Maps getOperand2() const;

        void set_operands(Maps _tkns);
    
    private:
        string _op;
        float _value;
        BTree *_left;
        BTree *_right;
        Maps _oprnd1;
        Maps _oprnd2;
};

#endif