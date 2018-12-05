#ifndef BSTSCANNER_H
#define BSTSCANNER_H

#include "BST.h"

class BSTScanner {
	string filePath;
	BST bst;
public:
	BSTScanner(string filePath) {
		this->filePath = filePath;
		readInFile();
	}

	void readInFile() {
		ifstream inputFile;
		string input, key, value;

		inputFile.open(filePath);
		getline(inputFile, input, '\n');
		while (!inputFile.eof()) {
			getline(inputFile, key, ',');
			getline(inputFile, value, '\n');
			bst.insert(key, value);
		}
		inputFile.close();
	}

	string find(string key) {
		return bst.find(key);
	}

};

#endif
