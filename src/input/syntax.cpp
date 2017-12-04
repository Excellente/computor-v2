#include "input/syntax.hpp"

SyntaxAnalyzer::~SyntaxAnalyzer(){}

SyntaxAnalyzer::SyntaxAnalyzer(){
    _index = 0;
}

bool SyntaxAnalyzer::is_matrix(string m)
{
    if (ismatrix(m) || _matrices.find(m) != _matrices.end())
        return (true);
    return (false);
}

bool SyntaxAnalyzer::ismatrix_tree(BTree *r)
{
    bool res = false;

    if (is_matrix(r->getName()))
        res = true;
    if (r->_left != NULL)
        res |= ismatrix_tree(r->_left);
    if (r->_right != NULL)
        res |= ismatrix_tree(r->_right);
    return (res);
}

bool SyntaxAnalyzer::iscomplex_tree(BTree *r)
{
    bool res = false;

    if (iscomplex(r->getName()))
        res = true;
    if (r->_left != NULL)
        res |= iscomplex_tree(r->_left);
    if (r->_right != NULL)
        res |= iscomplex_tree(r->_right);
    return (res);
}

bool SyntaxAnalyzer::can_eval(BTree *r, string v)
{
    int val;
    size_t lp;
    string vname;
    string fname;
    bool retval = true;
    string name = r->getName();

    if (isname(name) && name != v)
    {
        getVal(r);
        r->setName(to_string(r->getValue()));
        retval = true;
    }
    else if (isfunction(name))
    {
        lp = name.find("(");
        fname = name.substr(0, lp - 0);
        vname = name.substr(++lp, 1);
        if (isname(vname))
            vname = _vars_int[v];
        val = eval_func(_funct[fname]->_f_rhs, vname);
        r->setName(to_string(val));
        retval = true;
    }
    else
        retval = false;
    if (r->_right != NULL)
        retval &= can_eval(r->_right, v);
    if (r->_left != NULL)
        retval &= can_eval(r->_left, v);
    return (retval);
}

void SyntaxAnalyzer::build_ast(stack<SToken> &s, BTree *&b) throw (InvalidSyntaxException)
{
    BTree *tb;
    stack<SToken> tmp;
    InvalidSyntaxException ise;

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
        else
            throw ise;
    }
    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
    if (!s.empty())
        build_ast(s, b);
}

void SyntaxAnalyzer::parse(BTree *&bt)
{
    Error err;

    err.ScanTree(bt);
    err.OperandScan(bt);
    if (isop(bt->getName()))
    {
        if (bt->getName() == "=")
            op_equal(bt);
        else
            cout << eval_exp(bt) << endl;
    }
    else if (is_matrix(bt->getName()) || isname(bt->getName()) || isnumber(bt->getName()) || 
             isfunction(bt->getName()) || iscomplex(bt->getName()))
    {
        if (isfunction(bt->getName()))
            value_of(bt->getName());
        else
            cout << "use: <exp> = ?: e.g 2 + a = ?" << endl;
        // if (bt->_left == NULL && bt->_right == NULL)
        //     value_of(bt->getName());
    }
}

bool SyntaxAnalyzer::search_map(string s)
{
    size_t lp;
    string fname;
    
    map<string, Function*>::const_iterator _ef = _funct.end();
    map<string, Function*>::const_iterator _bf = _funct.begin();

    if (isfunction(s))
    {
        lp = s.find("(");
        fname = s.substr(0, lp - 0);
        for (; _bf != _ef; _bf++)
            if (fname == _bf->first)
                return (true);
    
    } else {
        if (_matrices.find(s) != _matrices.end() ||
            _vars_int.find(s) != _vars_int.end() ||
            _complex.find(s) != _complex.end())
            return (true);
    }
    return (false);
}

void SyntaxAnalyzer::value_of(string s)
{
    size_t lp;
    string fname;
    string vname;

    if (isfunction(s) && search_map(s))
    {
        lp = s.find("(");
        fname = s.substr(0, lp - 0);
        vname = s.substr(++lp, 1);
        if (isname(vname))
        {
            if (search_map(vname))
                cout << eval_func(_funct[fname]->_f_rhs, _vars_int[vname]) << endl;
            else
                cout << _funct[fname]->getString() << endl;
        }
        else if (isnumber(vname) && !search_map(vname))
            cout << eval_func(_funct[fname]->_f_rhs, vname) << endl;
    }
    else if (isname(s) && search_map(s))
    {
        if (_matrices.find(s) != _matrices.end())
            _matrices[s]->print_mat();
        if (_complex.find(s) != _complex.end())
            _complex[s]->print_cn();
        else
            cout << _vars_int[s] << endl;
    }
    else
        cout << "\033[1;31merror:\033[0m " << s << ": hasn't been declared" << endl;
}

void SyntaxAnalyzer::op_equal(BTree *&bt)
{
    string _lft = bt->_left->getName();
    string _rht = bt->_right->getName();

    // varDeclare = name | number | functionCall | exp
    if (isname(_lft) && (isnumber(_rht) || isname(_rht) || isfunction(_rht) ||
        ismatrix(_rht) || iscomplex(_rht) || isop(_rht)))
        var_declaration(bt);
    // functionDeclare = name | number | functionCall | exp    
    else if (isfunction(_lft) && (isnumber(_rht) || isname(_rht) || isop(_rht)))
        function_declaration(bt);
    else if (_rht == "?" || _lft == "?")
    {
        if (_lft == "?")
        {
            if (ismatrix_tree(bt->_right))
                matrix_eval(bt->_right)->print_mat();
            else if (iscomplex_tree(bt->_right))
                complex_eval(bt->_right)->print_cn();
            else
                cout << eval_exp(bt->_right) << endl;
        }
        else if (_rht == "?")
        {
            if (isname(_lft))
                value_of(_lft);
            else if (iscomplex(_lft))
                complex_eval(bt->_left)->print_cn();
            else if (ismatrix(_lft))
                matrix_eval(bt->_left)->print_mat();
            else if (isnumber(_lft))
                cout << _lft << endl;
        }
    }
}

void SyntaxAnalyzer::var_declaration(BTree *&bt)
{
    size_t lp;
    string fname;
    string vname;
    string val = bt->_right->getName();

    if (bt->_left->getName() == "i")
        cerr << "\033[1;31merror:\033[0m forbidden var_name: " << bt->_left->getName() << endl;
    else
    {
        if (isnumber(val))
        {
            if (_matrices.find(bt->_left->getName()) != _matrices.end())
                _matrices.erase(bt->_left->getName());
            else if (_complex.find(bt->_left->getName()) != _complex.end())
                _complex.erase(bt->_left->getName());
            _vars_int[bt->_left->getName()] = val;
        }
        else if (isname(val))
        {
            //todo: check to if val is not a matrix
            if ((_complex.find(val) != _complex.end()) || val == "i")
            {
                if (_matrices.find(bt->_left->getName()) != _matrices.end())
                    _matrices.erase(bt->_left->getName());
                else if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                    _vars_int.erase(bt->_left->getName());
                if (val == "i")
                    _complex[bt->_left->getName()] = new Complex(val);
                else
                    _complex[bt->_left->getName()] = _complex[val];
            }
            else if (_matrices.find(val) != _matrices.end())
            {
                if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                    _vars_int.erase(bt->_left->getName());
                else if (_complex.find(bt->_left->getName()) != _complex.end())
                    _complex.erase(bt->_left->getName());
                _matrices[bt->_left->getName()] = _matrices[val];
            }
            else if (_vars_int.find(val) != _vars_int.end())
            {
                if (_matrices.find(bt->_left->getName()) != _matrices.end())
                    _matrices.erase(bt->_left->getName());
                else if (_complex.find(bt->_left->getName()) != _complex.end())
                    _complex.erase(bt->_left->getName());
                _vars_int[bt->_left->getName()] = _vars_int[val];
            }
            else
                cout << "\033[1;31merror: \033[0m" << bt->_right->getName() << ": has not been declared." << endl;
        }
        else if (isfunction(val))
        {
            lp = val.find("(");
            fname = val.substr(0, lp - 0);
            vname = val.substr(++lp, 1);
            if (_funct.find(fname) != _funct.end())
            {
                _vars_int[bt->_left->getName()] = to_string(eval_func(_funct[fname]->_f_rhs, vname));
                value_of(val);
            }
            else
                cout << "\033[1;31merror: \033[0m" << bt->_right->getName() << ": has not been declared." << endl;
        }
        else if (ismatrix(val))
        {
            if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                _vars_int.erase(bt->_left->getName());
            Matrix *ma = new Matrix();
            ma->tomatrix(val);
            _matrices[bt->_left->getName()] = ma;
        }
        else if (iscomplex(val))
            _complex[bt->_left->getName()] = new Complex(val);
        else if (isop(val))
        {
            if (ismatrix_tree(bt->_right))
            {
                if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                    _vars_int.erase(bt->_left->getName());
                else if (_complex.find(bt->_left->getName()) != _complex.end())
                    _complex.erase(bt->_left->getName());
                _matrices[bt->_left->getName()] = matrix_eval(bt->_right);
            }
            else if (iscomplex_tree(bt->_right))
            {
                if (_matrices.find(bt->_left->getName()) != _matrices.end())
                    _matrices.erase(bt->_left->getName());
                else if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                    _vars_int.erase(bt->_left->getName());
                _complex[bt->_left->getName()] = complex_eval(bt->_right);
            }
            else
            {
                if (_matrices.find(bt->_left->getName()) != _matrices.end())
                    _matrices.erase(bt->_left->getName());
                else if (_complex.find(bt->_left->getName()) != _complex.end())
                    _complex.erase(bt->_left->getName());
                _vars_int[bt->_left->getName()] = to_string(eval_exp(bt->_right));
            }
        }
        if (!isfunction(bt->_right->getName()))
        {
            if (_matrices.find(bt->_left->getName()) != _matrices.end())
                _matrices[bt->_left->getName()]->print_mat();
            if (_complex.find(bt->_left->getName()) != _complex.end())
                _complex[bt->_left->getName()]->print_cn();
            else if (_vars_int.find(bt->_left->getName()) != _vars_int.end())
                cout << _vars_int[bt->_left->getName()] << endl;
        }
    }
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
    else if (isop(_f_rhs->getName()) || vname == _f_rhs->getName())
    {
        if (can_eval(_f_rhs, vname))
            cout << eval_exp(_f_rhs) << endl;
        else
        {
            f->tostring(_f_rhs);
            cout << f->getString() << endl;
        }
        _funct[fname] = f;
    }
}

void SyntaxAnalyzer::getVal(BTree *&bt)
{
    size_t lp;
    string fname;
    string vname;
    if (isname(bt->getName()))
    {
        if (iscomplex(bt->getName()) || (_complex.find(bt->getName()) != _complex.end()))
        {
            if (iscomplex(bt->getName()))
                bt->_com = new Complex(bt->getName());
            else
                bt->_com = _complex[bt->getName()];
        }
        else if (_matrices.find(bt->getName()) != _matrices.end())
        {
            bt->_mat = new Matrix();
            *(bt->_mat) = *_matrices[bt->getName()] * bt->getSign();
        }
        else if (search_map(bt->getName()))
            bt->setValue(stod(_vars_int[bt->getName()]) * bt->getSign());
        else
        {
            cout << "\033[1;31merror: \033[0m" << bt->getName() << ": has not been declared." << endl;
            return;
        }
    }
    else if (isnumber(bt->getName()))
        bt->setValue(stod(bt->getName()) * bt->getSign());
    else if (isfunction(bt->getName()))
    {
        lp = bt->getName().find("(");
        fname = bt->getName().substr(0, lp - 0);
        vname = bt->getName().substr(++lp, 1);
        bt->setValue(eval_func(_funct[fname]->_f_rhs, vname));
    }
    else if (is_matrix(bt->getName()))
    {
        bt->_mat = new Matrix();
        bt->_mat->tomatrix(bt->getName());
        *(bt->_mat) = *bt->_mat * bt->getSign();
    }
    else if (iscomplex(bt->getName()))
        bt->_com = new Complex(bt->getName());
}

int SyntaxAnalyzer::eval_func(BTree *bt, string vn)
{
    int res;

    if (bt->_left != NULL)
        eval_func(bt->_left, vn);
    if (isname(bt->getName()))
        _vars_int[bt->getName()] = vn;
    if (bt->_right != NULL)
        eval_func(bt->_right, vn);
    res = eval_exp(bt, vn);
    _vars_int.erase(bt->getName());
    return (res);
}

int SyntaxAnalyzer::eval_exp(BTree *&bt, string v)
{
    int res;

    if (bt->_left != NULL)
        eval_exp(bt->_left, v);
    getVal(bt);
    if (bt->_right != NULL)
        eval_exp(bt->_right, v);
    if (isop(bt->getName()))
    {
        if (bt->getName() == "^")
        {
            if (bt->_left && bt->_right)
            {
                res = bt->pow(bt->_left->getValue(), bt->_right->getValue());
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "+")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left + *bt->_right;
                bt->setValue(res);
            }            
        }
        else if (bt->getName() == "-")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left - *bt->_right;
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "*")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left * *bt->_right;
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "/")
        {
            if (bt->_left && bt->_right)
            {
                if (bt->_right->getValue() != 0)
                {
                    res = *bt->_left / *bt->_right;
                    bt->setValue(res);
                }
                else
                cout << "Error: InvalidOperandException" << endl;
            }
        }
    }
    return (bt->getValue());
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
        if (bt->getName() == "^")
        {
            if (bt->_left && bt->_right)
            {
                res = bt->pow(bt->_left->getValue(), bt->_right->getValue());
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "+")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left + *bt->_right;
                bt->setValue(res);
            }            
        }
        else if (bt->getName() == "-")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left - *bt->_right;
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "*")
        {
            if (bt->_left && bt->_right)
            {
                res = *bt->_left * *bt->_right;
                bt->setValue(res);
            }
        }
        else if (bt->getName() == "/")
        {
            if (bt->_left && bt->_right)
            {
                if (bt->_right->getValue() != 0)
                {
                    res = *bt->_left / *bt->_right;
                    bt->setValue(res);
                }
                else
                cout << "Error: InvalidOperandException" << endl;
            }
        }
    }
    return (bt->getValue());
}

Matrix *SyntaxAnalyzer::matrix_eval(BTree *&bt)
{
    if (bt->_left != NULL)
        matrix_eval(bt->_left);
    getVal(bt);
    if (bt->_right != NULL)
        matrix_eval(bt->_right);
    if (isop(bt->getName()))
    {
        bt->_mat = new Matrix();
        if (bt->getName() == "+")
            *(bt->_mat) = *bt->_left->_mat + *bt->_right->_mat;
        else if (bt->getName() == "**")
            *(bt->_mat) = *bt->_left->_mat | *bt->_right->_mat;
        else if (bt->getName() == "*")
        {
            if (ismatrix(bt->_left->getName()))
                *(bt->_mat) = *bt->_left->_mat * bt->_right->getValue();
            else
                *(bt->_mat) = *bt->_right->_mat * bt->_left->getValue();
        }        
    }
    return (bt->_mat);
}

Complex *SyntaxAnalyzer::complex_eval(BTree *&bt)
{
    if (bt->_left != NULL)
        complex_eval(bt->_left);
    getVal(bt);
    if (bt->_right != NULL)
        complex_eval(bt->_right);
    if (isop(bt->getName()))
    {
        bt->_com = new Complex();
        if (bt->getName() == "+")
        {
            if (bt->_left->_com == NULL)
                bt->_left->_com = new Complex(to_string(bt->_left->getValue()));
            if (bt->_right->_com == NULL)
                bt->_right->_com = new Complex(to_string(bt->_right->getValue()));
            *(bt->_com) = *bt->_left->_com + *bt->_right->_com;
        }
        else if (bt->getName() == "*")
        {
            if (iscomplex(bt->_left->getName()) || iscomplex(bt->_right->getName()))
            {
                if (bt->_left->_com == NULL)
                    bt->_left->_com = new Complex(to_string(bt->_left->getValue()));
                if (bt->_right->_com == NULL)
                    bt->_right->_com = new Complex(to_string(bt->_right->getValue()));
                *(bt->_com) = *bt->_left->_com * *bt->_right->_com;
            } else
            {
                if (bt->_left->_com == NULL)
                    bt->_left->_com = new Complex(to_string(bt->_left->getValue()));
                if (bt->_right->_com == NULL)
                    bt->_right->_com = new Complex(to_string(bt->_right->getValue()));
                *(bt->_com) = *bt->_left->_com * *bt->_right->_com;
            }
        }
    }
    return (bt->_com);
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