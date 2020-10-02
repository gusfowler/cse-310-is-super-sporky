//********************************************************************************
// Assignment: ASU CSE310 HW#3
// Name:
// ASU ID:
// ASU Email Address:
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

#include <iostream>
#include <string>

//include the header file here
#include <Heap.h>
//----

using namespace std;

void printMenu();

int main()
{
	char input1 = 'Z';
	string foodName;
	int key, newKey;
	int capacity, index = -1;   //1D array capacity and index
	double price;
	bool success = false;

    Food oneFood;

	//a variable used to represent a Heap object
	Heap* heap1 = nullptr;
	printMenu();

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		input1 = toupper(input1);
		cin.ignore(20, '\n');	//flush the buffer

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the relevant capacity
				cout << "\nPlease enter the heap capacity: ";
				//----
				//----
				cin.ignore(20, '\n');	//flush the buffer
				break;

			//delete the heap, call the destructor explicitly. Re-initialize heap1
			//with capacity 5
			case 'D':
				cout << "\nDelete the heap" << endl;
				//----
				//----
				break;

			case 'E':	//Extract the maximum node
                //----
				//----
				break;

			case 'F':	//Find a food
				cout << "\nEnter the food key you want to search: ";
				cin >> key;
				cin.ignore(20, '\n');	//flush the buffer

				//----
				//----

				break;

			case 'I':	//Insert a Food
				cout << "\nEnter the food name: ";
				getline(cin, foodName);
				cout << "\nEnter food key: ";
				cin >> key;
				cout << "\nEnter the food price: ";
				cin >> price;
				cin.ignore(20, '\n');	//flush the buffer

				//----
				//----
				break;

			case 'K':	//increase the key
				cout << "\nEnter the old food key you want to increase: ";
				cin >> key;
				cout << "\nEnter the new key value: ";
				cin >> newKey;
				cin.ignore(20, '\n');	//flush the buffer

				//----
				//----

				break;

			case 'M':	//get the maximum node
			    //----
				//----

				break;

			case 'P':	//Print heap contents
			    //----
				//----

				break;

			case 'Q':	//Quit
				delete heap1;
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "Unknown action\n";
				break;
		}
	} while (input1 != 'Q');
	return 0;
}

/**The function displays the menu to a user**/
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind a food by key\n";
	cout << "I\t\tInsert a food\n";
	cout << "K\t\tIncrease the key\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}
