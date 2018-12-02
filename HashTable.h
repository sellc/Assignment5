#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

class HashTable {
	//Node object used for storing the key, value and next node in the list
	struct Node {
		string key;
		string value;
		Node* next;
		Node() {
			key = "";
			value = "";
			next = nullptr;
		}
		Node(string key, string value) {
			this->key = key;
			this->value = value;
			next = nullptr;
		}
	};

	size_t size;
	Node* nodeArray;

public:
	//Constructor
	HashTable() {
		size = 1000;
		nodeArray = new Node[size];
	}

	//Destructor
	~HashTable() {
		deleteAll();
		delete[] nodeArray;
	}

//Insert a new node with the provided key and value
	void insert(string key, string value) {
		Node * newNode = new Node(key, value);
		int hashValue = getHashValue(key);
		newNode->next = nodeArray[hashValue].next;
		nodeArray[hashValue].next = newNode;
	}

//Search for a value with the given key
	string search(string key) {
		Node * current = nullptr;
		int hashValue = getHashValue(key);
		current = &nodeArray[hashValue];
		while (current != nullptr) {
			if (current->key == key) {
				return current->value;
			}
			current = current->next;
		}
		return "";
	}

//Delete all nodes when the program is done.
//Increments through the array and deletes the list of nodes
	void deleteAll() {
		int index = 0;
		Node * current = nullptr;
		Node * temp = nullptr;
		while (index < size) {
			current = nodeArray[index].next;
			while (current != nullptr) {
				temp = current;
				current = current->next;
				delete temp;
			}
			index++;
		}
	}

//Get the hash value of the given key by performing the hashing operation
	int getHashValue(string key){
		string substring;
		if (key.length() > 4) {
			substring = key.substr(key.length() - 4, 4);
		} else {
			substring = key;
		}
		return stoi(substring) % size;
	}
};

#endif
