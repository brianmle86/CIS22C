#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <iostream>

using namespace std;
/*
Template array class.
This allows us to create an array of a generic type, T.

*/
template <class T>
class Array {
private:
	T* dataArray;
	int size;
public:
	Array();
	Array(int givenSize);
	virtual ~Array();
	
	//operator overloads
	friend ostream& operator<<(ostream& output, Array<T>* obj) {
		for (int i = 0; i < size; i++) {
			output << obj[i];
		}
		return output;
		
	}
	T& operator[](int i) {
		return dataArray[i];
	}
	
};


template <class T>
Array<T>::Array() {
	size = 0;
}

template <class T>
Array<T>::Array(int givenSize) {
	dataArray = new T[givenSize];
	size = givenSize;
}

template <class T>
Array<T>::~Array() {
	delete[] dataArray;
}

#endif
