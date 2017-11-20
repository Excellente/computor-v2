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
        void var_declaration();
        void paranScan(char *l);
        void parse(Maps _tk, BTree *&bt);

    private:
        Maps _tkns;
        int _tkn_num;
        mapit_t _bgn;
        mapit_t _end;
};

#endif