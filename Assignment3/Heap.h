//********************************************************
// Assignment: ASU CSE310 HW#3
// Your Name: August Fowler
// ASU ID: 1214774210
// ASU Email address: amfowle3@asu.edu
// Description: 
//********************************************************
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)
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
	 foodArr = new Food[capacity]; 	// init array
	 this->capacity = capacity;		// set capacity in this
	 this->size = 0;				// sets current size to zero
 	//----
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
Heap::~Heap()
{
	//----
	int foodCount = getSize();
	delete[] foodArr;
	//----
	cout << "\nThe number of deleted food items is: " << foodCount << endl;
}

//Finish all the remaining functions according to the project's description
//----
Food* Heap::getFoodArr() {
	return foodArr;
}

int Heap::getSize() {
	return size;
}

int Heap::getCapacity() {
	return capacity;
}

int Heap::isFound(int foodKey) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (foodArr[i].key == foodKey) {
			index = i;
			return index;
		}
	}
	return index;
}

bool Heap::increaseKey(int index, Food foodwithNewKey) {	// not finished!! need to heapify
	bool success = false;

	try {
		foodArr[index].key = foodwithNewKey.key;
		success = true;
	} catch (exception e) {
		cout << "increaseKey exception:\t" << e.what() << endl;
	}

	return success;
}

bool Heap::insert(int key, string foodName, double foodPrice) {		// not finished !!

}

void Heap::heapify(int index) {
	int largest = index;
	int left = LEFT(index);
	int right = RIGHT(index);

	// if left leaf is larger than root
	if (left < size && foodArr[left].key > foodArr[largest].key) {
		largest = left;
	}

	// if right leaf is larger than root
	if (right < size && foodArr[right].key > foodArr[largest].key) {
		largest = right;
	}

	if (largest != index) {
		//swap index and largest

		heapify(largest);
	}
}
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
