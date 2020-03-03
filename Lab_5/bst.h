#pragma once
#ifndef BST_H
#define BST_H

#include "bstNode.h"

template <typename T>
class bst {
public:
	bstNode<T>* root = nullptr;
	int n = 0;

public:
	bst() {};
	~bst() {};
	
	void insert(T toInsert);
	bstNode<T>* insert(bstNode<T>* node, T toInsert);
	void display();
	void inorder(bstNode<T>* node);
	void preorder(bstNode<T>* node);
	void postorder(bstNode<T>* node);

	
};

template <typename T>
void bst<T>::insert(T toInsert) {
	insert(root, toInsert);
}

template <typename T>
bstNode<T>* bst<T>::insert(bstNode<T>* node, T toInsert) {
	if (node == nullptr) {
		root = new bstNode<T>(toInsert);
		return root;
	}
	bstNode<T>* temp = root;
	bstNode<T>* parent = nullptr;
	while (temp != nullptr) {
		parent = temp;
		if (toInsert <= temp->data) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	bstNode<T>* temp2 = new bstNode<T>(toInsert);
	if (toInsert <= parent->data) {
		parent->left = temp2;
	}
	else {
		parent->right = temp2;
	}
	return root;

}

template <typename T>
void bst<T>::display() {
	inorder(root);
}
template <typename T>
void bst<T>::inorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	inorder(node->getLeft());
	std::cout << node->getData() << std::endl;
	inorder(node->getRight());
}

template <typename T>
void bst<T>::preorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	std::cout << node->getData() << std::endl;
	preorder(node->left);
	preorder(node->right);
}

template <typename T>
void bst<T>::postorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	postorder(node->left);
	postorder(node->right);
	std::cout << node->getData() << std::endl;
}


#endif