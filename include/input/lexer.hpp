#ifndef LEXER_HPP
#define LEXER_HPP

#include "common.hpp"
#include "map.hpp"

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
// #define TOK_DI '[0-9]'
// #define TOK_NA '[a-zA-Z]'

class Lexer{
    public:
        Lexer();
        ~Lexer();

        bool isdigit(char c);
        bool isalpha(char c);
        bool iswhitespace(char c);
        string tolower(string s);

        void tokenize(char *s);
        void printmap();

    private:
        Maps _tkns;
};

#endif