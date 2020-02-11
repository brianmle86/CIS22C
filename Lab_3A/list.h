#pragma once
#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>
#include <string>

template<typename T>
class List {
protected:
	int numNodes;
	Node<T>* head;
	Node<T>* tail;
	int sortStatus;

public:
	List();
	List(int s);
	virtual ~List();
	void insertNode(T value);
	void removeNode(int pos);
	int findValue(T value);
	int getSize();
	void deleteList();
	T getValue(int pos);
	void printList();
};

template <typename T>
List<T>::List() {
	numNodes = 0;
	head = nullptr;
	tail = nullptr;

}

template <typename T>
List<T>::List(int s) {
	numNodes = 0;
	head = nullptr;
	tail = nullptr;
	sortStatus = s; // 0 - unsorted, 1 - ascending, 2 - descending
}

template <typename T>
List<T>::~List() {
	deleteList();
}

template <typename T>
void List<T>::insertNode(T value) {
	Node<T>* toInsert = new Node<T>(value);
	Node<T>* temp = nullptr;

	if (sortStatus == 0) { //unsorted push
		if (numNodes == 0) {
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else {

			tail->next = toInsert;
			tail = tail->next;
			numNodes++;
		}
	}

	else if (sortStatus == 1) { //ascending push
		if (numNodes == 0) {
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else {
			Node<T>* temp, * prev;
			temp = head->next;
			prev = head;

			//if we need to insert before the head node
			if (toInsert->data < head->data) {
				toInsert->next = head;
				head = toInsert;
				numNodes++;
				return;
			}

			while (temp != nullptr && temp->data < toInsert->data) {
				prev = temp;
				temp = temp->next;
			}
			toInsert->next = temp;
			prev->next = toInsert;
			numNodes++;

			//we need to update the list's tail node
			temp = head->next;
			prev = head;
			while (temp != nullptr) {
				prev = temp;
				temp = temp->next;
			}
			tail = prev;
		}
	}

	else if (sortStatus == 2) { //descending push
		if (numNodes == 0) {
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else {
			Node<T>* temp, * prev;
			temp = head->next;
			prev = head;

			//if new data is greater than head node's data, insert to beginning of list
			if (toInsert->data > head->data) {
				toInsert->next = head;
				head = toInsert;
				numNodes++;
				return;
			}

			while (temp != nullptr && temp->data > toInsert->data) {
				prev = temp;
				temp = temp->next;
			}
			toInsert->next = temp;
			prev->next = toInsert;
			numNodes++;

			//since we originally set head = tail, we need to update the list's tail node
			temp = head->next;
			prev = head;
			while (temp != nullptr) {
				prev = temp;
				temp = temp->next;
			}
			tail = prev;
		}
	}

}

template <typename T>
void List<T>::removeNode(int pos) {
	Node<T>* temp = head;
	Node<T>* toRemove;
	Node<T>* prev, * cur;

	//if list is empty
	if (numNodes == 0) {
		return;
	}

	//if position is head
	if (pos == 1) {
		temp = head;
		head = head->next;
		delete temp;
		numNodes--;
	}

	//if position is tail
	else if (pos == numNodes) {
		for (int i = 1; i < pos - 1; i++)
			temp = temp->next;
		toRemove = temp->next;
		temp->next = nullptr;
		delete toRemove;
		numNodes--;
		tail = temp;
	}

	//else, removing from somewhere in middle of list
	else {
		for (int i = 1; i < pos - 1; i++)
			temp = temp->next;
		toRemove = temp->next;
		temp->next = toRemove->next;
		delete toRemove;
		numNodes--;
	}
}
template <typename T>
int List<T>::findValue(T value) {
	Node<T>* temp = head;

	int count = 1; //position variable
	while (temp != nullptr) {
		if (temp->data == value)
			return count;
		temp = temp->next;
		count++;
	}
	return false; //value does not exist

}

template <typename T>
int List<T>::getSize() {
	return numNodes;
}

template <typename T>
void List<T>::deleteList() {
	Node<T>* nodePtr = head;
	Node<T>* temp;
	
	while (nodePtr != nullptr) {
		temp = nodePtr->next;
		delete nodePtr;
		nodePtr = temp;
		numNodes--;
	}
	//numNodes = 0;
	head = nullptr;
	tail = nullptr;
	
}

template <typename T>
T List<T>::getValue(int pos) {
	Node<T>* temp;
	Node<T>* toRemove;

	temp = head;
	if (pos == 1) {
		return head->data;
	}
	for (int i = 1; i < pos; i++)
		temp = temp->next;
	return temp->data;
	
}

template <typename T>
void List<T>::printList() {
	if (numNodes == 0) {
		std::cout << "(empty)\n";
		return;
	}
	Node<T>* temp = head;
	std::cout << "\n# nodes: " << numNodes << std::endl;
	while (temp->next != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << tail->data << " " << std::endl;
}


#endif