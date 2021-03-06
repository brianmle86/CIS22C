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
	
	void inOrder(bstNode<T>* node);
	void preOrder(bstNode<T>* node);
	void postOrder(bstNode<T>* node);
	

	void wInOrder(bstNode<T>* node, std::ofstream& file);
	void wPostOrder(bstNode<T>* node, std::ofstream& file);
	void wPreOrder(bstNode<T>* node, std::ofstream& file);

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
	
	void writeInOrder(std::ofstream& file);
	void writePostOrder(std::ofstream& file);
	void writePreOrder(std::ofstream& file);
	
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

/*
Insert a node to the tree
*/
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

/*
Remove a node in the tree
*/
template <typename T>
bstNode<T>* bst<T>::remove(bstNode<T>* node, T toRemove) {
	bstNode<T>* temp;
	if (node == nullptr)
		return nullptr;

	else if (toRemove <= node->data)
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
Search for a value in the BST. (recursively)
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

/*
Deletes all nodes in tree
*/
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

/*
Returns node with minimum value in a subtree of a given node
*/
template <typename T>
bstNode<T>* bst<T>::min(bstNode<T>* node) {
	if (node == nullptr)
		return nullptr;

	else if (node->left == nullptr)
		return node;

	else
		return min(node->left);
}

/*
Returns node with maximum value in a subtree of a given node
*/
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
	inOrder(node->left);
	std::cout << node->data << std::endl;
	inOrder(node->right);
}

template <typename T>
void bst<T>::preOrder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	std::cout << node->data << std::endl;
	preOrder(node->left);
	preOrder(node->right);
}

template <typename T>
void bst<T>::postOrder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	postOrder(node->left);
	postOrder(node->right);
	std::cout << node->data << std::endl;
}

template <typename T>
void bst<T>::writeInOrder(std::ofstream& file) {
	wInOrder(root, file);
}

template <typename T>
void bst<T>::writePostOrder(std::ofstream& file) {
	wPostOrder(root, file);
}

template <typename T>
void bst<T>::writePreOrder(std::ofstream& file) {
	wPreOrder(root, file);
}

template <typename T>
void bst<T>::wInOrder(bstNode<T>* node, std::ofstream& file) {
	if (node == nullptr)
		return;
	wInOrder(node->left, file);
	file << node->data << std::endl;
	wInOrder(node->right, file);
}

template <typename T>
void bst<T>::wPostOrder(bstNode<T>* node, std::ofstream& file) {
	if (node == nullptr)
		return;
	wPostOrder(node->left, file);
	wPostOrder(node->right, file);
	file << node->data << std::endl;
}

template <typename T>
void bst<T>::wPreOrder(bstNode<T>* node, std::ofstream& file) {
	if (node == nullptr)
		return;
	file << node->data << std::endl;
	wPreOrder(node->left, file);
	wPreOrder(node->right, file);
}

#endif