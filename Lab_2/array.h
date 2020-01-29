#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <iostream>
using namespace std;
template <typename T>
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
	
	
	virtual ~Array() {
		delete[] dataArray;
	};
	
	
	friend ostream& operator<<(ostream& output, Array<T> *obj) {
		for (int i = 0; i < size; i++) {
			output << obj[i];
		}
		return output;
	}
	
	T& operator[](int i) {
		return dataArray[i];
	}
	
};




#endif
