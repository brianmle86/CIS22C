#pragma once

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip>

/*
Person class.
A person has a name and bday, and pkey
points to either name or bday, based on
how the person is constructed.
*/

class Person {
private:
	std::string name;
	std::string bday;
	std::string* pkey = nullptr;

public:
	Person();
	Person(int key, std::string x);
	std::string getName();
	std::string getBday();
	void setName(std::string n);
	void setBday(std::string day);
	void displayPerson(); //actually not needed, because we can directly output it with cout

	//operator overloads
	friend std::ostream& operator<<(std::ostream& output, Person& obj);
	friend std::istream& operator>>(std::istream& input, Person& obj);
	friend bool operator< (Person& obj1, Person& obj2);
	friend bool operator> (Person& obj1, Person& obj2);
	friend bool operator== (Person& obj1, Person& obj2);
	friend bool operator<= (Person& obj1, Person& obj2);
};

#endif