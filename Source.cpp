//Janet Valdez
//CS 210
//Project 3
//June 20, 2026

#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include "GroceryItem.h"
#include <iostream>

using namespace std;

//Function to prompt menu
void displayMenu() {
	cout << endl << "Menu" << endl;
	cout << "1. Search for item" << endl;
	cout << "2. Print list with number of frequency's" << endl;
	cout << "3. Print list with frequency's in the form of histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter choice: " << endl;
}


int main() {

	//Map to read input from text file with pointer
	map<string, GroceryItem*> items;

	//Input file stream
	ifstream inFile("inventory.txt");

	//Open text file
	cout << "Opening file inventory.txt" << endl;

	//Checks that the file is open
	if (!inFile.is_open()) {
		cout << "Could not open file inventory.txt" << endl;
		return 1;
	}

	string name;

	//Could not use !inFile.eof() without casuing infinite loop
	while (inFile >> name) {
		if (items.count(name) > 0) {
			//Update the count
			items.at(name)->addItem();

		}
		else {
			//Doesn't exit, need to add to map using emplace
			GroceryItem* newItem = new GroceryItem(name, 1);
			items.emplace(name, newItem);
		}
	}

	cout << "Closing file inventory.txt" << endl;

	//Close file
	inFile.close();
	
	int choice;

	do {
		displayMenu();
		
		//Checks for input that is not an integer
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input" << endl;
		}

		//Value for item search
		string i;
		//Integer for histogram
		int j;

		switch (choice) {
			case 1: {
				cout << "-------------" << endl;
				cout << "Enter item: ";
				cin >> i;
				//Retrieves item with the quantity
				if (items.count(i) > 0) {
					cout << i << " " << items.at(i)->getQuantity() << endl;
				}
				else {
					cout << i << " not in inventory" << endl;
				}
				break;
			}

			case 2: {
				//Loop through map conatining object value
				map<string, GroceryItem*>::iterator it;
				cout << "-------------" << endl;
				for (it = items.begin(); it != items.end(); it++) {
					cout << it->first << " " << it->second->getQuantity() << endl;
				}
				break;
			}

			case 3: {
				//Loop through map conatining object value
				map<string, GroceryItem*>::iterator it;
				cout << "-------------" << endl;
				for (it = items.begin(); it != items.end(); it++) {
					cout << it->first << " ";
					//Outputs frequency in the form of histograms
					for (j = 0; j < it->second->getQuantity(); j++) {
						cout << "*";
					}
					cout << endl;
				}
				break;
			}

			case 4:
				cout << "-------------" << endl;
				cout << "Exiting Program!" << endl;
				break;

			default:
				cout << "-------------" << endl;
				cout << "Invalid input" << endl;
		}
	}
	while (choice != 4);

	//Backup file implementation
	//Output file stream
	ofstream outFile("frequency.dat");

	//Checks if the file is open
	if (!outFile.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
		return 1;
	}

	//Loops through the data then write into a new file
	map<string, GroceryItem*>::iterator it;

	//Open text file
	cout << "Opening file frequency.dat" << endl;

	for (it = items.begin(); it != items.end(); it++) {
		outFile << it->first << " " << it->second->getQuantity() << endl;
	}

	cout << "Closing file frequency.dat" << endl;

	//Close file
	outFile.close();


	//Deletes allocated memory
	for (it = items.begin(); it != items.end(); it++) {
		delete it->second;
	}
	items.clear();

	return 0;
}
