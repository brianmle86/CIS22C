#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include "hashNode.h"
#include "person.h"

/*
Hash Table class which uses quadratic probing for collision
resolution. For cyclic hashes, linear probing is used.
*/
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
	void displayTable();
	void insert(Person toInsert);
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

template<typename K, typename V>
void hashTable<K, V>::displayTable() {
	std::cout << "----------------------------------------------------\n";
	std::cout << std::left << std::setw(25)
		<< "Name" << std::setw(15) << "key(bday)"
		<< std::setw(3) << "Index\n\n";
	for (int i = 0; i < maxElements; i++) {
		if (table[i] == nullptr) {
			std::cout << std::left << std::setw(25)
				<< "NULL" << std::setw(15) << "NULL"
				<< std::setw(3) << i << std::endl;
		}
			
		else {
			std::cout << std::left << std::setw(25)
				<< table[i]->value.getName() << std::setw(15)
				<< table[i]->value.getBday()
				<< std::setw(3) << i << std::endl;
		}
			
	}

	std::cout << "\n\n# Items loaded: " << numElements << std::endl
		<< "Load factor: " << std::setprecision(2) << std::fixed
		<< getLoadFactor() << std::endl
		<< "# Collisions: " << getNumCollisions() << std::endl;
	std::cout << "----------------------------------------------------\n";
}

/*
Insert a Person object to the hash table.
Uses quadratic probing for collision resolution.
In the event of a cyclic hash, linear probing is used.
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
		bool cycle = false;
		//use quadratic probing to find next available index
		int i = 1;
		while (table[index] != nullptr) {
			numCollisions++;
			index = ((hash(key) + (i * i)) % maxElements);
			i++;

			//if the index from quadratic probing
			//is what we started with, it is a cyclic hash
			if (index == hash(key)) {
				cycle = true;
				break;
			}
		}

		if (cycle) {
			//use linear probing
			i = 1;
			index = hash(key) + 1; //skip the first index, since we know there was a collision
			while (table[index] != nullptr) {
				numCollisions++;
				index = (hash(key) + i) % maxElements;
				i++;
			}
		}
		table[index] = temp;
		numElements++;
	}
}

/*
Search in the hash table given a key. Uses quadratic probing
exactly like the insert method (and linear probing when needed)
to return the pointer to the node in the hash table.
Returns a null pointer if search was unsuccesful.
*/
template<typename K, typename V>
hashNode<K, V>* hashTable<K, V>::search(std::string key) {
	int index = hash(key);
	bool cycle = false;
	int i = 1;
	while (table[index]->value.getBday() != key) {
		index = ((hash(key) + (i * i)) % maxElements);
		i++;

		//if the index from quadratic probing
			//is what we started with, it is a cyclic hash
		if (index == hash(key)) {
			cycle = true;
			break;
		}
	}

	if (cycle) {
		//use linear probing
		i = 1;
		index = hash(key) + 1; //skip the first index, already searched
		while (table[index]->value.getBday() != key) {
			index = (hash(key) + i) % maxElements;
			i++;
			if (i == numElements)
				return nullptr;
		}
	}
	return table[index];
}
