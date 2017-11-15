#ifndef LEXER_HPP
#define LEXER_HPP

#include "common.hpp"
#include "map.hpp"

class Lexer{
    public:
        Lexer();
        ~Lexer();

        Maps getTokens();

        void printmap();
        void tokenize(char *s);

    private:
        Maps _tkns;
};

#endif