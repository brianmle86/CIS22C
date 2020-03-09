#pragma once
#ifndef LIST_H
#define LIST_H
#include "listNode.h"
#include <iostream>
#include <string>

/*
List ADT.
This is the class for a linked list which has all its typical functions.
Note that it can insert in a sorted, or unsorted manner.
*/
template<typename T>
class List {
protected:
	int numNodes;
	listNode<T>* head;
	listNode<T>* tail;
	int sortStatus = 0; //default to unsorted behavior

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
	void reverseList();
};

template <typename T>
List<T>::List() {
	numNodes = 0;
	head = nullptr;
	tail = nullptr;

}

//overloaded constructor for List, which defines how node insertion behaves
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

//inserts a node based on value of sortStatus
template <typename T>
void List<T>::insertNode(T value) {
	listNode<T>* toInsert = new Node<T>(value); //node to insert
	listNode<T>* temp = nullptr;

	if (sortStatus == 0) { //unsorted insert
		if (numNodes == 0) { //if list is empty
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else { //else insert to end of list
			tail->next = toInsert;
			tail = tail->next;
			numNodes++;
		}
	}

	else if (sortStatus == 1) { //insert in ascending order
		if (numNodes == 0) { //if list is empty
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else {
			listNode<T>* temp, * prev;
			temp = head->next;
			prev = head; //we need to keep track of the previous node

			//if we need to insert before the head node
			if (toInsert->data < head->data) {
				toInsert->next = head;
				head = toInsert;
				numNodes++;
				return;
			}

			//we're inserting in ascending order, so compare toInsert to nodes in list
			while (temp != nullptr && temp->data < toInsert->data) {
				prev = temp;
				temp = temp->next;
			}

			//insert node in correct location by changing previous node's next pointer
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

	else if (sortStatus == 2) { //insert in descending order
		if (numNodes == 0) {
			head = toInsert;
			tail = head;
			numNodes++;
		}
		else {
			listNode<T>* temp, * prev;
			temp = head->next;
			prev = head;

			//if new data is greater than head node's data, insert to beginning of list
			if (toInsert->data > head->data) {
				toInsert->next = head;
				head = toInsert;
				numNodes++;
				return;
			}

			//we're inserting in ascending order, so compare toInsert to nodes in list
			while (temp != nullptr && temp->data > toInsert->data) {
				prev = temp;
				temp = temp->next;
			}
			//insert node in correct location by changing previous node's next pointer
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

//removes a node at a given position
template <typename T>
void List<T>::removeNode(int pos) {
	listNode<T>* temp = head;
	listNode<T>* toRemove; //node to remove

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

//returns the position of a node, given a value
template <typename T>
int List<T>::findValue(T value) {
	listNode<T>* temp = head; //using temp to traverse list

	int count = 1; //position variable
	while (temp != nullptr) {
		if (temp->data == value)
			return count;
		temp = temp->next;
		count++;
	}
	return false; //value does not exist, so returning a non-position number(0), indicating failure

}

//gets size
template <typename T>
int List<T>::getSize() {
	return numNodes;
}

//clears the list
template <typename T>
void List<T>::deleteList() {
	listNode<T>* nodePtr = head;
	listNode<T>* temp;

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

//gets value of a node, given its position
template <typename T>
T List<T>::getValue(int pos) {
	listNode<T>* temp;

	temp = head;
	if (pos == 1) {
		return head->data;
	}
	for (int i = 1; i < pos; i++)
		temp = temp->next;
	return temp->data;

}

//displays the list to console
template <typename T>
void List<T>::printList() {
	if (numNodes == 0) {
		std::cout << "(empty)\n";
		return;
	}
	listNode<T>* temp = head;

	while (temp->next != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << tail->data << " " << std::endl;
}

//reverse the list
template <typename T>
void List<T>::reverseList() {
	listNode<T>* temp = head;
	listNode<T>* current = head;
	listNode<T>* nextNode = nullptr;
	listNode<T>* prevNode = nullptr;

	while (current != nullptr) {
		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	head = prevNode;
	tail = temp;




}

#endif