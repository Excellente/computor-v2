#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}
SyntaxAnalyzer::SyntaxAnalyzer()
{
    _tkn_num = 0;
    _end = _tkns.end();
    _bgn = _tkns.begin();
}

string SyntaxAnalyzer::look_ahead()
{
    return (_tkns.value_at(*_bgn));
}

string SyntaxAnalyzer::getNextToken()
{
    string st;
    if (_bgn != _end)
    {
        st = _tkns.value_at(*_bgn);
        _bgn++;
        _tkn_num++;
    }
    else
        return (_EOF_);
    return (st);
}

bool SyntaxAnalyzer::isAtomic(Maps m)
{
    if (m.length() == 1 && (isnumber(m[0]) || isname(m[0])))
        return (true);
    return (false);
}

bool SyntaxAnalyzer::search_map(string s)
{
    map<string, string>::const_iterator _e = _vars_int.end();
    map<string, string>::const_iterator _b = _vars_int.begin();

    for (; _b != _e; _b++)
        if (s == _b->first)
            return (true);
    return (false);
}

void SyntaxAnalyzer::value_of(string s)
{
    if (search_map(s))
        cout << _vars_int[s] << endl;
    else
        cout << 0 << endl;
}

void SyntaxAnalyzer::var_declaration(BTree *&bt)
{
    if (isnumber(bt->_right->getName()))
            _vars_int[bt->_left->getName()] = bt->_right->getName();
    else if (isname(bt->_right->getName()))
    {
        if (search_map(bt->_right->getName()))
            _vars_int[bt->_left->getName()] = _vars_int[bt->_right->getName()];
        else
            cout << bt->_right->getName() << ": has not been declared" << endl;
    }
    else if (isop(bt->_right->getName()))
        _vars_int[bt->_left->getName()] = to_string(eval_exp(bt->_right));
}

void SyntaxAnalyzer::getVal(BTree *&bt)
{
    if (isname(bt->getName()))
    {
        if (search_map(bt->getName()))
            bt->setValue(stof(_vars_int[bt->getName()]));
        else
        {
            cout << bt->_right->getName() << ": has not been declared" << endl;
            return;
        }
    }
    else if (isnumber(bt->getName()))
        bt->setValue(stof(bt->getName()));
}

float SyntaxAnalyzer::eval_exp(BTree *&bt)
{
    float res;

    if (bt->_left != NULL)
        eval_exp(bt->_left);
    getVal(bt);
    if (bt->_right != NULL)
        eval_exp(bt->_right);
    if (isop(bt->getName()))
    {
        if (bt->getName() == "OP_ADD")
        {
            res = *bt->_left + *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "OP_SUB")
        {
            res = *bt->_left - *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "OP_MUL")
        {
            res = *bt->_left * *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "OP_DIV")
        {
            if (bt->_right->getValue() != 0)
                res = *bt->_left / *bt->_right;
            else
                cout << "Error: InvalidOperandException" << endl;
            bt->setValue(res);
        }
    }
    return (bt->getValue());
}

void SyntaxAnalyzer::op_equal(BTree *&bt)
{
    // Q_MARK
    if (isname(bt->_left->getName()) && (isnumber(bt->_right->getName()) || isname(bt->getName()) || isop(bt->getName())))
        var_declaration(bt);
    // if (isname(bt->_left->getName()) && isop(bt->_right->getName()));
}

void SyntaxAnalyzer::delete_tree(BTree *&bt)
{
    if (bt->_left != NULL)
        delete_tree(bt->_left);
    if (bt->_right != NULL)
        delete_tree(bt->_right);
    delete bt;
    bt = NULL;
}

void SyntaxAnalyzer::parse(BTree *&bt)
{
    if (isop(bt->getName()))
    {
        if (bt->getName() == "OP_EQU")
            op_equal(bt);
    }
    else if (isname(bt->getName()))
    {
        if (bt->_left == NULL && bt->_right == NULL)
            value_of(bt->getName());
    }
}

void SyntaxAnalyzer::build_ast(Maps _tk, BTree *&bt)
{
    int i;
    bool found;
    string ops[] = {OP_EQU, OP_ADD, OP_SUB, OP_DIV, OP_MUL, OP_MOD, OP_EXP, _NULL_};

    this->_tkns = _tk;
    for (i = 0; ops[i] != _NULL_ && !(found = _tkns.search(ops[i])); i++)
        ;
    if (found)
    {
        bt = new BTree(ops[i]);
        bt->set_operands(_tkns);
        build_ast(bt->getOperand1(), bt->_left);
        build_ast(bt->getOperand2(), bt->_right);

    }
    else
    {
        if (_tk.length() == 1)
            bt = new BTree(_tk[0]);
        else
            {
                // concatenate all tokens
                // verify if result is a function
                // create a function node
            }
    }
}