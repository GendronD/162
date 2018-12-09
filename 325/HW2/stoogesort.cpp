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

//output to file
void output_to_file(std::ofstream &outputFile, std::vector<int> data) {
    //size_t size = sizeof(data)/sizeof(data[0]);
    for(int i = 0; i < data.size(); i++)
    {
        //std::cout << "Adding " << data[i] << " to file." << std::endl;
        outputFile << data[i] << " ";
    }
}

int main() {
    //variables
    std::vector <int> vec;
    int num_to_sort;

    //create file entry portion
    std::string fileName;

    std::cout << "Accessing data.txt file..." << std::endl;
    fileName= "data.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW2StoogeSort/data.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    if(inputFile.fail()) {
        std::cout << "data.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail()) {
        std::cout << "data.txt Opened - Reading..." << std::endl;

        //read in file here
        readFile(inputFile, &vec, &num_to_sort);

        //set array
        int data[num_to_sort];

        //fill array from vector
        for(int i = 0; i < num_to_sort; i++)
        {
            data[i] = vec[i];
        }

        std::cout << "StoogeSort Commencing" << std::endl;

        //before test
        std::cout << "Before StoogeSort: " << std::endl;
        for(int i = 0; i < num_to_sort; i++)
        {
            std::cout << data[i] << ", ";
        }

        //stooge sort function
        stoogeSort(data, 0, num_to_sort - 1);

        //after test
        std::cout << "After StoogeSort: " << std::endl;
        for(int i = 0; i < num_to_sort; i++)
        {
            std::cout << data[i] << ", ";
        }

        //output portion
        std::ofstream outputFile;
        std::string outputFileName;

        outputFileName = "stooge.out";

        outputFile.open(outputFileName.c_str());
        if(outputFile.fail()) {
            std::cout << "stooge.out File Failed" << std::endl;
        }
        else if(!outputFile.fail()) {
            std::cout << "stooge.out Successfully Opened." << std::endl;
            std::cout << "Writing to File..." << std::endl;

            //empty vector
            vec.erase(vec.begin(), vec.end());

            //fill with sorted data from array
            for(int i = 0; i < num_to_sort; i++)
            {
                vec.push_back(data[i]);
            }

            //write to file
            output_to_file(outputFile, vec);

            outputFile.close();
        }
        inputFile.close();
    }
    std::cout << "StoogeSort Read and Write Program Ending" << std::endl;

    return 0;
}