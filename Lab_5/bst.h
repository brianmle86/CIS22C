#pragma once
#ifndef BST_H
#define BST_H

#include "bstNode.h"
/*
Binary Search Tree Class.
Has all the typical functions related to BST. Also is able
to traverse inorder, preorder, and postorder.
*/
template <typename T>
class bst {
private:
	bstNode<T>* root;
	int numNodes;

	bstNode<T>* insert(bstNode<T>* node, T toInsert);
	bstNode<T>* remove(bstNode<T>* node, T toRemove);
	bstNode<T>* search(bstNode<T>* node, T value);
	bstNode<T>* clear(bstNode<T>* node);
	bstNode<T>* min(bstNode<T>* node);
	bstNode<T>* max(bstNode<T>* node);
	int height(bstNode<T>* node);
	void inOrder(bstNode<T>* node);
	void preOrder(bstNode<T>* node);
	void postOrder(bstNode<T>* node);
	void breathFirst(bstNode<T>* node);

public:
	bst();
	~bst();
	
	void insert(T toInsert);
	void remove(T toRemove);
	bstNode<T>* search(T value);
	void clear();

	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	void displayBreathFirst();
	

	
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
void bst<T>::remove(T toRemove) {
	remove(root, toRemove);
}

template <typename T>
bstNode<T>* bst<T>::remove(bstNode<T>* node, T toRemove) {
	bstNode<T>* temp;
	if (node == nullptr)
		return nullptr;

	else if (toRemove < node->data)
		node->left = remove(node->left, toRemove);

	else if (toRemove > node->data)
		node->right = remove(node->right, toRemove);
	
	//node has two children
	else if (node->left && node->right) {
		temp = min(node->right); //get min of right subtree
		//alternatively, temp = max(node->left);
		node->data = temp->data;
		node->right = remove(node->right, node->data);
	}

	else {
		temp = node;
		if (node->left == nullptr)
			node = node->right;
		else if (node->right == nullptr)
			node = node->left;
		delete temp;
	}
	numNodes--;
	return node;
}
/*
Search for a value in the BST.
Returns it's node's memory address.
*/
template <typename T>
bstNode<T>* bst<T>::search(T value) {
	return search(root, value);
}

template <typename T>
bstNode<T>* bst<T>::search(bstNode<T>* node, T value) { 
	if (node == nullptr || node->data == value)
		return node;
 
	if (node->data < value)
		return search(node->right, value);

	else
		return search(node->left, value);
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
bstNode<T>* bst<T>::min(bstNode<T>* node) {
	if (node == nullptr)
		return nullptr;

	else if (node->left == nullptr)
		return node;

	else
		return min(node->left);
}

template <typename T>
bstNode<T>* bst<T>::max(bstNode<T>* node) {
	if (node == nullptr)
		return nullptr;

	else if (node->right == nullptr)
		return node;

	else
		return max(node->right);
}

template <typename T>
int bst<T>::height(bstNode<T>* node) {
	if (node == nullptr)
		return 0;

	else {
		//left and right subtrees
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);

		if (leftHeight > rightHeight)
			return(leftHeight + 1);

		else //leftHeight <= rightHeight
			return(rightHeight + 1);
	}
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
void bst<T>::displayBreathFirst() {
	//display breath first traversal
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

template <typename T>
void bst<T>::breathFirst(bstNode<T>* node) {
	//do something
}
#endif