#pragma once
#ifndef BST_H
#define BST_H

#include "bstNode.h"

template <typename T>
class bst {
private:
	

public:
	bst();
	~bst();
	
	bstNode<T>* insert(bstNode<T>* node, T data);
	void inorder(bstNode<T>* node);
	void preorder(bstNode<T>* node);
	void postorder(bstNode<T>* node);

	
};

template <typename T>
bstNode<T>* bst<T>::insert(bstNode<T>* root, T toInsert) {
	if (root == nullptr)
		return new bstNode<T>(toInsert);

	if (toInsert < root->data)
		root->left = insert(root->left, toInsert);

	else if (toInsert > root->data)
		root->right = insert(root->right, toInsert);

	return root;
}

template <typename T>
void bst<T>::inorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	inorder(node->left);
	inorder(node->right);
}

template <typename T>
void bst<T>::preorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	preorder(node->left);
	preorder(node->right);
}

template <typename T>
void bst<T>::postorder(bstNode<T>* node) {
	if (node == nullptr)
		return;
	postorder(node->left);
	postorder(node->right);
}


#endif