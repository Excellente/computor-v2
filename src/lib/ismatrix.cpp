#include "common.hpp"

bool ismatrix(string s)
{
    regex rm("(\\s+)?\\[(\\s+)?\\[(\\s+)?([0-9]+((\\s+)?,(\\s+)?[0-9]+)?)?(\\s+)?\\]((\\s+)?;(\\s+)?(\\s+)?\\[(\\s+)?[0-9]+((\\s+)?,(\\s+)?[0-9]+)?(\\s+)?\\](\\s+)?)?(\\s+)?\\](\\s+)?");

    return (regex_match(s, rm));
}