// ASU CSE310 Assignment #5
// Name of Author: August Fowler
// ASU ID: 1214774210
// Description: this is where you need to design functions on Hash hashTable,
// such as hashInsert, hashDelete, hashSearch and hashDisplay

#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

class Hash
{
    private:
		LinkedList* hashTable;     //hashTable is a one-dimensional array of LinkedList
		int m;                     //slots number of the hash table
	public:
      Hash(int size);
      ~Hash();
      bool hashInsert(string foodID, string name, string supplierID, double price);
      bool hashDelete(string foodID, string name, string supplierID);
      bool hashSearch(string foodID, string name, string supplierID);
      void hashDisplay();
      int hashFunction(string key);

      //add any other auxiliary functions here
      //----
};

//constructor
Hash::Hash(int size)
{
	hashTable = new LinkedList[size];
	m = size;
}

//Destructor
Hash::~Hash()
{
	//----
      delete[] hashTable;
}

//hashInsert inserts a Food with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string foodID, string name, string supplierID, double price)
{
	//----
      return hashTable[hashFunction(foodID + name + supplierID)].insertFood(foodID, name, supplierID, price);
}

//hashDelete deletes a Food with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashDelete(string foodID, string name, string supplierID)
{
      //----
      if (hashSearch(foodID, name, supplierID)) {
            bool deleted = hashTable[hashFunction(foodID + name + supplierID)].deleteFood(foodID);

            if (deleted) {
                  cout << "\n";
                  cout	<< setw(4) << foodID
                        << setw(30) << name
                        << setw(12) << supplierID
                        << " is deleted from hash table." << endl;
            }

            return deleted;
      } else { return false; }
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of foodID, name and supplierID
bool Hash::hashSearch(string foodID, string name, string supplierID)
{
    //----
    bool found = hashTable[hashFunction(foodID + name + supplierID)].searchFood(foodID);

   if (found)
     cout   << "\n" << left
            << setw(4) << foodID
            << setw(30) << name
            << setw(12) << supplierID
            << " is found inside the hash table." << endl;
	if(!found)
      cout	<< "\n" << left
            << setw(4) << foodID
            << setw(30) << name
            << setw(12) << supplierID
            << " is NOT found inside the hash table." << endl;

      return found;
 }

//This function prints all the elements from the hash hashTable.
void Hash::hashDisplay()
{
	//----
      for (int i = 0; i < m; i++) {
            printf("hashTable[%i], size=%i", i, hashTable[i].getSize());
            hashTable[i].displayList();
            cout << "\n" << endl;
      }
	//----
}

//This is the hash function you will need to design, test and refine
//Given a Food key, the function should return the slot index where it
//will be hashed to
int Hash::hashFunction(string key)
{
      //----
      int hash = 0;
      //Create total of all ASCII values in key
      int ASCII_total = 0;

      int keyLength = key.length();
      char* char_array = new char[keyLength + 1];
      strcpy(char_array, key.c_str());

      for (int i = 0; i < keyLength; i++) {
            ASCII_total += char_array[i];
      }

      // hash by multiplication
      float A = 2 / (sqrt(5) + 1);  //inverse fibonacci
      hash = floor(m * (fmod((ASCII_total * A), 1)));
      return hash;
}
