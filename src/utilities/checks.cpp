#include "checks.h"

using namespace std;

bool isNumber(string& str)
{
    int size = str.size();
    for (int i = 0; i < size; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}

