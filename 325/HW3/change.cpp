/*
 * Author: Devin Gendron
 * Assignment: Homework 3 - Question 5: Making Change
 * Date Due: July 15th - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <ctime>
#include <time.h>

//makeChange
/*
 * CITATION: https://www.youtube.com/watch?annotation_id=annotation_2195265949&feature=iv&src_vid=Y0ZqKpToTic&v=NJuKJ8sasGk
 * CITATION: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 * CITATION: https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 * CITATION: https://www.geeksforgeeks.org/knapsack-problem/
 * CITATION: http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/DynProg/money-change.html
 *
 *
 *
 * -I was completely at a loss for how to properly get this algorithm going.  I used these sources
 *  in an attempt to get the algorithm working.
 */
int *makeChange(int V[], int A, int size, int &sum) {
    int table[A+1];
    int denom[A+1];

    const int infinity = 2147483647;

    table[0] = 0;
    denom[0] = -1;

    for (int i=1; i<=A; i++)
    {
        table[i] = infinity - 1;
        denom[i] = -1;
    }

    //for(int i = 0; i < A + 1; i++)
        //std::cout << "table" << i << ": " << table[i] << std::endl;
    //for(int i = 0; i < A + 1; i++)
        //std::cout << "denom" << i << ": " << denom[i] << std::endl;

    for (int j=0; j<size; j++)
    {
        for (int i=1; i<=A; i++)
        {
            if (i >= V[j])
            {
                if(table[i - V[j]] + 1 < table[i])
                {
                    table[i] = 1 + table[i - V[j]];
                    denom[i] = j;
                }
            }
        }
    }
    //std::cout << "min coins: " << table[A] << std::endl;
    //for(int i = 0; i < A + 1; i++)
        //std::cout << "table" << i << ": " << table[i] << std::endl;
    //for(int i = 0; i < A + 1; i++)
        //std::cout << "denom" << i << ": " << denom[i] << std::endl;

    sum = table[A];

    int x = 0;
    int *ans = new int[size];
    for(int i = 0; i < size; i++)
    {
        ans[i] = 0;
    }
    int array[size];

    int getSize = A;

    while(getSize != 0)
    {
        int j = denom[getSize];
        array[x] = V[j];
        getSize = getSize - V[j];
        x++;
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j< size; j++)
        {
            if(V[i] == array[j])
                ans[i]++;
        }
    }

    return ans;
}

//output to file
void output_to_file(std::ofstream &outputFile, std::vector<int> vec, int data[], int A, int size, int summation) {

    int sum = 0;

    //output coin types
    //std::cout << "Vec to File" << std::endl;
    for(int i = 0; i < vec.size(); i++)
    {
        //std::cout << "Adding " << data[i] << " to file." << std::endl;
        outputFile << vec[i] << " ";
    }

    outputFile << std::endl;

    //return amount A
    //std::cout << "A to File" << std::endl;
    outputFile << A;

    outputFile << std::endl;

    //array of coin counts
    //std::cout << "coin count to file" << std::endl;
    for(int i = 0; i < size; i++) {
        outputFile << data[i] << " ";
    }

    outputFile << std::endl;

    //total number of coins used
    //std::cout << "sum to file" << std::endl;
    outputFile << summation;

    outputFile << std::endl;
    outputFile << std::endl;
}

int main() {
    //variables
    std::vector <int> vec;
    int A = 0;
    double runtime = 0.0;
    int sum = 0;

    //create file entry portion
    std::string fileName;

    std::cout << "Accessing data.txt file..." << std::endl;
    fileName= "amount.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW3makeChange/amount.txt";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());

    if(inputFile.fail()) {
        std::cout << "amount.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail()) {
        std::cout << "amount.txt Opened - Reading..." << std::endl;

        //read in file here
        bool end = true;	//checks for end of line
        int num;
        char var;
        bool line_A = false;
        int counter = 0;
        bool ender = false;

        //do while not at end of file
        do
        {
            std::string line;

            //read one line at a time
            std::getline(inputFile, line);
            std::stringstream ss(line);

            while(ss >> num) {
                if(line_A == true) {
                    A = num;
                    //std::cout << "a: " << A << std::endl;
                }
                else
                {
                    vec.push_back(num);
                    //std::cout << "num: " << num << std::endl;
                }
            }

            //makeChangefunction
            if(line_A == true) {
                int size = vec.size();

                //set array
                int data[size];
                //int *data;
                int *dataReturned;
                //data = new int[size];

                //fill array from vector
                for(int i = 0; i < size; i++)
                {
                    data[i] = vec[i];
                }

                //std::cout << "about to enter makeChange" << std::endl;

                //CITATION: https://stackoverflow.com/questions/5248915/execution-time-of-c-program
                //start clock
                clock_t begin = clock();

                dataReturned = makeChange(data, A, size, sum);

                clock_t ended = clock();

                //compute time
                runtime = (double)(ended - begin) / CLOCKS_PER_SEC;

                //print data
                //std::cout << "n = " << num_to_sort << std::endl;
                std:: cout << "makeChange Sort RunTime: " << runtime << std::endl;
                std::cout << "" << std::endl;

                //output portion
                std::ofstream outputFile;
                std::string outputFileName;

                outputFileName = "change.txt";

                outputFile.open(outputFileName.c_str(), std::fstream::app);
                if(outputFile.fail()) {
                    std::cout << "change.txt File Failed" << std::endl;
                }
                else if(!outputFile.fail()) {
                    std::cout << "change.txt Successfully Opened." << std::endl;
                    std::cout << "Writing to File..." << std::endl;

                    //write to file
                    output_to_file(outputFile, vec, dataReturned, A, size, sum);

                    outputFile.close();
                }
                //empty vector
                vec.erase(vec.begin(), vec.end());
                //set A to 0
                A = 0;
                //reset line_A boolean
                line_A = false;
                //delete returned data
                delete [] dataReturned;
                dataReturned = 0;

                if (inputFile.eof())	//if file ends, exit loop
                {
                    end = false;
                }
            }
            else{
                line_A = true;
            }

        }
        while (end != false);
    }
    std::cout << "makeChange Program Ending" << std::endl;

    return 0;
}