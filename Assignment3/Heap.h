//********************************************************
// Assignment: ASU CSE310 HW#3
// Your Name:
// ASU ID:
// ASU Email address:
// Description:
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Food represents a food. Each food with a unique key
struct Food
{
	int key;
	string foodName;
	double price;
};

//class Heap represents a Max heap that contains Food objects. Underline data structure is
//a one dimensional array of Food objects.
class Heap
{
    private:
	struct Food* foodArr;	//an array of Food
	int capacity, size;

    public:
	Heap(int capacity);
	~Heap();
	Food* getFoodArr();
	int getSize();
	int getCapacity();
	int isFound(int foodKey);
	bool increaseKey(int index, Food oneFoodwithNewKey);
	bool insert(int key, string foodName, double foodPrice);
	void heapify(int index);
	Food getHeapMax();
	void extractHeapMax();
	int leftChild(int parentIndex);
	int rightChild(int parentIndex);
	int parent(int childIndex);
	void printHeap();
};

//Constructor to dynamically allocate memory for a heap with the specified capacity
Heap::Heap(int capacity)
{
 	//----
 	//----
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
Heap::~Heap()
{
	//----
	//----
	cout << "\nThe number of deleted food items is: " << foodCount << endl;
}

//Finish all the remaining functions according to the project's description
//----
//----

void Heap::printHeap()
{
	//----
	//----

    cout << left;
	cout << setw(5) << foodArr[i].key
         << setw(8) << foodArr[i].foodName
         << setw(8) << fixed << setprecision(2) << foodArr[i].price << endl;

}
