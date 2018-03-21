/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/

#ifndef ALGORITHMS_EFFICIENCY_RECURSIVE_H
#define ALGORITHMS_EFFICIENCY_RECURSIVE_H

///Please note: code is sourced from:
/// https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

class Recursive {
private:
    Recursive();
    //int recursion(const int &n);
    const int *n_;
protected:
public:
    Recursive(const int &n);
    virtual ~Recursive();
    int recursion(const int &n);
    void PrintRecursive();
};


#endif //ALGORITHMS_EFFICIENCY_RECURSIVE_H
