#pragma once
#ifndef STACK_H
#define STACK_H

#include "list.h"
/*
Stack ADT
This is a linked list that has FILO behavior
*/
template<typename T>
class Stack : public List<T> {
public:
	Stack() {
		List<T>::List();
	}

	//push to stack
	void push(T value) {
		List<T>::insertNode(value);
	}

	//pop the stack by removing node on top
	void pop() {
		List<T>::removeNode(returnSize());
	}

	//get value of top of stack
	T peek() {
		return List<T>::getValue(returnSize());
	}

	//clears stack by calling delete function in list
	void clear() {
		List<T>::deleteList();
	}

	//returns the size of the stack
	int returnSize() {
		return List<T>::getSize();
	}

	~Stack() {
		clear();
	}


};
#endif