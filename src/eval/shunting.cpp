#include "eval/shunting.hpp"

void Shunting::_token_sign(string &tmp, int &inBrace, int &sign)
{
    if (tmp == "(") inBrace += 1;
    if (tmp == ")") inBrace -= 1;
    if (tmp == "-")
    {
        tmp = "+";
        if (inBrace > 0)
        {
            if (sign == -1)
                sign = 1;
            else
                sign = -1;
        }
        if (inBrace == 0) sign = -1;
    }
    else if (tmp == "+")
    {
        if (!inBrace && sign == -1)
            sign = 1;
    }
}

stack<SToken> Shunting::shuntingYard(Maps _tkns)
{
    SToken st;
    string tmp;
    int sign = 1;
    int inBrace = 0;
    string str = "";
    stack<SToken> lstack;
    stack<SToken> rstack;
    stack<SToken> opstack;
    map<string, int> o_pre;

    o_pre["="] = 0;
    o_pre["+"] = 1;
    o_pre["-"] = 1;
    o_pre["*"] = 2;
    o_pre["/"] = 3;
    o_pre["%"] = 4;
    o_pre["^"] = 5;
    while (1)
    {
        if ((tmp = _tkns.getNextToken()) == _EOF_) break;
        _tkns.check_funct(tmp);
        if (isop(tmp) || tmp == "(")
        {
            _token_sign(tmp, inBrace, sign);
            st = SToken(true, tmp);
            if (isop(tmp))
            {
                if (!opstack.empty())
                    str = opstack.top().getValue();
                while (!opstack.empty() && str != "(" &&
                       o_pre[tmp] < o_pre[str])
                {
                    lstack.push(opstack.top());
                    opstack.pop();
                    if (!opstack.empty())
                        str = opstack.top().getValue();
                }
            }
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
        } else if (isname(tmp) || isnumber(tmp) || isfunction(tmp) || tmp == "?") {
            st = SToken(false, tmp);
            st.setSign(sign);
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