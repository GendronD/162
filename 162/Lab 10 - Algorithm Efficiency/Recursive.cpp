/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/

#include "Recursive.h"
#include <iostream>
///Please note: code is sourced from:
/// https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

Recursive::Recursive() {}

Recursive::Recursive(const int &n) : n_(&n) {}

Recursive::~Recursive() {}

int Recursive::recursion(const int &n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    return recursion(n-1) + recursion(n-2);
}
void Recursive::PrintRecursive()
{
    int RecNum = recursion(*n_);
    std::cout << *n_ << "th fibonacci number: " << RecNum << std::endl;
}