#ifndef BTREE_HPP
#define BTREE_HPP

#include "common.hpp"
#include "input/map.hpp"

class BTree{
    string _op;
    float _value;
    BTree *_left;
    BTree *_right;
    vector<string> _oprnd1;
    vector<string> _oprnd2;

    public:
        ~BTree();
        BTree(string op = "");

        vector<string> getOperand1() const;
        vector<string> getOperand2() const;

        void set_operands(Maps _tkns);
};

#endif