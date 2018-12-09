/*
 * Author: Devin Gendron
 * Assignment: Homework 1 - Question 4: MergeSort
 * Date Due: July 1st - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

//Read file function
void readFile(std::ifstream &inputFile, std::vector <int> *data, int *num_to_sort)
{
    bool end = true;	//checks for end of line
    int num;
    bool first = true;

    //do while not at end of file
    do
    {
        //read in file
        inputFile >> num;

        //std::cout << "num: " << num << std::endl;

        if(first == true) {
            *num_to_sort = num;
            first = false;
        }
        else {
            data->push_back(num);
        }

        if (inputFile.eof())	//if file ends, exit loop
        {
            end = false;
        }
    }
    while (end != false);
}

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

//output to file
void output_to_file(std::ofstream &outputFile, std::vector <int> data) {
    for(int i = 0; i < data.size(); i++)
    {
        //std::cout << "Adding " << data[i] << " to file." << std::endl;
        outputFile << data[i] << " ";
    }
}

int main() {
    //variables
    std::vector <int> data;
    int num_to_sort;

    //create file entry portion
    std::string fileName;

    std::cout << "Accessing data.txt file..." << std::endl;
    fileName = "data.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW1MergeSort/data.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    if(inputFile.fail()) {
        std::cout << "data.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail()) {
        std::cout << "data.txt Opened - Reading..." << std::endl;

        //read in file here
        readFile(inputFile, &data, &num_to_sort);

        //setup for mergesort
        int low = 0;
        int high = num_to_sort - 1;

        std::cout << "MergeSort Commencing" << std::endl;


        /*std::cout << "Before MergeSort: " << std::endl;
        for(int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << ", ";
        }*/

        //implement mergesort code here
        mergeSort(data, low, high);

        /*std::cout << "After MergeSort: " << std::endl;
        for(int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << ", ";
        }*/
        std::cout << "MergeSort Complete" << std::endl;

        //output portion
        std::ofstream outputFile;
        std::string outputFileName;

        outputFileName = "merge.out";

        outputFile.open(outputFileName.c_str());
        if(outputFile.fail()) {
            std::cout << "merge.out File Failed" << std::endl;
        }
        else if(!outputFile.fail()) {
            std::cout << "merge.out Successfully Opened." << std::endl;
            std::cout << "Writing to File..." << std::endl;

            //write to file
            output_to_file(outputFile, data);

            outputFile.close();
        }
        inputFile.close();
    }
    std::cout << "File Write Complete" << std::endl;
    std::cout << "MergeSort Read and Write Program Ending" << std::endl;

    return 0;
}