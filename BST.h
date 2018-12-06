#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

//This is a binary search tree. Each node contains
//a key, value, left and right reference to nodes
class BST {
public:
	//Constructor
	BST() {
		root = nullptr;
	}

	//Destructor
	~BST() {
		deleteAllNodes();
	}

	//Insert a node with the given key and value. Base function
	void insert(string key, string value) {
		Node* newNode = new Node(key, value);
		insert(newNode, root);
	}

	//Find a node with the given key. Base function
	string find(string key) {
		return find(key, root);
	}

private:
	struct Node {
		string key;
		string value;
		Node* left;
		Node* right;
		Node(string key, string value) {
			this->key = key;
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;

	//Insert a new node
	void insert(Node* newNode, Node*& root) {
		if (root == nullptr) {
			root = newNode;
		} else if (root->key.compare(newNode->key) > 0) {
			insert(newNode, root->left);
		} else {
			insert(newNode, root->right);
		}
	}

	//Find a node with the given key
	string find(string key, Node* root) {
		if (root->key == key) {
			return root->value;
		} else if (root->key.compare(key) > 0) {
			return find(key, root->left);
		} else if (root->key.compare(key) < 0) {
			return find(key, root->right);
		}
		return NULL;
	}

	//Delete all nodes. Base function
	void deleteAllNodes() {
		deleteAllNodes(root);
	}

	//Delete all nodes in the order of left, right, root
	void deleteAllNodes(Node* root) {
		if (root->left != nullptr) {
			deleteAllNodes(root->left);
		} else if (root->right != nullptr) {
			deleteAllNodes(root->right);
		}
		delete root;
	}
};

#endif
