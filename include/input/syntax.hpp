#ifndef INPUT_HPP
#define INPUT_HPP

#include "common.hpp"
#include "map.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();

        string getNextToken();

        void parse(Maps _tk);
        void paranScan(char *l);

    private:
        Maps _tkns;
        maper_t _bgn;
        maper_t _end;
};

#endif