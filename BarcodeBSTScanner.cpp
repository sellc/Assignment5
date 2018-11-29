#include <time.h>
#include <fstream>
#include <sstream>
#include "BST.h"

//Chris Sellers
//11/21/2018
//Assignment 4 - UPC Scanner

//*****Running the program in terminal*****
//The ./(File Name) upc_corpus.txt (upc number)
//-Sample- ./BST upc_corpus.txt 797776111084

//Barcode Scanner with a BST data structure
int main(int argc, char** arga) {
	ifstream inputFile;
	string input = "";
	BST bst;
	string key = "";
	string value = "";
	istringstream inputStream;
	int switchValue = 0;

	//Open file and read in each line
	inputFile.open(arga[1]);
	getline(inputFile, input, '\n');
	while (!inputFile.eof()) {
		switch (switchValue) {

		//First token ending with ',''
		case 0:
			getline(inputFile, input, ',');
			key = input;
			break;

		//Second token ending with '\n'
		case 1:
			getline(inputFile, input, '\n');
			value = input;
			bst.insert(key, value);
			break;
		}
		//To alternate between tokens
		switchValue++;
		switchValue %= 2;
	}
	inputFile.close();

//Search for a node and print the total time
	clock_t t = clock();
	cout << bst.find(arga[2]) << endl;
	t = clock() - t;

	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}
