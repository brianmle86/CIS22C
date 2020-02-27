#pragma once

template <typename T>
class bstNode {
private:
	T data;
	T* left;
	T* right;

public:
	bstNode();
	bstNode(T x);

	void setData(T x);
	void setLeft(T l);
	void setRight(T r);

	T getData();
	T* getLeft();
	T* getRight();


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
T* bstNode<T>::getLeft() {
	return left;
}

template <typename T>
T* bstNode<T>::getRight() {
	return right;
}

template <typename T>
bstNode<T>::~bstNode() {
	left = nullptr;
	right = nullptr;
}
