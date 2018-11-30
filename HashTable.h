#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

class HashTable {
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
	HashTable() {
		size = 1000;
		nodeArray = new Node[size];
	}
	~HashTable() {
		deleteAll();
		delete[] nodeArray;
	}
	void insert(string key, string value) {
		Node * newNode = new Node(key, value);
		int hashValue = getHashValue(key);
		newNode->next = nodeArray[hashValue].next;
		nodeArray[hashValue].next = newNode;
	}

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
