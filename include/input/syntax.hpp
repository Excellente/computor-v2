#ifndef INPUT_HPP
#define INPUT_HPP

#include "common.hpp"

class SyntaxAnalyzer{
    public:
        SyntaxAnalyzer();
        ~SyntaxAnalyzer(); 

        bool isAtomic(string &s);

        void parse(char *l);
        void paranScan(char *l);

    private:
};

#endif