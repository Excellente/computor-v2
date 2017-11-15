#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <exception>

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

bool isnumber(string s)
{
    regex rn("[0-9]+");

    if (regex_match(s, rn))
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
};

BTree::BTree(int v) : value(v)
{
    right = NULL;
    right = NULL;
}

BTree *BTree::insert(int v)
{
    BTree *tmp = new BTree();

    tmp->value = v;
    v > value ? (right == NULL) ? right = tmp : right->insert(v)
    : (left == NULL) ? left = tmp : left->insert(v);
    return (tmp);
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

int main(int ac, char *av[])
{
    try
    {
        BTree *node = new BTree(2);
        node->insert(4);
        node->insert(5);
        node->insert(1);
        cout << node->getValue() << endl;
        cout << node->getLeft()->getValue() << endl;
        cout << node->getRight()->getValue() << endl;
        cout << node->getRight()->getRight()->getValue() << endl;
    }
    catch(ErrorException &e){
        cerr << e.what() << endl;
    }
    return (0);
}