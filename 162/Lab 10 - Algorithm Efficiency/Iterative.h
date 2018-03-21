/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/

#ifndef ALGORITHMS_EFFICIENCY_ITERATIVE_H
#define ALGORITHMS_EFFICIENCY_ITERATIVE_H

///Please note: code is sourced from:
/// https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
class Iterative {
    private:
        Iterative();
        //int IterativeNR(const int &n);
        const int* n_;
    protected:
    public:
        Iterative(const int &n);
        virtual ~Iterative();
        int IterativeNR(const int &n);
        void PrintIterative();
};


#endif //ALGORITHMS_EFFICIENCY_ITERATIVE_H
