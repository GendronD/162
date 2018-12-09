/*
 * Author: Devin Gendron
 * Assignment: Homework 4 - Question 4: Activity Selection Last-to-Start
 * Date Due: July 23th - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <ctime>
#include <time.h>

struct Activity {
    int actNum;
    int start;
    int end;
};

//CITATION: Introduction to Algorithms (CLRS) pg 31 (Chpt 2).
//CITATION: https://www.geeksforgeeks.org/merge-sort/
void merge(std::vector<Activity> &data, int low, int mid, int high) {
    //set variables
    int i, j, k;

    //determine vector sizes
    int vector1Size = mid - low + 1;
    int vector2Size = high - mid;

    //create temp arrays with sizes
    std::vector<Activity> leftVector;
    std::vector<Activity> rightVector;

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
        if(leftVector[i].end <= rightVector[j].end) {
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
void mergeSort(std::vector <Activity> &data, int low, int high) {
    if(low < high) {
        int mid;
        mid = (low + (high - 1)) / 2;

        mergeSort(data, low, mid);
        mergeSort(data, mid+1, high);
        merge(data, low, mid, high);
    }
}
// CITATION: https://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
//Citation used to study activity selection in order to formulate my greedy algorithm
void select(std::vector <Activity> toSelect, std::vector <int> &selected)
{
    int j = toSelect.size() - 1;

    selected.push_back(toSelect[j].actNum); // Push last activity into selected list

    //std::cout << "selected: " << toSelect[j].actNum << std::endl;

    j--;
    for(int i = toSelect.size() - 1; i >= 0 && j>= 0; j--)  //loop backwards through activities
    {
        //std::cout << "to select start: " << toSelect[i].start << std::endl;
        //std::cout << "to select end: " << toSelect[j].end << std::endl;

        if(toSelect[i].start >= toSelect[j].end)    //if start of cur activity is greater than or equal to next activity
        {
            selected.push_back(toSelect[j].actNum); //add to selected list
            //std::cout << "selected: " << toSelect[j].actNum << std::endl;
            i = j;  //set new current
        }
    }
}


int main() {
    // Variables
    int read = 0;
    int actSize = 0;
    int set = 0;
    std::vector<int> selected;

    // File Entry
    std::string fileName;
    std::cout << "Accessing act.txt file..." << std::endl;
    fileName= "act.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW4act/act.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    if(inputFile.fail())
    {
        std::cout << "act.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail())
    {
        std::cout << "act.txt Opened - Reading..." << std::endl;

        //do while not at end of file
        do
        {
            inputFile >> read;                  // Read in number of activities for set
            actSize = read;
            struct Activity array[actSize];     // Create array of that size
            int i = 0;
            int looper = actSize;
            set++;

            while (looper != 0) {               // Loop through for number of activities
                inputFile >> read;
                array[i].actNum = read;

                inputFile >> read;
                array[i].start = read;

                inputFile >> read;
                array[i].end = read;

                i++;
                looper--;
            }

            //TEST PURPOSES
            /*for(int i = 0; i < actSize; i++)
            {
                std::cout << "actNum: " << array[i].actNum << " ";
                std::cout << "start: " << array[i].start << " ";
                std::cout << "end: " << array[i].end << " ";
                std::cout << std::endl;
            }*/

            //sort array by actNum to have proper order
            std::vector<Activity> toSort;
            for(int i = 0; i < actSize; i++)
            {
                toSort.push_back(array[i]);
            }

            // Setup for Merge Sort
            int low = 0;
            int high = actSize - 1;

            //Sort activities by latest end time
            mergeSort(toSort, low, high);

            //TEST PURPOSES
            /*for(int i = 0; i < actSize; i++)
            {
                std::cout << "actNum: " << toSort[i].actNum << " ";
                std::cout << "start: " << toSort[i].start << " ";
                std::cout << "end: " << toSort[i].end << " ";
                std::cout << std::endl;
            }*/

            //insert array into function to determine activity order based on end time
            select(toSort, selected);

            std::cout << "Set: " << set << std::endl;

            std::cout << "Number of Activities Selected: " << selected.size() << std::endl;

            std::cout << "Activities: ";
            for(int i = selected.size() - 1; i >= 0; i--)
            {
                std::cout << selected[i] << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;

            // Remove selected for next set
            selected.erase(selected.begin(), selected.end());
        }
        while (!inputFile.eof());
    }
    std::cout << "Activity Program Ending" << std::endl;

    return 0;
}