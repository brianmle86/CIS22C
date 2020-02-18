#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
/*
Queue ADT
This is a linked list that has FIFO behavior
*/
template<typename T>
class Queue : public List<T> {
public:
	Queue() {
		List<T>::List();
	}

	//enqueue by inserting node
	void enqueue(T value) {
		List<T>::insertNode(value);
	}

	//dequeue by removing node at position 1, which is position of first node enqueued
	void dequeue() {
		List<T>::removeNode(1);
	}

	//returns value of node at position 1
	T front() {
		return List<T>::getValue(1);
	}

	//returns value of the most recent node enqueued
	T rear() {
		return List<T>::getValue(returnSize());
	}

	//clears queue by calling delete function in list
	void clear() {
		List<T>::deleteList();
	}

	//returns the size of queue
	int returnSize() {
		return List<T>::getSize();
	}

	void displayQueue() {
		List<T>::printList();
	}
	//reverse the queue
	void reverseQueue() {
		List<T>::reverseList();
	}

	~Queue() {
		clear();
	}

};
#endif