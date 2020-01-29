#pragma once
#ifndef SORT_H
#define SORT_H
#include "array.h"
#include <iostream>
template <class T>
class Sort { //needs to be a template class because our sort func needs to sort ints, strings, and currencies
private:
	T* dataArray;
	int size;
public:
    Sort(Array<T> arr, int s) {
        dataArray = arr;
        size = s;
    };
    ~Sort() {
        delete[] dataArray;
    };
	static void RecurSelectionSort(Array<T>& toSort, int size, int x = 0) {
        if (size - x == 1)
            return;
        else {
            T min = toSort[x];
            int minIndex = x;

            for (int i = x; i < size; ++i) { 
                if (toSort[i] < min) {
                    min = toSort[i];
                    minIndex = i;
                }
            }

            swapVal(toSort[x], toSort[minIndex]);
            for (int i = 0; i < size; i++) {
                cout << toSort[i] << " ";

            }
            cout << endl;
            RecurSelectionSort(toSort, size, x + 1);

            
        }
	}
	static void swapVal(T &a, T &b) {
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
    
};





#endif