#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

class InvalidSyntaxException : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("InvalidSyntax");
        }
};

class IndexOutOfBounds : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("IndexOutOfBoundsException");
        }
};

class InvalidOperatorException : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("InvalidOperatorException");
        }
};

class InvalidOperandException : public exception{
    using exception::what;
    public:
        virtual const char *what() const throw(){
            return ("InvalidOperandException");
        }
};

#endif