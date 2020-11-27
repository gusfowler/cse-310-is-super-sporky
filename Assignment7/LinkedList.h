//********************************************************************
// ASU CSE310 Assignment #7
// Name: August Fowler
// ASU ID: 1214774210
// Description: LinkedList to store data

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//struct ArrCity represents an arrival city information with
//price info. from the departure city
struct ArrCity
{
    string arrCityName;
    int price;
    struct ArrCity* next;
};

//class LinkedList will contains a linked list of ArrCity
class LinkedList
{
    private:
        struct ArrCity* head;

    public:
        LinkedList();
        ~LinkedList();
        ArrCity* getHead();
        ArrCity* findArrCity(string aCity);
        bool addArrCity(string aCity, int price);
        void printArrCityList();
        void alphabetical_sort();
};

//Define all remaining functions according to above function declaration
//----

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    if (head != NULL) {
        struct ArrCity* current = head;
        while (current != NULL) {
            struct ArrCity* toDelete = current;
            current = current->next;
            delete current;
        }
    }
}

ArrCity* LinkedList::getHead() {
    return head;
}

ArrCity* LinkedList::findArrCity(string aCity) {
    struct ArrCity* current = head;
    bool found = false;
    
    while (current != NULL) {
        if (current->arrCityName.compare(aCity) == 0) {
            found = true;
            break;  
        } else {
            current = current->next;
        }
    }
    if (found == false && current == NULL) { return NULL; }
    return current;
}

bool LinkedList::addArrCity(string aCity, int price) {
    bool output = false;

    struct ArrCity* newNode = new ArrCity;
    newNode->next = NULL;
    newNode->arrCityName = aCity;
    newNode->price = price;

    if (head == NULL) {
        head = newNode;
        output = true;
    } else {
        struct ArrCity* current = head;
        
        while (current->next != NULL) { current = current->next; }
        current->next = newNode;
        output = true;
    }

    return output;
}

//----

//Prints all the elements in the linked list starting from the head.
void LinkedList::printArrCityList()
{
    struct ArrCity *temp = head;

    // flip the head to induce abc order

	if(head == NULL)
    {
		cout << "Arrival city list is empty\n";
		return;
	}
	while(temp!= NULL)
    {
		cout << temp->arrCityName << "(" << temp->price << "),";
		temp = temp->next;
	}
	cout <<"\n";
}