#ifndef SHUNTING_HPP
#define SHUNTING_HPP

#include "common.hpp"
#include "eval/btree.hpp"
#include "eval/stoken.hpp"
#include "input/exceptions.hpp"

void print_stack(stack<SToken> st);

class Shunting{
    public:
        stack<SToken> shuntingYard(Maps, int &);
        int error_check(stack<SToken>, stack<SToken>, string, Maps);

        void print(stack<SToken>);
        void assembly_float(string &, Maps &);
        void _token_sign(string &, int &, int &);
        void assembly_matrix_multi(string &, Maps &);
        void assembly_complex(string &, Maps &, SToken &, stack<SToken> &);
        bool leading_sign(int, int &, int, string &, Maps &, SToken &, stack<SToken> &) throw (InvalidSyntaxException);
};

#endif