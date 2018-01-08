#ifndef ERROR_HPP
#define ERROR_HPP

#include "eval/btree.hpp"
#include "exceptions.hpp"

class Error{
    public:
        Error();
        ~Error();
    
        bool hasop(BTree *);
        bool isleaf(string s);

        void ScanTree(BTree *) throw (InvalidSyntaxException);
        void OperandScan(BTree *) throw (InvalidOperandException);
        void OperatorScan(BTree *) throw (InvalidSyntaxException);
};

#endif