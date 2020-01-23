#pragma once
#ifndef NODE_H
#define NODE_H

template<class T>

class Node {
public:
	T data;
	Node<T>* next;

	Node(T x) {
		data = x;
		next = nullptr;
	}

	~Node() {
		next = nullptr; //delete maybe?
	}
};

#endif