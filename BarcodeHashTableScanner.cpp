#include <time.h>
#include <fstream>
#include <sstream>
#include "HashTable.h"

//Chris Sellers
//11/28/2018
//Assignment 5 - UPC Scanner

//*****Running the program in terminal*****
//The ./(File Name) upc_corpus.txt (upc number)
//-Sample- ./HashTable upc_corpus.txt 797776111084

//725177540363
//12569675162
//12569595590
//70720011808
//13484000091
//86891069555
//72392315017
//731454390422
//70145170616

int main(int argc, char** arga) {
	ifstream inputFile;
	string input = "";
	HashTable h;
	string key = "";
	string value = "";
	istringstream inputStream;
	int switchValue = 0;
	string searchValues[9];
	searchValues[0] = "725177540363";
	searchValues[1] = "12569675162";
	searchValues[2] = "12569595590";
	searchValues[3] = "70720011808";
	searchValues[4] = "13484000091";
	searchValues[5] = "86891069555";
	searchValues[6] = "72392315017";
	searchValues[7] = "731454390422";
	searchValues[8] = "70145170616";

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
			h.insert(key, value);
			break;
		}
		//To alternate between tokens
		switchValue++;
		switchValue %= 2;
	}
	inputFile.close();

	int index = 0;
	while (index < 10) {
		//Search for a node and print the total time
		clock_t t = clock();
		cout << h.search(searchValues[index]) << endl;
		t = clock() - t;

		cout << "time: " << t << " milliseconds" << endl;
		cout << CLOCKS_PER_SEC << " clocks per second" << endl;
		cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

		index++;
	}
	return 0;
}
