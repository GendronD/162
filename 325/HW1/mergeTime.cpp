/*
 * Author: Devin Gendron
 * Assignment: Homework 1 - Question 5: MergeSort
 * Date Due: July 1st - 11:59PM
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <time.h>


//CITATION: Introduction to Algorithms (CLRS) pg 31 (Chpt 2).
//CITATION: https://www.geeksforgeeks.org/merge-sort/
void merge(std::vector<int> &data, int low, int mid, int high) {
    //set variables
    int i, j, k;

    //determine vector sizes
    int vector1Size = mid - low + 1;
    int vector2Size = high - mid;

    //create temp arrays with sizes
    std::vector<int> leftVector;
    std::vector<int> rightVector;

    //input data from initial vectors into left and right vectors
    for(i = 0; i < vector1Size; i++) {
        leftVector.push_back(data[low+ i]);
    }
    for(j = 0; j < vector2Size; j++) {
        rightVector.push_back(data[mid + 1 + j]);
    }

    //initial indexes
    i = 0;
    j = 0;
    k = low;

    //collect values back into data
    while(i < vector1Size && j < vector2Size) {
        if(leftVector[i] <= rightVector[j]) {
            data[k] = leftVector[i];
            i++;
        } else {
            data[k] = rightVector[j];
            j++;
        }
        k++;
    }

    //check for any left from leftVector
    while(i < vector1Size) {
        data[k] = leftVector[i];
        i++;
        k++;
    }

    //check for any left from rightVector
    while(j < vector2Size) {
        data[k] = rightVector[j];
        j++;
        k++;
    }
}

//CITATION: Introduction to Algorithms (CLRS) pg 34 (Chpt 2).
void mergeSort(std::vector <int> &data, int low, int high) {
    if(low < high) {
        int mid;
        mid = (low + (high - 1)) / 2;

        mergeSort(data, low, mid);
        mergeSort(data, mid+1, high);
        merge(data, low, mid, high);
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

    //setup for mergesort
    int low = 0;
    int high = num_to_sort - 1;

    std::cout << "MergeSort Commencing" << std::endl;


    /*std::cout << "Before MergeSort: " << std::endl;
    for(int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ", ";
    }*/

    //CITATION: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
    //start clock
    clock_t begin = clock();

    //implement mergesort code here
    mergeSort(data, low, high);

    //end clock
    clock_t end = clock();

    //compute time
    runtime = (double)(end - begin) / CLOCKS_PER_SEC;

    /*std::cout << "After MergeSort: " << std::endl;
    for(int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ", ";
    }*/
    std::cout << "MergeSort Complete" << std::endl;

    //print data
    std::cout << "n = " << num_to_sort << std::endl;
    std:: cout << "Merge Sort RunTime: " << runtime << std::endl;
    std::cout << "" << std::endl;
    std::cout << "MergeSort Read and Write Program Ending" << std::endl;

    return 0;
}