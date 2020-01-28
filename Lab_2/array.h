#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <string>

template <class T>
class Array {
private:
	T* dataArray;
	int size;
public:
	Array() {
		size = 0;
	}
	
	Array(int givenSize) {
		dataArray = new T[givenSize];
		size = givenSize;
	}
	
	virtual ~Array() {};
	
	void clearArray() {
		if (size < 0) {
			delete[] dataArray;
			size = 0;
		}
	}

	void displayArray() {

	}

};






#endif
