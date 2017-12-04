#ifndef INPUT_HPP
#define INPUT_HPP

#include "map.hpp"
#include "common.hpp"
#include "eval/btree.hpp"
#include "input/lexer.hpp"
#include "eval/stoken.hpp"
#include "input/error.hpp"
#include "eval/matrix.hpp"
#include "eval/complex.hpp"
#include "eval/function.hpp"

void print_stack(stack<SToken>);

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        int eval_exp(BTree *&b);
        int eval_exp(BTree *&, string);
        int eval_func(BTree *, string);

        bool is_matrix(string);
        bool search_map(string);
        bool ismatrix_tree(BTree *);
        bool iscomplex_tree(BTree *);
        bool can_eval(BTree *, string);

        Matrix *matrix_eval(BTree *&);
        Complex *complex_eval(BTree *&);

        void node_eval();
        void parse(BTree *&);
        void getVal(BTree *&);
        void value_of(string);
        void paranScan(char *);
        void op_equal(BTree *&);
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
        map<string, Complex*> _complex;
        map<string, Matrix*> _matrices;
        map<string, string> _vars_float;
};

#endif