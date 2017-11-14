#ifndef LEXER_HPP
#define LEXER_HPP

#include "common.hpp"
#include "map.hpp"
#include "lib.hpp"

#define TOK_LP '('
#define TOK_RP ')'
#define TOK_LSB '['
#define TOK_RSB ']'
#define TOK_EQ '='
#define TOK_QM '?'
#define TOK_CO ','
#define TOK_SC ';'
#define TOK_OA '+'
#define TOK_OS '-'
#define TOK_OD '/'
#define TOK_OM '*'
#define TOK_DP '.'

class Lexer{
    public:
        Lexer();
        ~Lexer();

        string getNextToken();

        void printmap();
        void tokenize(char *s);

    private:
        Maps _tkns;
        maper_t _bgn;
        maper_t _end;
};

#endif