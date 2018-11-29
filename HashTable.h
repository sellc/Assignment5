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
		Node* current;
		if (nodeArray[stoi(key) % size].key.compare("") == 0) {
			nodeArray[stoi(key) % size].key = key;
			nodeArray[stoi(key) % size].value = value;
		} else {
			current = &nodeArray[stoi(key) % size];
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = new Node(key, value);
		}
	}

	string search(string key) {
		int index = 0;
		Node * current = nullptr;
		while (index < size) {
			current = &nodeArray[index];
			while (current != nullptr) {
				if (current->key == key) {
					return current->value;
				}
				current = current->next;
			}
			index++;
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
};

#endif
