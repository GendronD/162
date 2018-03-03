/*****************************************************************************************
 * Author: Devin Gendron
 * Date: 9/27/17
 * Description: Output of the number of change from a given number of cents from 0 to 99.
 * ***************************************************************************************/

#include <iostream>
#include <string>

//variables for change
int cents, Q, D, N, P;
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

int main()
{
        //statement
        std:: cout << "Please enter an amount in cents less than a dollar." << std:: endl;

        //input
        std:: cin >> cents;

        //calculations for change
        Q = cents/quarter;
        D = (cents%quarter)/dime;
        N = ((cents%quarter)%dime)/nickel;
        P = (((cents%quarter)%dime)%nickel)/penny;

        //output
        std:: cout << "Your change will be:" << std:: endl;
        std:: cout << "Q: " << Q << std:: endl;
        std:: cout << "D: " << D << std:: endl;
        std:: cout << "N: " << N << std:: endl;
        std:: cout << "P: " << P << std:: endl;

        return 0;
}
