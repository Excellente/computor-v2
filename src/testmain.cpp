#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <exception>
#include "input/map.hpp"
#include "common.hpp"

using namespace std;

string _substr(string l, int s, int e)
{
    int i;
    int j = 0;
    char *str;

    if ((e < s))
        return ("");
    str = (char *)malloc((sizeof(char) * (e - s)) + 1);
    if (str == NULL)
        return ("");
    for (i = 0; i != s && l[i] != '\0'; i++);
    while (i < e && l[i] != '\0')
        str[j++] = l[i++];
    str[j] = '\0';
    string ret(str);
    return (ret);
}

string tolower(string s)
{
    string tl(s);
    for (int i = 0; tl[i] != '\0'; i++)
        if (tl[i] >= 65 && tl[i] <= 90)
            tl[i] += 32;
    return (tl);
}

bool isalpha(char c)
{
    regex rn("[a-zA-Z]");

    if (regex_match(string(1, c), rn))
        return (true);
    return (false);
}

class ErrorException : public exception {
    using exception::what;
    public:
        virtual const char* what() throw() {
            return "ErrorExcpetion";
        }
};

int divide(int a, int b) throw(ErrorException)
{
    int q;
    ErrorException ee;

    if (b == 0)
        throw ee;
    q = a / b;
    return (q);
}

class BTree{
    int value;
    BTree *left;
    BTree *right;
    
    public:
        BTree(int v = 0);
        ~BTree();
        BTree *insert(int v);
        int getValue() const;
        BTree *getLeft() const;
        BTree *getRight() const;

        void visit();
        void print();
        void traverse();
};

void BTree::print()
{
    if (left != NULL)
        left->print();
    visit();
    if (right != NULL)
        right->print();
}

BTree::BTree(int v) : value(v)
{
    left = NULL;
    right = NULL;
}

BTree *BTree::insert(int v)
{
    BTree *tmp = new BTree();

    tmp->value = v;
    v > value ? ((right == NULL) ? right = tmp : right->insert(v))
    : ((left == NULL) ? left = tmp : left->insert(v));
    return (tmp);
}

void BTree::traverse()
{
    if (left != NULL)
        left->traverse();
    visit();
    if (right != NULL)
        right->traverse();
}

void BTree::visit()
{
    cout << value << endl;
}

BTree *BTree::getLeft() const
{
    return (left);
}

BTree *BTree::getRight() const
{
    return (right);
}

int BTree::getValue() const
{
    return (value);
}

bool isAtomic(Maps m)
{
    if (m.length() == 1 && (isnumber(m[0]) || isname(m[0])))
        return (true);
    return (false);
}

bool isfunction(string s)
{
    regex rf("[a-zA-Z]+\\([a-zA-Z]\\)");
    return (regex_match(s, rf));
}

bool isnumber(string s)
{
    regex rn("[0-9]+\\.[0-9]+|[0-9]+");
    return (regex_match(s, rn));
}

bool isop(string s)
{
    regex ro("OP_ADD|OP_SUB|OP_DIV|OP_MUL|OP_MOD|OP_EXP|OP_EQU|\\+|-|/|\\*|\\^|\\%|=");
    if (regex_match(s, ro) || s == "**")
        return (true);
    return (false);
}

int main(int ac, char *av[])
{
    regex rm("(\\s+)?\\[(\\s+)?\\[(\\s+)?([0-9]+((\\s+)?,(\\s+)?[0-9]+)?)?(\\s+)?\\]((\\s+)?;(\\s+)?(\\s+)?\\[(\\s+)?[0-9]+((\\s+)?,(\\s+)?[0-9]+)?(\\s+)?\\](\\s+)?)?(\\s+)?\\](\\s+)?");
    try
    {
        if (isop("0"))
            cout << "yep is operator" << endl;
        else
            cout << "nope not operator" << endl;
    }
    catch(ErrorException &e){
        cerr << e.what() << endl;
    }
    return (0);
}