#pragma once
#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

template <typename T>
class bstNode {
public:
	T data;
	bstNode<T>* left;
	bstNode<T>* right;

public:
	bstNode();
	bstNode(T x);

	void setData(T x);
	void setLeft(T l);
	void setRight(T r);

	T getData();
	bstNode<T>* getLeft();
	bstNode<T>* getRight();
	
	void displayData();

	~bstNode();
};

template <typename T>
bstNode<T>::bstNode() {
	left = nullptr;
	right = nullptr;
}

template <typename T>
bstNode<T>::bstNode(T x) {
	data = x;
	left = nullptr;
	right = nullptr;
}

template <typename T>
void bstNode<T>::setData(T x) {
	data = x;
}

template <typename T>
void bstNode<T>::setLeft(T l) {
	left = l;
}

template <typename T>
void bstNode<T>::setRight(T r) {
	right = r;
}

template <typename T>
T bstNode<T>::getData() {
	return data;
}

template <typename T>
bstNode<T>* bstNode<T>::getLeft() {
	return left;
}

template <typename T>
bstNode<T>* bstNode<T>::getRight() {
	return right;
}

template <typename T>
void bstNode<T>::displayData() {
	std::cout << data << std::endl;
}

template <typename T>
bstNode<T>::~bstNode() {
	left = nullptr;
	right = nullptr;
}

#endif