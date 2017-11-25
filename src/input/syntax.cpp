#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer(){
    _index = 0;
}

bool SyntaxAnalyzer::can_eval(BTree *r, string v)
{
    bool retval = true;
    string name = r->getName();

    if (isname(name) && name != v)
        retval = true;
    else if (isname(r->getName()) && name == v)
        retval = false;
    // if (r->_right != NULL)
    //     retval &= can_eval(r, v);
    // if (r->_left != NULL)
    //     retval &= can_eval(r, v);
    return (retval);
}

void SyntaxAnalyzer::build_ast(stack<SToken> &s, BTree *&b) throw (InvalidSyntaxException)
{
    BTree *tb;
    stack<SToken> tmp;

    // print_stack(s);
    // return ;
    while (!s.empty())
    {
        if (isop(s.top().getValue()))
            break;
        tmp.push(s.top());
        s.pop();
    }
    if (b == NULL)
    {
        if (!s.empty())
        {
            b = new BTree(s.top().getValue(), s.top().getSign());
            s.pop();
            if (!tmp.empty())
            {
                b->_right = new BTree(tmp.top().getValue(), tmp.top().getSign());
                tmp.pop();
                if (!tmp.empty())
                {
                    b->_left = new BTree(tmp.top().getValue(), tmp.top().getSign());
                    tmp.pop();
                }
            }
        }
        else if (!tmp.empty())
        {
            b = new BTree(tmp.top().getValue(), tmp.top().getSign());
            tmp.pop();
            if (!tmp.empty())
            {
                b->_right = new BTree(tmp.top().getValue(), tmp.top().getSign());
                tmp.pop();
                if (!tmp.empty())
                {
                    b->_left = new BTree(tmp.top().getValue(), tmp.top().getSign());
                    tmp.pop();
                }
            }
        }
    } else {
        if (!s.empty())
        {
            tb = new BTree(s.top().getValue(), s.top().getSign());
            s.pop();
            tb->_right = b;
            b = tb;
            if (!tmp.empty())
            {
                tb->_left = new BTree(tmp.top().getValue(), tmp.top().getSign());
                tmp.pop();        
            }
        }
    }
    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
    if (!s.empty())
        build_ast(s, b);
}

void SyntaxAnalyzer::build_ast(Maps _tk, BTree *&bt) throw (InvalidSyntaxException)
{
    int i;
    bool found;
    string str;
    string tmp = "";
    InvalidSyntaxException ise;
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
        if (_tkns.length() == 1)
            bt = new BTree(_tkns[0]);
        else
            {
                // while ((str = getNextToken()) != _EOF_)
                //     tmp = tmp + str;
                // if (isfunction(tmp) || isnumber(tmp))
                //     bt = new BTree(tmp);
                // else
                //     throw ise;
                // _index = 0;
            }
    }
    _tkns.delete_m();
}

void SyntaxAnalyzer::parse(BTree *&bt)
{
    if (isop(bt->getName()))
    {
        if (bt->getName() == "=")
            op_equal(bt);
    }
    else if (isname(bt->getName()) || isfunction(bt->getName()))
    {
        
        if (bt->_left == NULL && bt->_right == NULL)
            value_of(bt->getName());
    }
}

bool SyntaxAnalyzer::search_map(string s)
{
    size_t lp;
    string fname;
    
    map<string, Function*>::const_iterator _ef = _funct.end();
    map<string, Function*>::const_iterator _bf = _funct.begin();

    map<string, string>::const_iterator _ev = _vars_int.end();
    map<string, string>::const_iterator _bv = _vars_int.begin();

    if (isfunction(s))
    {
        lp = s.find("(");
        fname = s.substr(0, lp - 0);
        for (; _bf != _ef; _bf++)
            if (fname == _bf->first)
                return (true);
    
    } else {
        for (; _bv != _ev; _bv++)
            if (s == _bv->first)
                return (true);
    }
    return (false);
}

void SyntaxAnalyzer::value_of(string s)
{
    size_t lp;
    string fname;

    if (isfunction(s) && search_map(s))
    {
        lp = s.find("(");
        fname = s.substr(0, lp - 0);
        cout << _funct[fname]->getFrhs()->getName() << " = ";
        cout << eval_exp(_funct[fname]->_f_rhs) << endl;
    }
    else if (isname(s) && search_map(s))
        cout << _vars_int[s] << endl;
    else
        cout << "error: " << s << ": hasn't been declared" << endl;
        // cout << 0 << endl;
}

void SyntaxAnalyzer::op_equal(BTree *&bt)
{
    string _lft = bt->_left->getName();
    string _rht = bt->_right->getName();

    // name = name | number | functionCall | exp
    if (isname(_lft) && (isnumber(_rht) || isname(_rht) || isop(_rht)))
        var_declaration(bt);
    // functionDeclare = name | number | functionCall | exp    
    else if (isfunction(_lft) && (isnumber(_rht) || isname(_rht) || isop(_rht)))
        function_declaration(bt);
    else if ((isname(_rht) || isnumber(_rht) || isop(_rht)) && _lft == "?")
        cout << eval_exp(bt->_right) << endl;
    // if (isname(bt->_left->getName()) && isop(bt->_right->getName()));
}

void SyntaxAnalyzer::var_declaration(BTree *&bt)
{
    string val = bt->_right->getName();
    if (isnumber(val))
    {
        if (isinteger(val))
            _vars_int[bt->_left->getName()] = bt->_right->getName();
        else if (isfloat(val))
            _vars_float[bt->_left->getName()] = bt->_right->getName();
    }
    else if (isname(val))
    {
        if (search_map(val))
            _vars_int[bt->_left->getName()] = _vars_int[bt->_right->getName()];
        else
            cout << bt->_right->getName() << ": has not been declared" << endl;
    }
    else if (isop(val))
        _vars_int[bt->_left->getName()] = to_string(eval_exp(bt->_right));
    value_of(bt->_left->getName());
}

void SyntaxAnalyzer::function_declaration(BTree *&bt)
{
    Function *f = new Function(bt->_right);
    size_t lp = bt->_left->getName().find("(");
    string fname = bt->_left->getName().substr(0, lp - 0);
    string vname = bt->_left->getName().substr(++lp, 1);

    _f_rhs = f->getFrhs();
    if (isnumber(_f_rhs->getName()))
    {
        _funct[fname] = f;
        cout << eval_exp(_f_rhs) << endl;
    }
    else if (isname(_f_rhs->getName()) && vname != _f_rhs->getName())
    {
        cout << "var: " << vname << endl;
        if (search_map(_f_rhs->getName()))
        {
            _funct[fname] = f;
            cout << eval_exp(_f_rhs) << endl;
        }
        else
            cout << _f_rhs->getName() << ": has not been declared" << endl;
    }
    else if (isop(_f_rhs->getName()))
    {
        _funct[fname] = f;
        if (can_eval(_f_rhs->_right, vname))
            cout << "can definatetly eval" << endl;
        else
            cout << "impossible" << endl;
            // _funct[fname] = to_string(eval_exp(_f_rhs));
    }
}

void SyntaxAnalyzer::getVal(BTree *&bt)
{
    if (isname(bt->getName()))
    {
        if (search_map(bt->getName()))
            bt->setValue(stoi(_vars_int[bt->getName()]));
    }
    else if (isnumber(bt->getName()))
        bt->setValue(stoi(bt->getName()) * bt->getSign());
}

int SyntaxAnalyzer::eval_exp(BTree *&bt)
{
    int res;

    if (bt->_left != NULL)
        eval_exp(bt->_left);
    getVal(bt);
    if (bt->_right != NULL)
        eval_exp(bt->_right);
    if (isop(bt->getName()))
    {
        if (bt->getName() == "+")
        {
            cout << bt->_left->getValue() << " + " << bt->_right->getValue() << endl;
            res = *bt->_left + *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "-")
        {
            
            cout << bt->_left->getValue() << " - " << bt->_right->getValue() << endl;
            res = *bt->_left - *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "*")
        {
            cout << bt->_left->getValue() << " * " << bt->_right->getValue() << endl;
            res = *bt->_left * *bt->_right;
            bt->setValue(res);
        }
        else if (bt->getName() == "/")
        {
            cout << bt->_left->getValue() << " / " << bt->_right->getValue() << endl;
            if (bt->_right->getValue() != 0)
                res = *bt->_left / *bt->_right;
            else
                cout << "Error: InvalidOperandException" << endl;
            bt->setValue(res);
        }
    }
    return (bt->getValue());
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