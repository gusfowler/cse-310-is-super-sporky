// ASU CSE310 Assignment #5
// Name of Author: August Fowler
// ASU ID: 1214774210
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
	if (head != NULL) {
		struct Food *current = head;
		while (current != NULL) {
			struct Food *toDelete = current;
			current = current->next;
			delete toDelete;
		}
	}
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
	bool success = false;

	struct Food newFood;
	newFood.foodID = foodID;
	newFood.name = name;
	newFood.supplierID = supplierID;
	newFood.price = price;
	newFood.next = NULL;

	if (head == NULL) {
		head = &newFood;
		size = 1;
		success = true;
	} else {
		newFood.next = head;
		head = &newFood;
		size += 1;
		success = true;
	}

	return success;
 }

//Delete the food with the given foodID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteFood(string foodID)
{
	//----
	bool success = false;

	if (head != NULL) {
		struct Food *current = head;
		struct Food *previous = NULL;
		while (current != NULL) {
			if (current->foodID.compare(foodID) == 0) {
				if (previous == NULL) {
					head = current->next;
					delete current;
					size -= 1;
					success = true;
				}
			}
			previous = current;
			current = current->next;
		}
	}

	return success;
}

//This function searches the food list with the given foodID
//returns true if it is found, otherwise return false.
bool LinkedList::searchFood(string foodID)
{
	//----
	bool success = false;

	if (head != NULL) {
		struct Food *current = head;
		while (current != NULL) {
			if (current->foodID.compare(foodID) == 0) {
				success = true;
				return success;
			}
			current = current->next;
		}
	}

	return success;
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
