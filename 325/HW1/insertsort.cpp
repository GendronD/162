/*
 * Author: Devin Gendron
 * Assignment: Homework 1 - Question 4: Insertion Sort
 * Date Due: July 1st - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

//read file function
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

//CITATION: Introduction to Algorithms (CLRS) pg 26 (Chpt 2).
void insertSort(std::vector<int> &data, int num_to_sort) {
    //variables
    int key;
    int i;

    //start at j=2
    for(int j = 2; j < num_to_sort; j++) {
        //key is equal to 2nd value
        key = data[j];
        //i is equal to 1 less
        i = j - 1;

        //compares
        while (i >= 0 && data[i] > key) {
            data[i+1] = data[i];
            i = i - 1;
        }
        //new key
        data[i+1] = key;
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
    fileName= "data.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW1InsertSort/data.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    if(inputFile.fail()) {
        std::cout << "data.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail()) {
        std::cout << "data.txt Opened - Reading..." << std::endl;

        //read in file here
        readFile(inputFile, &data, &num_to_sort);

        std::cout << "InsertionSort Commencing" << std::endl;

        //before test
        /*std::cout << "Before InsertionSort: " << std::endl;
        for(int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << ", ";
        }*/

        //insert sort function
        insertSort(data, num_to_sort);

        //after test
        /*std::cout << "After InsertionSort: " << std::endl;
        for(int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << ", ";
        }*/

        //output portion
        std::ofstream outputFile;
        std::string outputFileName;

        outputFileName = "insert.out";

        outputFile.open(outputFileName.c_str());
        if(outputFile.fail()) {
            std::cout << "insert.out File Failed" << std::endl;
        }
        else if(!outputFile.fail()) {
            std::cout << "insert.out Successfully Opened." << std::endl;
            std::cout << "Writing to File..." << std::endl;

            //write to file
            output_to_file(outputFile, data);

            outputFile.close();
        }
        inputFile.close();
    }
    std::cout << "InsertSort Read and Write Program Ending" << std::endl;

    return 0;
}