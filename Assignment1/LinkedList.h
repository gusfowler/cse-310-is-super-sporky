// Assignment: #1
// Your Name: August Fowler
// ASU ID: 1214774210
// ASU Email Address: amfowle3@asu.edu
// Description: Food linked list header file

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

    if (this->head != NULL) {
        struct Food* current = this->head;

        while (current != NULL) {
            struct Food* toDelete = current;
            current = toDelete->next;
            delete toDelete;
            foodCount += 1;
        }
    }

    //----
    cout << "The number of deleted food items is: " << foodCount <<"\n";
}

//A function to identify whether the parameterized food is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::isFound(int foodId)
{
	//----
    bool isFound = false;
    struct Food* current = this->head;

    while (current != NULL) {
        if (current->id == foodId) { 
            isFound = true;
            break;
            }
    }

    return isFound;
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
    bool successful = false;

    struct Food newFood;
    newFood.foodName = foodName;
    newFood.id = foodId;
    newFood.foodName = foodPrice;
    newFood.next = NULL;

    if (this->head == NULL) {
        this->head = &newFood;
        successful = true;
    } else {
        struct Food* current = this->head;
        struct Food* previous = NULL;
        int counter = 0;
        while (current != NULL) {
            int comparisonValue = foodName.compare(current->foodName);
            
            if (comparisonValue == 0) {
                if (newFood.id > current->id) {
                    if (counter == 0) {
                        newFood.next = current;
                        this->head = &newFood;

                        successful = true;
                        break;
                    } else if (previous != NULL) {
                        newFood.next = current;
                        previous->next = &newFood;
                        successful = true;
                        break;
                    }
                } else if (newFood.id < current->id) {
                    newFood.next = current->next;
                    current->next = &newFood;
                    successful = true;
                    break;
                }
            } else if (comparisonValue > 0) {
                if (counter == 0) {
                    newFood.next = current;
                    this->head = &newFood;

                    successful = true;
                    break;
                } else if (previous != NULL) {
                    newFood.next = current;
                    previous->next = &newFood;
                    successful = true;
                    break;
                }
            } 
            previous = current;
            current = current->next;
            counter++;
        }
    }
    
    return successful;
     //----
}

//Removes the given food by Id from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeById(int foodId)
{
	//----
    bool successful = false;
    struct Food* current = this->head;
    struct Food* previous = NULL;

    while (current != NULL) {
        if (current->id == foodId) {
            if (previous != NULL) {
                previous->next = current->next;
                delete current;
                successful = true;
                break;
            } else {
                this->head = current->next;
                delete current;
                successful = true;
                break;
            }
        }
        previous = current;
        current = current->next;
    }

    return successful;
	//----
}

//Removes the given food by name from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise. Note: all foods with
//the parameterized name should be removed from the list.
bool LinkedList::removeByName(string foodName)
{
	//----
    bool successful = false;
    struct Food* current = this->head;
    struct Food* previous = NULL;

    while (current != NULL) {
        if (current->foodName.compare(foodName) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
                delete current;
                successful = true;
                break;
            } else {
                this->head = current->next;
                delete current;
                successful = true;
                break;
            }
        }
        previous = current;
        current = current->next;
    }

    return successful;
	//----
}

//Modifies the name of the given Food item. Return true if it modifies successfully and
//false otherwise. Note: after changing a food name, the linked list must still be
//in alphabetical order of foods name
bool LinkedList::changeFoodName(int oldFoodId, string newFoodName)
{
	//----
    bool successful = false;
    struct Food* current = this->head;

    while (current != NULL) {
        if (current->id == oldFoodId) {
            struct Food tempFood = *current;
            tempFood.foodName = newFoodName;
            if(removeById(oldFoodId)) successful = add(tempFood.foodName, tempFood.id, tempFood.price);
            break;
        }
        current = current->next;
    }

    return successful;
	//----
}

//Modifies the price of the given food item. Return true if it modifies successfully and
//false otherwise.
bool LinkedList::changeFoodPrice(int foodId, double newPrice)
{
    //----
    bool successful = false;
    struct Food* current = this->head;

    while (current != NULL) {
        if (current->id == foodId) {
            current->price = newPrice;
        }
        current = current->next;
    }

    return successful;
    //----
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printFoodList()
{
    //----
    struct Food* current = this->head;

    while (current != NULL) {
        printf("%-7s%5i$%7d.2", current->foodName, current->id, current->price);
        current = current->next;
    }
    //----
}
