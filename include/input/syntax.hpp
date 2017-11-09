#ifndef INPUT_HPP
#define INPUT_HPP

#define BUFF_SIZE 1024

#include "common.hpp"

#define TOK_LB '('
#define TOK_RB ')'

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer(); 

        char *read_line();
        string getLhs() const;
        string getRhs() const;
        bool isAtomic(string &s);
        bool parseExpression(char *s);
        
        void parse(char *l);
        void trim(string &s);
        void setLhs(string s);
        void setRhs(string s);
        void ltrim(string &s);
        void rtrim(string &s);
        void paranScan(char *l);
        
    private:
        int _bracket;
        bool _isFloat;
        bool _isUnknown;
        bool _isComplex;
        bool _isFunction;
        
        string _lhs;
        string _rhs;
        vector<string> _sp;
};

#endif