/*
 * Author: Devin Gendron
 * Assignment: Homework 8
 * Date Due: August 16th - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
        leftVector.push_back(data[low + i]);
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
// CITATION: http://jeffe.cs.illinois.edu/teaching/algorithms/notes/31-approx.pdf
// CITATION: https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/
// CITATION: https://en.wikipedia.org/wiki/Bin_packing_problem
// CITATION: http://bastian.rieck.ru/uni/bin_packing/bin_packing.pdf
/*
 * My attempr at First_Fit algorithm.
 */


/*struct Bin {
    int cap = 0;
    int current = 0;
    int counter = 1;
};

int First_Fit(int weights[], Bin b, int item_num) {
    //iterate through weights
    for (int i = 0; i < item_num; i++) {
        int j;
        //if bin can be filled, fill.  Otherwise fill next bin.
        for (j = 0; j < b.counter; j++) {
            if (b.current >= weights[i]) {
                b.current = b.current - weights[i];
                break;
            }
        }
        //If bins full, create new bin
        if (j == b.counter) {
            b.current = b.cap - weights[i];
            b.counter++;
        }
    }
    //return number of bins
    return b.counter;
}*/
/*int First_Fit(int weights[], int bin_cap, int item_num)
{
    int bins = 0;
    int space[item_num];

    for(int i = 0; i < item_num; i++)
    {
        int j = 0;
        bool item_found = false;

        while(j < bins && item_found == false)
        {
            if(space[j] >= weights[i])
            {
                space[j] = space[j] - weights[i];
                item_found = true;
            }
            j++;
        }
        if(j == bins)
        {
            bins++;
            space[bins] = weights[i];
        }
    }

    return bins;
}*/
// CITATION: http://jeffe.cs.illinois.edu/teaching/algorithms/notes/31-approx.pdf
// CITATION: https://www.geeksforgeeks.org/bin-packing-problem-minimize-number-of-used-bins/
// CITATION: https://en.wikipedia.org/wiki/Bin_packing_problem
// CITATION: http://bastian.rieck.ru/uni/bin_packing/bin_packing.pdf
/*
 * I was unable to get my above attempt working properly and utilized the this solution below
 * using my references.
 */
int First_Fit(int weights[], int bin_size, int item_num) {
    //initialize bins
    int bins = 0;
    //initialize space per bin
    int space[item_num];

    //iterate through weights
    for (int i = 0; i < item_num; i++) {
        int j;
        //if bin can be filled, fill.  Otherwise fill next bin.
        for (j = 0; j < bins; j++) {
            if (space[j] >= weights[i]) {
                space[j] = space[j] - weights[i];
                break;
            }
        }
        //If bins full, create new bin
        if (j == bins) {
            space[bins] = bin_size - weights[i];
            bins++;
        }
    }
    //return number of bins
    return bins;
}

int main() {
    // File Entry
    std::string fileName;
    std::cout << "Accessing bin.txt file..." << std::endl;
    fileName= "bin.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW8BinPacking/binEC.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    int FF_Counter = 0;
    int FFD_Counter = 0;
    int tie = 0;

    if(inputFile.fail())
    {
        std::cout << "bin.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail())
    {
        std::cout << "bin.txt Opened - Reading..." << std::endl;

        //variables
        int tests = 0;
        int counter = 0;
        int bin_capacity = 0;
        int item_num = 0;
        int ans1 = 0;
        int ans2 = 0;

        //read number of tests
        inputFile >> tests;

        do{
            //set values for tests
            inputFile >> bin_capacity;
            inputFile >> item_num;
            int weights[item_num];

            //fill weights
            for(int i = 0; i < item_num; i++)
            {
                inputFile >> weights[i];
            }

            //run first test case
            std::cout << "Running Test Case " << counter + 1 << " - First Fit" << std::endl;
            ans1 = First_Fit(weights, bin_capacity, item_num);

            /////////testttttttt
            //struct Bin b;
            //b.cap = bin_capacity;
            //std::cout << "Running Test Case " << counter + 1 << " - First Fit" << std::endl;
            //ans1 = First_Fit(weights, b, item_num);


            //run second test case (decreasing)
            std::cout << "Running Test Case " << counter + 1 << " - First Fit : Decreasing" << std::endl;
            //Make into vector since my mergesort from prior assignments used vectors
            std::vector<int> toSort;
            for(int i = 0; i < item_num; i++)
            {
                toSort.push_back(weights[i]);
            }

            // Setup for Merge Sort
            int low = 0;
            int high = item_num - 1;

            //merges ort
            mergeSort(toSort, low, high);

            //set weights in decreasing order
            int x = 0;
            for(int i = item_num - 1; i >= 0; i--)
            {
                weights[x] = toSort[i];
                x++;
            }
            toSort.erase(toSort.begin(), toSort.end());

            //actual run
            ans2 = First_Fit(weights, bin_capacity, item_num);

            //print results
            std::cout << "Test Case " << counter + 1 << " - First Fit: " << ans1 << std::endl;
            std::cout << "Test Case " << counter + 1 << " - First Fit : Decreasing: " << ans2 << std::endl;
            //increment test counter
            counter++;
            //summarizing counters
            if (ans1 == ans2)
            {
                tie++;
            }
            else if(ans1 > ans2)
            {
                FFD_Counter++;
            }
            else if(ans1 < ans2)
            {
                FF_Counter++;
            }
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
        }while(counter != tests);
    }

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "First Fit Wins: " << FF_Counter << std::endl;
    std::cout << "First Fit Decreasing Wins: " << FFD_Counter << std::endl;
    std::cout << "Ties: " << tie << std::endl;

    std::cout << "Bin Packing Program Ending" << std::endl;

    return 0;
}