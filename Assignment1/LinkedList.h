// Assignment: #1
// Your Name:
// ASU ID:
// ASU Email Address:
// Description:

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Food represents a food information
struct Food
{
    string foodName;
    int id;
    double price;
    struct Food* next;
};

//class LinkedList will contains a linked list of foods
class LinkedList
{
    private:
        struct Food* head;

    public:
        LinkedList();
        ~LinkedList();
        bool isFound(int foodId);
        bool add(string foodName, int foodId, double foodPrice);
        bool removeById(int foodId);
        bool removeByName(string foodName);
        bool changeFoodName(int foodId, string newFoodName);
        bool changeFoodPrice(int foodId, double newPrice);
        void printFoodList();
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
    int foodCount = 0;
    //----
    //----
    cout << "The number of deleted food items is: " << foodCount <<"\n";
}

//A function to identify whether the parameterized food is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::isFound(int foodId)
{
	//----
	//----
}

//Creates a new node and inserts it into the list at the right place.
//It maintains an alphabetical ordering of foods by their names. Each
//food item has a unique id, if two food items have exactly the same name,
//then insert it into the list in the increasing order of their IDs.
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::add(string foodName, int foodId, double foodPrice)
{
     //----
     //----
}

//Removes the given food by Id from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeById(int foodId)
{
	//----
	//----
}

//Removes the given food by name from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise. Note: all foods with
//the parameterized name should be removed from the list.
bool LinkedList::removeByName(string foodName)
{
	//----
	//----
}

//Modifies the name of the given Food item. Return true if it modifies successfully and
//false otherwise. Note: after changing a food name, the linked list must still be
//in alphabetical order of foods name
bool LinkedList::changeFoodName(int oldFoodId, string newFoodName)
{
	//----
	//----
}

//Modifies the price of the given food item. Return true if it modifies successfully and
//false otherwise.
bool LinkedList::changeFoodPrice(int foodId, double newPrice)
{
    //----
    //----
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printFoodList()
{
    //----
    //----
}
