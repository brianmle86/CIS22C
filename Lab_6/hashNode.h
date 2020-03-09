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
public:
	hashNode(K key, V value);
};


#endif

template<typename K, typename V>
hashNode<K, V>::hashNode(K k, V v) {
	key = k;
	value = v;
}
