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

        string getName() const;
        BTree *getLeft() const;
        BTree *getRight() const;
        Maps getOperand1() const;
        Maps getOperand2() const;

        void visit();
        void print();
        void set_operands(Maps _tkns);
    
    private:
        string _name;
        float _value;
        Maps _oprnd1;
        Maps _oprnd2;
};

#endif