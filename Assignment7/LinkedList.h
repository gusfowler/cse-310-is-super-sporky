//********************************************************************
// ASU CSE310 Assignment #7
// Name:
// ASU ID:
// Description:

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
};

//Define all remaining functions according to above function declaration
//----
//----





//Prints all the elements in the linked list starting from the head.
void LinkedList::printArrCityList()
{
    struct ArrCity *temp = head;

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