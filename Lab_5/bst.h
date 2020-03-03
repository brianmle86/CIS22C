#pragma once
#ifndef BST_H
#define BST_H

#include "bstNode.h"

template <typename T>
class bst {
private:
	bstNode<T>* root;
	int numNodes;

	bstNode<T>* insert(bstNode<T>* node, T toInsert);
	bstNode<T>* clear(bstNode<T>* node);
	void inOrder(bstNode<T>* node);
	void preOrder(bstNode<T>* node);
	void postOrder(bstNode<T>* node);

public:
	bst();
	~bst();
	
	void insert(T toInsert);
	void clear();

	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	

	
};
template <typename T>
bst<T>::bst() {
	root = nullptr;
	numNodes = 0;
}

template <typename T>
bst<T>::~bst() {
	clear();
}

template <typename T>
void bst<T>::insert(T toInsert) {
	insert(root, toInsert);
}

template <typename T>
bstNode<T>* bst<T>::insert(bstNode<T>* node, T toInsert) {
	if (node == nullptr) { //base case
		root = new bstNode<T>(toInsert);
		numNodes++;
		return root;
	}

	bstNode<T>* newNode = new bstNode<T>(toInsert);
	bstNode<T>* current = root; //start at root
	bstNode<T>* parent = nullptr; //points to parent node of current
	

	while (current != nullptr) {
		parent = current; //store current node as parent
		//go left or right based on comparison
		if (toInsert <= current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	//current is now nullptr
	
	//because we have kept track of parent, compare once more to insert node in correct position
	if (toInsert <= parent->data) {
		parent->left = newNode;
	}
	else {
		parent->right = newNode;
	}
	numNodes++;
	return root;
}

template <typename T>
void bst<T>::clear() {
	clear(root);
	root = nullptr;
	numNodes = 0;
}

template <typename T>
bstNode<T>* bst<T>::clear(bstNode<T>* node) {
	if (node == nullptr)
		return nullptr;
	else {
		clear(node->left);
		clear(node->right);
		delete node;
	}
	return nullptr;
}

template <typename T>
void bst<T>::displayInOrder() {
	if (root == nullptr) {
		std::cout << "empty\n";
		return;
	}
	inOrder(root);
}

template <typename T>
void bst<T>::displayPreOrder() {
	if (root == nullptr) {
		std::cout << "empty\n";
		return;
	}
	preOrder(root);
}

template <typename T>
void bst<T>::displayPostOrder() {
	if (root == nullptr) {
		std::cout << "empty\n";
		return;
	}
	postOrder(root);
}

template <typename T>
void bst<T>::inOrder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	inOrder(node->getLeft());
	std::cout << node->getData() << std::endl;
	inOrder(node->getRight());
}

template <typename T>
void bst<T>::preOrder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	std::cout << node->getData() << std::endl;
	preOrder(node->left);
	preOrder(node->right);
}

template <typename T>
void bst<T>::postOrder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	postOrder(node->left);
	postOrder(node->right);
	std::cout << node->getData() << std::endl;
}


#endif