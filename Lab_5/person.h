#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
	std::string name;
	std::string bday;
	std::string* pkey;

public:
	Person();
	std::string readFile(std::string content);
	std::string getName();
	std::string getBday();
};

#endif