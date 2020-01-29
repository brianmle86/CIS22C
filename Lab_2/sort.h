#pragma once
#ifndef SORT_H
#define SORT_H
#include "array.h"
#include <iostream>
#include <fstream>
ofstream outFile;

/*
Sort template class.
This needs to be a template class because our sort function
needs to sort ints, strings, and Dollars.
We are using static functions because we are not creating objects of Sort.

*/
template <class T>
class Sort {
private:
    T* dataArray;
    int size;
    
public:
    Sort(Array<T> arr, int s);
    virtual ~Sort();
    
    /*
    This function sorts recursively with a recursive selection sort(descending order).
    While doing so, it displays and writes to a file "out.txt" the array each
    time it is called. Function static because we'll use it with no object.
    */
    static void RecurSelectionSort(Array<T>& toSort, int size, int x = 0);
    
    //simple swap function
    static void swapVal(T& a, T& b);
};


template <class T>
Sort<T>::Sort(Array<T> arr, int s) {
    dataArray = arr;
    size = s;

}

template <class T>
Sort<T>::~Sort() {
    delete[] dataArray;
}

template <class T>
void Sort<T>::RecurSelectionSort(Array<T>& toSort, int size, int x) {
    if (size - x == size) {//initial call, when x is 0 (default argument)
        outFile.open("out.txt");
        outFile << "Brian Le, Luke Marshall\nCIS22C - Lab 2\n\n";
        cout << "\ninput array: ";
        outFile << "input array: ";
        for (int i = 0; i < size; i++) {
            cout << toSort[i] << " ";
            outFile << toSort[i] << " ";
        }
        cout << endl;
        outFile << endl;
    }
    if (size - x == 1) {
        outFile.close();
        return;
    }
    else {
        T max = toSort[x]; //assume first value is largest
        int maxIndex = x; //therefore, set that index as maxIndex

        for (int i = x; i < size; ++i) {
            if (toSort[i] > max) { //found a value that's larger than the current max
                max = toSort[i];
                maxIndex = i;
            }
        }

        swapVal(toSort[x], toSort[maxIndex]);

        for (int i = 0; i < size; i++) { //display to console, write to file
            cout << toSort[i] << " ";
            outFile << toSort[i] << " ";

        }
        cout << endl;
        outFile << endl;
        RecurSelectionSort(toSort, size, x + 1);


    }
}

template <class T>
void Sort<T>::swapVal(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}



#endif