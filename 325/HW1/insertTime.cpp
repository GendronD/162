/*
 * Author: Devin Gendron
 * Assignment: Homework 1 - Question 5: Insertion Sort
 * Date Due: July 1st - 11:59PM
 */
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <time.h>

//CITATION: Introduction to Algorithms (CLRS) pg 26 (Chpt 2).
void insertSort(std::vector<int> &data, int num_to_sort) {
    //vector successfully in function
    int key;
    int i;

    for(int j = 2; j < num_to_sort; j++) {
        key = data[j];
        i = j - 1;

        while (i >= 0 && data[i] > key) {
            data[i+1] = data[i];
            i = i - 1;
        }
        data[i+1] = key;
    }
}

int main() {
    //set for randomized numbers
    srand(time(NULL));

    //variables
    std::vector <int> data;
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
                    data.push_back(random);
                    //std::cout << "data = " << data[i] << std::endl;
                }
                num_to_sort = 5000;
                menu = true;
                break;
            case 2 : //generates 10,000 n
                for(int i = 0; i < 10000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 10000;
                menu = true;
                break;
            case 3 : //generates 15,000 n
                for(int i = 0; i < 15000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 15000;
                menu = true;
                break;
            case 4 : //generates 20,000 n
                for(int i = 0; i < 20000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 20000;
                menu = true;
                break;
            case 5 : //generates 30,000 n
                for(int i = 0; i < 30000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 30000;
                menu = true;
                break;
            case 6 : //generates 40,000 n
                for(int i = 0; i < 40000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 40000;
                menu = true;
                break;
            case 7 : //generates 50,000 n
                for(int i = 0; i < 50000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 50000;
                menu = true;
                break;
            case 8 : //generates 60,000 n
                for(int i = 0; i < 60000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
                }
                num_to_sort = 60000;
                menu = true;
                break;
            case 9 : //generates 70,000 n
                for(int i = 0; i < 70000; i++) {
                    random = (rand() % 10000 + 1);
                    data.push_back(random);
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

    //CITATION: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
    //start clock
    clock_t begin = clock();

    //use insert sort to sort vector
    insertSort(data, num_to_sort);

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