#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

const int MAX_N = 100;

bool readMatrix(std::istream& in, Matrix& a, int& n);
void printMatrix(std::ostream& out, const Matrix& a, const std::string& title);
bool onSecondaryDiagonal(int i, int j, int n);
bool belowSecondaryDiagonal(int i, int j, int n);
long long sumSecondaryDivisibleBy3(const Matrix& a);
void replaceBelowSecondary(Matrix& a);

#endif // MATRIX_H