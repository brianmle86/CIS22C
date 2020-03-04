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
	static void readFile(std::fstream &dataFile, bst<Person>* &nameTree, bst<Person>* &bdayTree);
	static bool valid(std::fstream& dataFile);
	static int getNumLines(std::fstream& file);
};




#endif