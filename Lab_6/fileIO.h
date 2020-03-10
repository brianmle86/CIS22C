#pragma once
#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "person.h"

/*
Class of static functions for file IO.
*/
class fileIO {
public:
	static void readFile(std::ifstream& file, hashTable<std::string, Person> &table);
	static bool valid(std::string nameLine, std::string bdayLine);
	static int getNumLines(std::ifstream& file);
	static bool isNum(char c);
};




#endif