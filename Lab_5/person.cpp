#include "person.h"

Person::Person(int key, std::string x) {
	if (key == 0) {
		name = x;
		pkey = &name;
	}
	else if (key == 1) {
		bday = x;
		pkey = &bday;
	}
}

std::string Person::getName() {
	return name;
}

std::string Person::getBday() {
	return bday;
}

void Person::setName(std::string n) {
	name = n;
}

void Person::setBday(std::string day) {
	bday = day;
}

void Person::displayPerson() {
	std::cout << std::left << std::setw(60) << name << std::right << std::setw(20) << bday;
}

std::ostream& operator<<(std::ostream& output, Person& obj) {
	output << std::left << std::setw(60) << obj.getName() << std::right << std::setw(20) << obj.getBday();
	return output;
}

std::istream& operator>>(std::istream& input, Person& obj) {
	input >> obj.name >> obj.bday;
	return input;
}

bool operator< (Person& obj1, Person& obj2) {
	return *(obj1.pkey) < *(obj2.pkey);
}

bool operator> (Person& obj1, Person& obj2) {
	return *(obj1.pkey) > *(obj2.pkey);
}

bool operator== (Person& obj1, Person& obj2) {
	return *(obj1.pkey) == *(obj2.pkey);
}
