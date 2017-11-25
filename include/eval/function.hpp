#ifndef FUNCT_HPP
#define FUNCT_HPP

#include "common.hpp"
#include "eval/btree.hpp"
#include "eval/stoken.hpp"

void print_stack(stack<SToken> st);

class Function{
    private:
        int _val;

    public:
        BTree *_f_rhs;

        ~Function();
        Function(BTree *&);

        BTree *getFrhs() const;

        void tostring(BTree *&);
};

#endif