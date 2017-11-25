#ifndef INPUT_HPP
#define INPUT_HPP

#include "map.hpp"
#include "common.hpp"
#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "eval/stoken.hpp"
#include "eval/function.hpp"

void print_stack(stack<SToken>);

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        int eval_exp(BTree *&b);
        bool can_eval(BTree *, string);

        void node_eval();
        void parse(BTree *&);
        void getVal(BTree *&);
        void value_of(string);
        void paranScan(char *);
        void op_equal(BTree *&);
        bool search_map(string);
        void delete_tree(BTree *&);
        void var_declaration(BTree *&);
        void function_declaration(BTree *&);
        void build_ast(Maps, BTree *&) throw (InvalidSyntaxException);
        void build_ast(stack<SToken> &, BTree *&) throw (InvalidSyntaxException);

    private:
        int _index;
        Maps _tkns;
        mapit_t _bgn;
        mapit_t _end;
        BTree *_bt;
        BTree *_f_rhs;
        map<string, Function*> _funct;
        map<string, string> _vars_int;
        map<string, string> _vars_float;
};

#endif