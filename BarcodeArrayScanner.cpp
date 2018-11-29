#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//Chris Sellers
//11/21/2018
//Assignment 4 - UPC Scanner

//*****Running the program in terminal*****
//The ./(File Name) upc_corpus.txt (upc number)
//-Sample- ./Array upc_corpus.txt 797776111084

//Barcode Scanner with an array data structure
int main(int argc, char** arga) {
	//Node used in array to store key and value
	struct Node {
		string key;
		string value;
	};
	size_t size = 1000000;
	Node* nodeArray = new Node[size];
	int count = 0;
	int index = 0;

	ifstream inputFile;
	istringstream inputStream;

	string input = "";
	string key = "";
	string value = "";
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
			if (count + 1 < size) {
				nodeArray[count].key = key;
				nodeArray[count].value = value;
				count++;
			}
			break;
		}
		//To alternate between tokens
		switchValue++;
		switchValue %= 2;
	}
	inputFile.close();

//Search for a node and print the total time
	clock_t t = clock();
	while (index < size) {
		if ((nodeArray[index].key).compare(arga[2]) == 0) {
			cout << nodeArray[index].value << endl;
			index = size;
		}
		index++;
	}
	t = clock() - t;

	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	delete[] nodeArray;

	return 0;
}
