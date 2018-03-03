/*********************************************************************
** Program name: Langton's Ant - Project 1
** Author: Devin Gendron
** Date: 1/21/17
** Description: Creates a simulation of Langton's Ant
*********************************************************************/
#ifndef PROMPTUSERMENU_HPP
#define PROMPTUSERMENU_HPP
#include <iostream>
#include <string>
#include <sstream>

int rowsB();
int colsB();
int stepsAnt();
int randomizer();
int randomX(int boardRows);
int randomY(int boardCols);
int chooseX(int boardRows);
int chooseY(int boardCols);

#endif