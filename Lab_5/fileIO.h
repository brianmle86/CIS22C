#pragma once
#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>
#include <fstream>
#include "bst.h"
#include "person.h"

/*
Class of static functions for file IO.
*/
class fileIO {
public:
	static void readFile(std::ifstream &dataFile, bst<Person> &nameTree, bst<Person> &bdayTree);
	static void writeFiles(std::ofstream& nameFile, std::ofstream& bdayFile, bst<Person>& nameTree, bst<Person>& bdayTree);
	static bool valid(std::string nameLine, std::string bdayLine);
	static int getNumLines(std::ifstream& file);
	static bool isNum(char c);
};




#endif