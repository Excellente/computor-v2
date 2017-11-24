#ifndef INPUT_HPP
#define INPUT_HPP

#include "map.hpp"
#include "common.hpp"
#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "eval/stoken.hpp"

void print_stack(stack<SToken> st);

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        bool isAtomic(Maps m);
        int eval_exp(BTree *&b);

        void node_eval();
        void parse(BTree *&b);
        void getVal(BTree *&bt);
        void value_of(string s);
        void paranScan(char *l);
        void op_equal(BTree *&b);
        bool search_map(string s);
        void delete_tree(BTree *&b);
        void var_declaration(BTree *&b);
        void function_declaration(BTree *&bt);
        void build_ast(Maps _t, BTree *&b) throw (InvalidSyntaxException);
        void build_ast(stack<SToken> &s, BTree *&b) throw (InvalidSyntaxException);

    private:
        int _index;
        Maps _tkns;
        mapit_t _bgn;
        mapit_t _end;
        BTree *_bt;
        BTree *_f_rhs;
        map<string, BTree*> _funct;
        map<string, string> _vars_int;
        map<string, string> _vars_float;
};

#endif