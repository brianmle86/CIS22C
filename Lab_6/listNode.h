#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

/*
Node for use in linked lists.
*/
template <typename T>
class listNode {
public:
	T data;
	listNode<T>* next;

	listNode(T x);
	~listNode();
};

template<typename T>
listNode<T>::listNode(T x) {
	data = x;
	next = nullptr;
}

template<typename T>
listNode<T>::~listNode() {
	next = nullptr;
}
#endif