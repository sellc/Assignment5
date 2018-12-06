#include <time.h>
#include "BSTScanner.h"

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

//*****Running the program in terminal*****
//The ./(File Name) upc_corpus.txt (upc number)
//-Sample- ./BST upc_corpus.txt 797776111084

//Barcode Scanner with a BST data structure
int main(int argc, char** arga) {
	BSTScanner scanner(arga[1]);

	//Search for a node and print the total time
	clock_t t = clock();
	cout << scanner.find(arga[2]) << endl;
	t = clock() - t;

	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}
