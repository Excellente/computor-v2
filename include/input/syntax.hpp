#ifndef INPUT_HPP
#define INPUT_HPP

#include "common.hpp"
#include "map.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        string look_ahead();
        string getNextToken();

        void parse(Maps _tk);
        void paranScan(char *l);

    private:
        Maps _tkns;
        int _tkn_num;
        mapit_t _bgn;
        mapit_t _end;
};

#endif