#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include "hashNode.h"
#include "person.h"

template <typename K, typename V>
class hashTable {
private:
	hashNode<K, V>** table;
	int numElements;
	int maxElements;
	int numCollisions;

public:
	hashTable(int size);
	~hashTable();
	int hash(std::string key);
	double getLoadFactor();
	int getNumCollisions();
	void insert(Person toInsert); //insert method just for lab 6
	hashNode<K, V>* search(std::string key);
};

#endif

template<typename K, typename V>
hashTable<K, V>::hashTable(int size) {
	maxElements = size;
	numElements = 0;
	numCollisions = 0;

	table = new hashNode<K, V> * [size];
	for (int i = 0; i < size; i++)
		table[i] = nullptr;
}

template<typename K, typename V>
hashTable<K, V>::~hashTable() {
	delete[] table;
}

/*
Adds digits of a given key repeatedly until
the sum is a an integer n such that 0 <= n <= 9
*/
template<typename K, typename V>
int hashTable<K, V>::hash(std::string key) {
	int sum = 0;
	while (key.length() != 1) {
		sum = 0;
		for (int i = 0; i < key.length(); i++) {
			if (key[i] == '-')
				continue;
			sum += (key[i] - '0'); //key[i] is char, so subtract '0' to get int
		}
		key = std::to_string(sum);
	}
	return sum;
}

/*
Load Factor = # keys stored / total capacity
*/
template<typename K, typename V>
double hashTable<K, V>::getLoadFactor() {
	return static_cast<double>(numElements) / maxElements;
}

template<typename K, typename V>
int hashTable<K, V>::getNumCollisions() {
	return numCollisions;
}

/*
Insert a Person object to the hash table.
Uses quadratic probing for collision resolution.
*/
template<typename K, typename V>
void hashTable<K, V>::insert(Person toInsert) {
	std::string key = toInsert.getBday();
	hashNode<K, V>* temp = new hashNode<K, V>(key, toInsert);

	int index = hash(key);
	if (table[index] == nullptr) {
		table[index] = temp;
		numElements++;
	}

	else {
		//use quadratic probing to find next available index
		int i = 1;
		while (table[index] != nullptr) {
			numCollisions++;
			index = ((hash(key) + (i * i)) % maxElements);
			i++;
		}
		table[index] = temp;
		numElements++;
	}
}

template<typename K, typename V>
hashNode<K, V>* hashTable<K, V>::search(std::string key) {
	int index = hash(key);
	int i = 1;
	while (table[index]->value.getBday() != key)
		index = ((hash(key) + (i * i)) % maxElements);

	return table[index];
}
