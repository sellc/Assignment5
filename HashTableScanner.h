#ifndef HASHTABLESCANNER_H
#define HASHTABLESCANNER_H

#include <fstream>
#include <sstream>
#include "HashTable.h"

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

//This class is used to read in from a file and
//store values in a hash table.
class HashTableScanner {
	string filePath;
	HashTable hashTable;

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
			hashTable.insert(key, value);
		}
		inputFile.close();
	}

public:
	//Constructor
	HashTableScanner(string filePath) {
		this->filePath = filePath;
		readInFile();
	}

	//search for the provided key
	string search(string key) {
		return hashTable.search(key);
	}
};

#endif
