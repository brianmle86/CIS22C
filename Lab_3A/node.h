#pragma once
#ifndef NODE_H
#define NODE_H

template<typename T>

class Node {
protected:
	T data;
	Node<T>* next;

public:
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
	next = nullptr; //delete maybe?
}
#endif