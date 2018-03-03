/*********************************************************************
** Program name: Lab2 - File I/O
** Author: Devin Gendron
** Date: 1/21/17
** Description: Program that reads a file filled with letters, count 
** the letter frequencies in the file, and write the results to a new
** file.
*********************************************************************/
#ifndef OUTPUTFILE_HPP
#define OUTPUTFILE_HPP
#include "inputFile.hpp"
#include <fstream>

void output_letters(std::ofstream &outputFile, int *arrayCounter);

#endif