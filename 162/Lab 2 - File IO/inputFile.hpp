/*********************************************************************
** Program name: Lab2 - File I/O
** Author: Devin Gendron
** Date: 1/21/17
** Description: Program that reads a file filled with letters, count 
** the letter frequencies in the file, and write the results to a new
** file.
*********************************************************************/
#ifndef INPUTFILE_HPP
#define INPUTFILE_HPP
#include "outputFile.hpp"
#include <fstream>

void count_letters(std::ifstream &inputFile, int *arrayCounter);

#endif