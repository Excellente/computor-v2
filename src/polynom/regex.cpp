#include <iostream>
#include <regex>
#include <string>

using namespace std;

float _pow(float b, float e)
{
    float res = 1;

    for (int i = 0; i < e; i++)
        res *= b;
    return (res);
}

float improve(float &g, float x)
{
    g = ((x / g) + g) / 2;
    return (g);
}

bool isGoodEnough(float sqr, float guess)
{
    if (sqr - (guess * guess) < 0.001)
        return (true);
    return (false);
}

float find_closestsqrt(float n)
{
    return ((n / 2));
}

int main(int ac,  char *av[])
{
    float sqr = 4;
    float guess;
    // string input;
    // regex rg("((\\s+)?(-|\\+)(\\s+)?)?[[:digit:]]+(\\.[[:digit:]]+)?(\\s\\*\\s)(X|x)(\\^[[:digit:]]+)");

    // if (regex_match(av[1], rg))
    //     cout << "sequence matched\n";
    // else
    //     cout << "unknown sequence\n";
    guess = find_closestsqrt(10);
    for (int i = 0; 1; i++)
    {
        improve(guess, sqr);
        if (isGoodEnough(sqr, guess))
            break ;
        // cout << guess<< endl;
    }
    cout << guess << endl;
    return (0);
}