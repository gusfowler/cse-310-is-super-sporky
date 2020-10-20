// ASU CSE310 Assignment #5
// Name of Author:
// ASU ID:
// Description: this is the main program that reads input from keyboard,
// it then call hash functions to execute hash commands given in the input.

/**************************************************************************
//(1)Describe here what is your hash function?
//(2)What is the number of collisions you expected?
//(3)Did your hash function work well? Using the test cases, what's your hash
//   table's load factor?
//(4)If you had to change your hash function to reduce the number of collisions,
//   how will you change it?
//----
***************************************************************************/

#include "Hash.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//This function extracts tokens from oneLine and get all info. of a Food
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price);

//This function extracts tokens from oneLine and get a Food key which is
//the combination of FoodID, name and supplierID
void getKey(string oneLine, string& FoodID, string& name, string& supplierID);

int main()
{
    //a variable represents the number of hash table slots
    int size;

    //a variable represents the number of commands
    int numOfCommand;

    //a variable represents the actual command name
    string command;

   string FoodID, name, supplierID;
   double price;
   string delimiter = ",";

	//declare any other necessary variables here
   //----

    cout << "Enter the size of the hash table: ";
	cin >> size;
   cin.ignore(20, '\n');

   //create the hash table with the relevant number of slots
	//----

 do {
		cout << "\nEnter food info.(enter InsertionEnd to terminate): " << endl;
		getline(cin, oneLine);
		if(oneLine.compare("InsertionEnd") == 0)
            break;

      //if command is not InsertionEnd
      //Get one line, call getFoodInfo(), then
      //insert the new Food inside the hash table
      //----

	} while(true);

    cin >> numOfCommand;
    cin.ignore(20, '\n');

	for(int i= 0; i < numOfCommand; i++)
   {
 		//get one line from the input file and extract the first token,
 		//if the token is hashDisplay, call the relevant function in Hash.h
 		//-----

 		//if the token is hashSearch, call the relevant function in Hash.h
 		//----

 		//if the token is hashDelete, call the relevant function in Hash.h
 		//----

      //for all other cases, show the following message
      //cout << "Invalid command" << endl;

   } //end for loop

	return 0;
} //end main

//*******************************************************************
//This function extract the tokens from one line and
//get all Food info.
//*******************************************************************
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price)
{
   string delimiter = ",";

   //finish the remaining codes below
   //----
   //----

   //Note: you can use stod to convert a string into double
   //but you will need c++11 compiler to achieve this
   //for example: price = stod(token);
}

//********************************************************************
//This function extracts the FoodID, name, supplierID from a given line
//These info. forms the key of a Food.
//This function is given to you. Study it.
//********************************************************************
void getKey(string oneLine, string& FoodID, string& name, string& supplierID)
{
  string delimiter = ",";
    int pos=oneLine.find(delimiter);
	 string token = oneLine.substr(0,pos);
	 string command = token;
	 oneLine.erase(0, pos+delimiter.length());

	pos=oneLine.find(delimiter);
	token = oneLine.substr(0,pos);
	foodID = token;
	oneLine.erase(0, pos+delimiter.length());

	pos=oneLine.find(delimiter);
	token = oneLine.substr(0,pos);
	name = token;
	oneLine.erase(0, pos+delimiter.length());

	pos=oneLine.find(delimiter);
	token = oneLine.substr(0,pos);
	supplierID = token;
	oneLine.erase(0, pos+delimiter.length());
}
