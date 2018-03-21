/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include "Iterative.h"
#include "Recursive.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "InputValidation.h"

///Please note: code is sourced from:
/// https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
/// and: http://www.cplusplus.com/reference/ctime/clock/

void Usage()
{
    std::cout << "Correct usage: " << std::endl;
    std::cout << "./Fibonacci [n]" << std::endl;
}

int frequency_of_primes (int n) {
    int i,j;
    int freq=n-1;
    for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
    return freq;
}

int main(int argc, char** args)
{
    try {
        const char* input;
        if(args[1] != 0)
        {
            std::cout << "1st passed argument: '" << args[1] << "'" << std::endl;
        }

        int n = 0;

        std::cout << "Please enter a number between 0 and 45" << std::endl;
        n = InputValidation();

        std::cout << "Finding '" << n << "'th Fibonacci Number..." << std::endl;
        std::cout << std::endl;

        ///recursive
        std::cout << "Calling Recursive Fibonacci implementation" << std::endl;
        Recursive rec(n);

        clock_t t;
        t = clock();
        printf ("Calculating...\n");
        rec.PrintRecursive();
        t = clock() - t;
        printf ("It took me %d clicks (%f seconds) for recursion.\n",t,((float)t)/CLOCKS_PER_SEC);

        std::cout << std::endl;


        ///iterative
        std::cout << "Calling Non-Recursive Fibonacci implementation." << std::endl;
        Iterative it(n);

        clock_t tt;
        tt = clock();
        printf ("Calculating...\n");
        it.PrintIterative();
        tt = clock() - tt;
        printf ("It took me %d clicks (%f seconds) for recursion.\n",tt,((float)tt)/CLOCKS_PER_SEC);

        std::cout << std::endl;
        std::cout << "Done" << std::endl;

        return 0;
    }
    catch(...)
    {
        std::cout << "error occurred" << std::endl;
        Usage();
        return 1;
    }

}