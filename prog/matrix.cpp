#include "matrix.h"
#include "math_funcs.h"
#include <iomanip>

bool readMatrix(std::istream& in, Matrix& a, int& n)
{
    if (!(in >> n))
        return false;

    if (n < 1 || n > MAX_N)
        return false;

    a.assign(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!(in >> a[i][j]))
                return false;

    return true;
}

void printMatrix(std::ostream& out, const Matrix& a, const std::string& title)
{
    out << title << '\n';
    for (const auto& row : a) {
        for (int value : row)
            out << std::setw(6) << value;
        out << '\n';
    }
    out << '\n';
}

bool onSecondaryDiagonal(int i, int j, int n)
{
    return i + j == n - 1;
}

bool belowSecondaryDiagonal(int i, int j, int n)
{
    return i + j > n - 1;
}

long long sumSecondaryDivisibleBy3(const Matrix& a)
{
    const int n = static_cast<int>(a.size());
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        int j = n - 1 - i;
        if (onSecondaryDiagonal(i, j, n) && isDivisibleBy3(a[i][j]))
            sum += a[i][j];
    }
    return sum;
}

void replaceBelowSecondary(Matrix& a)
{
    const int n = static_cast<int>(a.size());

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (belowSecondaryDiagonal(i, j, n))
                a[i][j] = static_cast<int>(sumDigits(a[i][j]));
}