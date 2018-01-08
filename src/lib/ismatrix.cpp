#include "common.hpp"

bool ismatrix(string s)
{
    regex rm("\\[\\[([0-9]+(,[0-9]+)*?)?\\](;\\[[0-9]+(,[0-9]+)*?\\])*?\\]");

    return (regex_match(s, rm));
}