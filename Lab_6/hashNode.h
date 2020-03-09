#pragma once
#ifndef HASHNODE_H
#define HASHNODE_H

/*
Node template class for hash map. K = key, V = value
*/
template <typename K, typename V>
class hashNode {
private:
	K key;
	V value;
	hashNode<K, V>* next;
};

#endif