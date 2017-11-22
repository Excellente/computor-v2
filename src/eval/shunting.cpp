#include "eval/shunting.hpp"

stack<SToken> Shunting::shuntingYard(Maps _tkns)
{
    SToken st;
    string tmp;
    stack<SToken> lstack;
    stack<SToken> rstack;
    stack<SToken> opstack;

    while (1)
    {
        if ((tmp = _tkns.getNextToken()) == _EOF_) break;
        if (isop(tmp) || tmp == "(")
        {
            st = SToken(true, tmp);
            opstack.push(st);
        }
        else if (tmp == ")")
        {
            while ((st = opstack.top()).getValue() != "(" && !opstack.empty())
            {
                opstack.pop();
                lstack.push(st);
            }
            opstack.pop();
        } else {
            st = SToken(false, tmp);
            lstack.push(st);
        }
    }
    while (!opstack.empty())
    {
        lstack.push(opstack.top());
        opstack.pop();
    }
    while (!lstack.empty())
    {
        rstack.push(lstack.top());
        lstack.pop();
    }
    return (rstack);
}