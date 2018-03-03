/*********************************************************************
** Program name: Searching and Sorting
** Author: Devin Gendron
** Date: 3/4/18
** Description: Using algorithms to search data and sort data.
*********************************************************************/
#ifndef SEARCHING_AND_SORTING_MENUS_H
#define SEARCHING_AND_SORTING_MENUS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int menu();
void readFiles(std::ifstream &f, std::vector<int> &file, std::string name);

void simpleSearch(int n, std::vector<int> &file, std::string name);
void sorting(std::ofstream &oFile, std::vector<int> &file, std::string name);
void binarySearch(int n, std::vector<int> &file, std::string name);

#endif //SEARCHING_AND_SORTING_MENUS_H
