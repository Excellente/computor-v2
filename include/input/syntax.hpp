#ifndef INPUT_HPP
#define INPUT_HPP

#define BUFF_SIZE 1024

#include "common.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer();
        
        char *read_line();
        void parse(char *l);

    private:
        bool isFloat;
        bool isUnknown;
        bool isComplex;
        bool isFunction;
};

#endif