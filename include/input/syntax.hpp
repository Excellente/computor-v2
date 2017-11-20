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
        void build_ast(Maps _t, BTree *&b);

    private:
        Maps _tkns;
        int _tkn_num;
        mapit_t _bgn;
        mapit_t _end;
        map<string, string> _vars_int;
};

#endif