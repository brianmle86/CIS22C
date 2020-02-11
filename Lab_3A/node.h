#pragma once
#ifndef NODE_H
#define NODE_H

/*
Node for use in linked lists.
*/
template<typename T>
class Node {
public:
	T data;
	Node<T>* next;

	Node(T x);
	~Node();
};

template<typename T>
Node<T>::Node(T x) {
	data = x;
	next = nullptr;
}

template<typename T>
Node<T>::~Node() {
	next = nullptr;
}
#endif