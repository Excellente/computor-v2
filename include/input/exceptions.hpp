#include "common.hpp"

class InvalidSyntaxException : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("Error: InvalidSyntaxException");
        }
};

class IndexOutOfBounds : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("Error: IndexOutOfBoundsException");
        }
};