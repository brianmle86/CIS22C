#pragma once
#ifndef SORT_H
#define SORT_H
#include "array.h"
template <class T>
class Sort {
private:
	T* dataArray;
	int size;
public:
	void RecurSelectionSort(Array<T>& toSort, int size, int current = 0) {
        if (size - current == 1)
            return;
        else {
            T min = toSort[current];
            int minIndex = current;

            for (int i = current; i < size; ++i) { 
                if (toSort[i] < min) {
                    min = toSort[i];
                    minIndex = i;
                }
            }

            swapVal(toSort[current], toSort[minIndex]);

            RecurSelectionSort(toSort, size, current + 1);

            
        }
	}
	void swapVal(T &a, T &b) {
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
	
};





#endif