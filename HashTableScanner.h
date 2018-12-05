#ifndef HASHTABLESCANNER_H
#define HASHTABLESCANNER_H

#include "HashTable.h"

class HashTableScanner {
	string filePath;
	HashTable hashTable;
public:
	HashTableScanner(string filePath) {
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
			hashTable.insert(key, value);
		}
		inputFile.close();
	}

	string search(string key) {
		return hashTable.search(key);
	}

};

#endif
