/*
 * Author: Devin Gendron
 * Assignment: Homework 2 - Question 5: Stooge Sort
 * Date Due: July 8st - 11:59PM
 */
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <time.h>

/*CITATION:: Discussions in our group chat helped me understand how to fully implement stooge sort
             as well as the pseudocode.
 */
/*CITATION:: https://www.geeksforgeeks.org/stooge-sort/
 * This citation was used when I hit a wall with stoogeSort.  For some reason, my data would be
 * returned unsorted.  I commented out the function and just swapped some elements and when I
 * tested my code, the values were swapped.  Thus, I knew there was an error with stoogeSort.
 * I eventually realized the error was with my m variable.  I originally attempted to use the
 * same version as the pseudocode and this was where I hit the snag.  Using the method used by the
 * link, I could properly ascertain the size of n.  I then used this in my if statements to be consistent.
 */
void stoogeSort(int data[], int start, int end) {
    if(end - start + 1 == 2 && data[start] > data[end]) {
        int temp;
        temp = data[start];
        data[start] = data[end];
        data[end] = temp;
    }
    else if (end - start + 1 > 2) {
        int m;
        //https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
        //m = (2 * end + 1 + 2) / 3;
        m = (end - start + 1) / 3;

        //stoogeSort(data, start, m - 1 + start);
        //stoogeSort(data, end - m + 1, end);
        //stoogeSort(data, start, m - 1 + start);
        stoogeSort(data, start, end - m);
        stoogeSort(data, start + m, end);
        stoogeSort(data, start, end - m);

    }
}

int main() {
    //set for randomized numbers
    srand(time(NULL));

    //variables
    std::vector <int> vec;
    int num_to_sort;
    int choice;
    int random;
    bool menu = false;
    double runtime = 0.0;

    //while loop menu
    while(menu == false) {
        //Print Options
        std::cout << "Please Choose your Preferred Size of n: " << std::endl;
        std::cout << "1. 5,000" << std::endl;
        std::cout << "2. 10,000" << std::endl;
        std::cout << "3. 15,000" << std::endl;
        std::cout << "4. 20,000" << std::endl;
        std::cout << "5. 30,000" << std::endl;
        std::cout << "6. 40,000" << std::endl;
        std::cout << "7. 50,000" << std::endl;
        std::cout << "8. 60,000" << std::endl;
        std::cout << "9. 70,000" << std::endl;

        //read in user input
        std::cin >> choice;

        //fill vector based off user input
        switch(choice) {
            case 1 : //generates 5,000 n
                for(int i = 0; i < 5000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                    //std::cout << "data = " << data[i] << std::endl;
                }
                num_to_sort = 5000;
                menu = true;
                break;
            case 2 : //generates 10,000 n
                for(int i = 0; i < 10000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 10000;
                menu = true;
                break;
            case 3 : //generates 15,000 n
                for(int i = 0; i < 15000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 15000;
                menu = true;
                break;
            case 4 : //generates 20,000 n
                for(int i = 0; i < 20000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 20000;
                menu = true;
                break;
            case 5 : //generates 30,000 n
                for(int i = 0; i < 30000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 30000;
                menu = true;
                break;
            case 6 : //generates 40,000 n
                for(int i = 0; i < 40000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 40000;
                menu = true;
                break;
            case 7 : //generates 50,000 n
                for(int i = 0; i < 50000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 50000;
                menu = true;
                break;
            case 8 : //generates 60,000 n
                for(int i = 0; i < 60000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 60000;
                menu = true;
                break;
            case 9 : //generates 70,000 n
                for(int i = 0; i < 70000; i++) {
                    random = (rand() % 10000 + 1);
                    vec.push_back(random);
                }
                num_to_sort = 70000;
                menu = true;
                break;
            default : //if error
                std::cout << "Error: please choose 1 - 9 only." << std::endl;
                menu = false;
                break;
        }
    }

    std::cout << "InsertionSort Commencing" << std::endl;
    std::cout << "" << std::endl;

    //set array
    int data[num_to_sort];

    //fill array from vector
    for(int i = 0; i < num_to_sort; i++)
    {
        data[i] = vec[i];
    }

    //CITATION: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
    //start clock
    clock_t begin = clock();

    //stooge sort function
    stoogeSort(data, 0, num_to_sort - 1);

    //end clock
    clock_t end = clock();

    //compute time
    runtime = (double)(end - begin) / CLOCKS_PER_SEC;

    //print data
    std::cout << "n = " << num_to_sort << std::endl;
    std:: cout << "Insertion Sort RunTime: " << runtime << std::endl;
    std::cout << "" << std::endl;
    std::cout << "InsertSort Read and Write Program Ending" << std::endl;

    return 0;
}