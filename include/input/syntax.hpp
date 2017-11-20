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

        void node_eval();
        void parse(BTree *&bt);
        void var_declaration();
        void value_of(string s);
        void paranScan(char *l);
        bool search_map(string s);
        void op_equal(BTree *&bt);
        void delete_tree(BTree *&bt);
        void build_ast(Maps _tk, BTree *&bt);

    private:
        Maps _tkns;
        int _tkn_num;
        mapit_t _bgn;
        mapit_t _end;
        map<string, string> _vars_int;
};

#endif