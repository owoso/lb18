#include "matrix.h"
#include "math_funcs.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    Matrix a;
    int n = 0;
    bool ok = false;

    if (argc > 1) {
        std::ifstream fin(argv[1]);
        if (!fin) {
            std::cerr << "Error: cannot open file " << argv[1] << '\n';
            return 1;
        }
        ok = readMatrix(fin, a, n);
    } else {
        std::cout << "Enter n (1.." << MAX_N << ") and "
                  << "n*n integer elements:\n";
        ok = readMatrix(std::cin, a, n);
    }

    if (!ok) {
        std::cerr << "Error: invalid input data "
                  << "(n must be 1.." << MAX_N
                  << ", need n*n integers)\n";
        return 1;
    }

    printMatrix(std::cout, a, "Input matrix:");

    long long sum = sumSecondaryDivisibleBy3(a);
    std::cout << "Sum of secondary-diagonal elements divisible by 3 = "
              << sum << "\n\n";

    replaceBelowSecondary(a);

    printMatrix(std::cout, a, "Result matrix:");
    return 0;
}