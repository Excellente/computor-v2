#ifndef LEXER_HPP
#define LEXER_HPP

#include "common.hpp"
#include "map.hpp"

class Lexer{
    public:
        Lexer();
        ~Lexer();

        string look_ahead();
        string getNextToken();
        Maps getTokens() const;

        void printmap();
        void tokenize(char *s);

    private:
        int _index;
        Maps _tkns;
        mapit_t _bgn;
        mapit_t _end;
};

#endif