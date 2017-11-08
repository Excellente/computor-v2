#include "polynom/computor.hpp"

Computor::Computor(string exp) : _exp(exp){
    vector<string> ret;

    ret = strsplit("=");
    _sol1 = 0;
    _sol2 = 0;
    _sol3[0] = '\0';
    _sol4[0] = '\0';
    _h_power = 0;
    _reduced = "";
    _lhs = ret[0];
    _rhs = ret[1];
}

Computor::~Computor(){
}

Computor &Computor::operator=(const Computor &rhs)
{
    this->_lhs = rhs._lhs;
    this->_rhs = rhs._rhs;
    return (*this);
}

void Computor::toString()
{
    int len = count_terms(_exp_terms);

    printTerms(_exp_terms);
    cout << endl;
}

void Computor::solvepoly()
{
    transpose();
    addLikeTerms();
    find_ABC();
    if (_h_power == 1)
        solvelinear();
    else if (_h_power == 2)
        quadraticForm();
    output();
}

void Computor::transpose()
{
    int sign;

    sign = 0;
    stringToTerm(_lhs, sign, 0);
    sign = 0;
    stringToTerm(_rhs, sign, 1);
}

void Computor::stringToTerm(string _e, int &sign, int f)
{
    Term *t;
    int last;
    int first;
    string tmp;
    
    last = first = 0;
    while (_e[last] != '\0')
    {
        _sign(_e, last, sign);
        if (f == 1)
        {
            if (sign == 1)
                sign = 0;
            else
                sign = 1;
        }
        t = new Term(sign);
        getTerm(_e, tmp, last, first);
        assign_term(tmp, t);
        _exp_terms.push_back(*t);
    }
}

void Computor::getTerm(string p, string &t, int &last, int &first)
{
    regex rg("(\\s+)?((-|\\+)(\\s+)?)?[[:digit:]]+(\\.[[:digit:]]+)?(\\s\\*\\s)(X|x)(\\s)?(\\^(\\s)?[[:digit:]]+)(\\s+)?");
    
    while (p[last] != '+' && p[last] != '-' && p[last] != '\0')
        last++;
    t = p.substr(first, last - first);
    if (p[last] != '\0')
        last++;
    first = last;
    if (!regex_match(t, rg))
    {
        cout << t << endl;
        cerr << "Error: InvalidTermFormat\n";
        exit(EXIT_FAILURE);
    }
}

void Computor::_sign(string &_e, int &last, int &sign)
{
    if (last > 0)
    {
        if (_e[last - 1] == '+')
            sign = 0;
        else if (_e[last - 1] == '-')
            sign = 1;
    }
    else
        lead_sign(_e, sign, last);
}

void Computor::lead_sign(string &p, int &_sign, int &last)
{
    int numsign;
    
    while (!(p[last] >= 48 && p[last] <= 57) && p[last] != '\0')
    {
        if (p[last] == '+' || p[last] == '-')
        {
            if (p[last] == '-')
                _sign = 1;
            else
                _sign = 0;
            if ((numsign += 1) > 1)
                _err = 1;
            
        }
        last++;
    }
    p = p.substr(last, string::npos);
}

void Computor::assign_term(string p, Term *t)
{
    string::size_type sz;

    t->setCoefficient(stof(p, &sz));
    sz = p.find("^") + 1;
    while (p[sz] == ' ') sz++;
    t->setExponent(stof(p.substr(sz, 4), &sz));
    sz = p.find("^") - 1;
    while (p[sz] == ' ') sz--;
    t->setBase(p.substr(sz, 2)[0]);
}

bool Computor::ignore(vector<float> del, float _exp)
{
    vector<float>::iterator bvi = del.begin();
    vector<float>::iterator evi = del.end();

    for (; bvi != evi; bvi++)
    {
        if (_exp == *bvi)
            return (true);
    }
    return (false);
}

void Computor::addLikeTerms()
{
    vector<Term> lt;
    vector<float> ig;
    v_iter_t evi = _exp_terms.end();
    v_iter_t bvi = _exp_terms.begin();

    for (; bvi != evi;)
    {
        if (!ignore(ig, bvi->getExponent()))
        {
            reduce(lt, bvi, evi);
            ig.push_back(bvi->getExponent());
        }
        bvi++;
    }
    _exp_terms = lt;
}

void Computor::find_ABC()
{
    float _sign;
    float expo;
    float coeff;
    float tmpabc[3] = {0.0f, 0.0f, 0.0f};
    v_iter_t evi = _exp_terms.end();
    v_iter_t bvi = _exp_terms.begin();

    for (; bvi != evi; bvi++)
    {
        _sign = 1;
        if (bvi->getSign() == 1)
            _sign *= -1;
        expo = bvi->getExponent();
        coeff = bvi->getCoefficient();
        if (expo == 0)
            tmpabc[0] = coeff * _sign;
        else if (expo == 1)
            tmpabc[1] = coeff * _sign;
        else if (expo == 2)
            tmpabc[2] = coeff * _sign;
        if (_h_power < bvi->getExponent() && bvi->getCoefficient() != 0)
            _h_power = bvi->getExponent();
    }
    for (int i = 0; i < 3; i++)
        _CBA.push_back(tmpabc[i]);
}

void Computor::solvelinear()
{
    float c = _CBA[0] * -1;
    float b = _CBA[1];

    _sol1 = c / b;
}

void Computor::quadraticForm()
{
    float negb;
    float rootd;
    float denom;

    _discrimi = pow(_CBA[1], 2.0f) - 4 * _CBA[2] * _CBA[0];
    negb = -_CBA[1];
    rootd = __sqrt(_discrimi);
    denom = 2 * _CBA[2];
    if (_discrimi > 0)
    {
        _sol1 = (negb + rootd) / denom;
        _sol2 = (negb - rootd) / denom;
    }
    else if (_discrimi == 0)
        _sol1 = negb / denom;
    else if (_discrimi < 0)
    {
        // sprintf(_sol3, "%.3f / %f  + i%f", negb, denom, sqrt((_discrimi * -1)) / denom);
        // sprintf(_sol4, "%.3f / %f  - i%f", negb, denom, sqrt((_discrimi * -1)) / denom);
    }
    else;
}

void Computor::reduce(vector<Term> &lt, v_iter_t bvi, v_iter_t evi)
{
    static int i;
    v_iter_t tmp;
    v_iter_t hit;

    lt.push_back(*bvi);
    for (tmp = bvi + 1; tmp != evi;)
    {
        if (bvi->getExponent() == tmp->getExponent())
        {
            lt[i] += *tmp;
            hit = tmp;
        }
        tmp++;
    }
    // likeTermsVerbose(lt, hit, bvi);
    i++;
}

template <class T>
size_t Computor::count_terms(vector<T> v)
{
    size_t terms;
    typename vector<T>::iterator evi = v.end();
    typename vector<T>::iterator bvi = v.begin();

    terms = 0;
    while (bvi != evi)
    {
        bvi++;
        terms++;
    }
    return (terms);
}

vector<string> Computor::strsplit(string del)
{
    int len;
    size_t pos;
    vector<int> delpos;
    vector<string> terms;

    len = 0;
    for (int i = 0; i != string::npos;)
    {
        delpos.push_back((i = _exp.find(del, i + 1)));
        len++;
    }
    terms.push_back(_exp.substr(0, delpos[0]));
    for (int i = 1; i < len; i++)
        terms.push_back(_exp.substr(delpos[i - 1] + 1, (delpos[i] - delpos[i - 1]) - 1));
    return (terms);
}

float Computor::_sqrt(float n)
{
    float sqr = 4;
    float guess;

    guess = find_closestsqrt(10);
    for (int i = 0; 1; i++)
    {
        improve(guess, sqr);
        if (isGoodEnough(sqr, guess))
            break ;
    }
    return (0);
}

float Computor::_pow(float b, float e)
{
    float res = 1;

    for (int i = 0; i < e; i++)
        res *= b;
    return (res);
}

float Computor::improve(float &g, float x)
{
    g = ((x / g) + g) / 2;
    return (g);
}

bool Computor::isGoodEnough(float sqr, float guess)
{
    if (sqr - (guess * guess) < 0.001)
        return (true);
    return (false);
}

float Computor::find_closestsqrt(float n)
{
    return ((n / 2) - 2);
}

void Computor::printTerms(vector<Term> v)
{
    int len = count_terms(v);

    for (int j = 0; j < len; j++)
        v[j].toString(j);
}

void Computor::debugmode(string debug)
{
    int len = count_terms(_CBA);

    cout <<"========== Entered debug mode ==========" << endl;
    if (debug.compare("-d") == 0)
        cout << "discriminant = " <<_discrimi << endl;
    else if (debug.compare("-abc") == 0)
    {
            cout
                << "a = " << _CBA[2]
                << ", b = " << _CBA[1]
                << ", c = " << _CBA[0] <<
            endl;

    }
    else if (debug.compare("-dabc") == 0)
    {
        cout << "discriminant = " <<_discrimi << endl;
        cout
            << "a = " << _CBA[2]
            << ", b = " << _CBA[1]
            << ", c = " << _CBA[0] <<
        endl;
    }
    else
        cout << "ERROR: Debug text " << debug << endl;
}

void Computor::output()
{
    string tmp;
    v_iter_t evi = _exp_terms.end();
    v_iter_t bvi = _exp_terms.begin();
    float negb;
    float rootd;
    float denom;

    _discrimi = pow(_CBA[1], 2.0f) - 4 * _CBA[2] * _CBA[0];
    negb = -_CBA[1];
    rootd = sqrt(_discrimi);
    denom = 2 * _CBA[2];
    cout << "Reduced Form: ";
    for (; bvi != evi; bvi++)
    {
        if (bvi == _exp_terms.begin())
            bvi->toString(0);
        else
            bvi->toString(1);
    }
    cout << " = 0" << endl;
    cout << "Polynomial Degree: " << _h_power << endl;
    if (_h_power == 0 && _exp_terms[0].getCoefficient() == 0)
        cout << "The solution is:\nX ∈ ℝ\n";
    else if (_h_power == 0 && _exp_terms[0].getCoefficient() != 0)
        cout << "No Solution\n";
    else if (_h_power == 1)
        cout << "The Solution is:\n" << _sol1 << endl;
    else if (_h_power == 2)
    {
        if (_discrimi > 0)
        {
            cout << "The Solutions are: " << endl;
            cout << _sol1 << "\n" << _sol2 << endl;
        }
        else if (_discrimi == 0)
            cout << "The Solution is:\n" << _sol1 << endl;
        else
        {
            cout << "The Solutions are: " << endl;
            sprintf(_sol3, "%.3f / %f  + i%f", negb, denom, sqrt((_discrimi * -1)) / denom);
            cout << _sol3 << endl;
            sprintf(_sol3, "%.3f / %f  - i%f", negb, denom, sqrt((_discrimi * -1)) / denom);
            cout << _sol3 << endl;
        }
    }
    else if (_h_power > 2)
        cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;

}