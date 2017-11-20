#ifndef INPUT_HPP
#define INPUT_HPP

#include "map.hpp"
#include "common.hpp"
#include "eval/btree.hpp"
#include "input/lexer.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        string look_ahead();
        string getNextToken();
        bool isAtomic(Maps m);
        float eval_exp(BTree *&b);

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

    private:
        int _index;
        Maps _tkns;
        mapit_t _bgn;
        mapit_t _end;
        BTree *_bt;
        map<string, BTree *> _funct;
        map<string, string> _vars_int;
};

#endif