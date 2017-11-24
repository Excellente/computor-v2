#ifndef FUNCT_HPP
#define FUNCT_HPP

#include "common.hpp"
#include "eval/btree.hpp"
#include "eval/stoken.hpp"

class Function{
    private:
        BTree *_f_rhs;
        string _str_val;
        stack<SToken> _stk_val;

    public:
        ~Function();
        Function(BTree *);

        void tostack(BTree *);
        void tostring(BTree *);
};

#endif