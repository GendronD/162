/*********************************************
 * Author: Devin Gendron
 * Date: 9/27/17
 * Description: Celsius to farenheit converter.
 * ********************************************/

#include <iostream>
#include <string>

//variables
float celsius, fahrenheit;

int main()
{
        //ask for celsius
        std:: cout << "Please enter a Celsius temperature." << std:: endl;

        //input celsius
        std:: cin >> celsius;

        //conversion of celsius to fahrenheit   
        fahrenheit = ( ( 9 / (float) 5 ) * celsius ) + 32;

        //statement & output 
        std:: cout << "The equivalent Fahrenheit temperature is:" << std:: endl << fahrenheit;

        return 0;

}

