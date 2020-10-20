// ASU CSE310 Assignment #5
// Name of Author:
// ASU ID:
// Description: A simple linked list that implements a list of Food objects. A user can
//              perform searching, insertion or deletion on the linked list.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Food
{
	string foodID, name, supplierID;
	double price;
	struct Food* next;
};

class LinkedList
{
	private:
		struct Food* head;
		int size;
    public:
       	LinkedList();
       	~LinkedList();
       	Food* getHead();
       	int getSize();
       	bool insertFood(string foodID, string name, string supplierID, double price);
       	bool deleteFood(string foodID);
       	bool searchFood(string foodID);
       	void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
	//----
}

//Accessor for the head
Food* LinkedList::getHead()
{
    return head;
}

//Return number of foods inside the Linked list
int LinkedList::getSize()
{
	return size;
}

//Insert the parameter food at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertFood(string foodID, string name, string supplierID, double price)
{
    //----
 }

//Delete the food with the given foodID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFood(string foodID)
{
	//----
}

//This function searches the food list with the given foodID
//returns true if it is found, otherwise return false.
bool LinkedList::searchFood(string foodID)
{
	//----
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
   struct Food *temp = head;
	if(head == NULL)
    {
		return;
	}
	while(temp != NULL)
    {
      cout << left;
      cout << setw(4) << temp->foodID
           << setw(30) << temp->name
           << setw(12) << temp->supplierID
           << setw(8) << temp->price << endl;
      temp = temp->next;
	}
}
