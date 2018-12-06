#ifndef BSTSCANNER_H
#define BSTSCANNER_H

#include <fstream>
#include <sstream>
#include "BST.h"

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

//This class is used to read in from a file and
//store values in a BST.
class BSTScanner {
	string filePath;
	BST bst;

	//Read in the contents of the file
	void readInFile() {
		ifstream inputFile;
		string input, key, value;

		//open file at provided file path
		inputFile.open(filePath);
		getline(inputFile, input, '\n');

		//continue to read in until end of file
		while (!inputFile.eof()) {
			getline(inputFile, key, ',');
			getline(inputFile, value, '\n');
			bst.insert(key, value);
		}
		inputFile.close();
	}

public:
	//Constructor
	BSTScanner(string filePath) {
		this->filePath = filePath;
		readInFile();
	}

	//Search for the provided key
	string find(string key) {
		return bst.find(key);
	}
};

#endif
