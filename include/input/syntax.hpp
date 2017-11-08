#ifndef INPUT_HPP
#define INPUT_HPP

#define BUFF_SIZE 1024

#include "common.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer(); 

        char *read_line();
        string getLhs() const;
        string getRhs() const;

        void parse(char *l);
        void setLhs(string s);
        void setRhs(string s);

    private:
        bool _isFloat;
        bool _isUnknown;
        bool _isComplex;
        bool _isFunction;
        
        string _lhs;
        string _rhs;
        vector<string> _sp;
};

#endif