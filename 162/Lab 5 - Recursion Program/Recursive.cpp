/*********************************************************************
** Program name: Recursive Functions
** Author: Devin Gendron
** Date: 2/11/17
** Description: Recursive Functions: Three separate functions -
** 1. Reverse String, 2. Array Sums, 3. Triangular Num Calculator
*********************************************************************/
#include "Recursive.h"
#include "Menu.h"
#include <string>
#include <iostream>

//1. Reverse String Recursive Function
//http://www.cplusplus.com/reference/string/string/substr/
//https://www.geeksforgeeks.org/stdsubstr-in-ccpp/
/********************************************************************
 * Using substring function, the string is recursively broken into sub
 * strings one smaller than the last.  As the function runs, it
 * builds the call stacks until it reaches the exit condition.
 * At this point, it begins returning each char from the stack until
 * it is back to the beginning of the stack and returns the initial char
 * last. Ex: (Hello! -> !olleH).
 * ******************************************************************/
std::string reverseString(std::string reversed) {
    //int counter = reversed.length() - 1;
    //std::string revString;
    //std::cout << reversed.at(0) << std::endl;
    if (reversed.length() == 0)
    {
        return ""; // the string is empty
    }
    else if (reversed.length() == 1)
    {
        return reversed;
    }
    else
    {
        //return reverseString(reversed.substr(0, reversed.length() - 1)) + reversed.at(0); //not working
        //return reverseString(reversed.substr(0, reversed.length() - 1)) + reversed.at(1); //not working
        //counter--;
        return reverseString(reversed.substr(1, reversed.length() - 1)) + reversed.at(0);   //need to test for endline char
    }
}

//2. Array Sum Recursive Function
/********************************************************************
 * For this recursive summation function, I implemented a similar
 * structure to the reverseString function.  As the function runs,
 * it searches for the end of the array, and then returns once it has
 * reached that point.
 * ******************************************************************/
int arraySum(int *array, int size)
{
    if (size <= 0)
    {
        return 0;
    }
    /*else if (size == 1)
    {
        return array[0];
    }*/
    //return arraySum(array, size - 1) + array[size]; ///FIXXXXXXXXXXXXXXXXXXXXXXX
    return arraySum(array, size - 1) + array[size - 1];
}

//3. Triangular Num Calculator
/********************************************************************
 * Again, this function follows the same concept as the previous two
 * functions. As the function runs, it will run again, smaller by one,
 * until N = 0 and it begins returning.
 * ******************************************************************/
int triangularCalc(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return triangularCalc(n-1) + n;
}

/********************************************************************
 * I struggled with these functions at first, not fully conceptualizing
 * the recursion aspect.  I went through the readings and the lectures
 * and I understood what was occurring within the functions, but had I a
 * hard time implementing it.  After an hour or so of drawing diagrams
 * and watching some more videos online, I was able to properly
 * structure my functions and get them working. (1 and 2 being the
 * hardest for me as I was having some issues at first).
 * ******************************************************************/