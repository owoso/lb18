#include "math_funcs.h"

long long sumDigits(long long number)
{
    if (number < 0)
        number = -number;

    if (number < 10)
        return number;

    return number % 10 + sumDigits(number / 10);
}

bool isDivisibleBy3(long long number)
{
    return number % 3 == 0;
}