/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/

#include "Iterative.h"
#include <iostream>

///Please note: code is sourced from:
/// https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

Iterative::Iterative() {}

Iterative::Iterative(const int &n) : n_(&n) {}

Iterative::~Iterative() {}

int Iterative::IterativeNR(const int &n)
{
    int first = 0;
    int second = 1;
    int counter = 2;
    while (counter < n)
    {
        int temp = second;
        second = first + second;
        first = temp;
        ++counter;
    }
    if (n == 0)
        return 0;
    else
        return first+second;
}
void Iterative::PrintIterative()
{
    const int result = IterativeNR(*n_);
    std::cout << *n_ << "th fibonacci Number: " << result << std::endl;
}