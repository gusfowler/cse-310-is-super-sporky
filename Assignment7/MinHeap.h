//********************************************************
// Assignment: ASU CSE310 HW#7
// Your Name: August Fowler
// ASU ID: 1214774210
// ASU Email address: amfowle3@asu.edu
// Description: MinHeap of LinkedLists to store data needed by Graph.h
//********************************************************
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)
#define PARENT(i) ((i - 1) / 2)
#include "LinkedList.h"

using namespace std;

//represent each node of the graph which is a departure City
struct City
{
    string cityName;
    int d;
    struct City* pi;
    LinkedList* arrCityList;
};

//class Heap represents a Min-heap that contains City objects. Underline data structure is
//a one dimensional array of City objects.
class MinHeap
{
    private:
        struct City* cityArr;	//an array of City
        int capacity, size;

	public:
        MinHeap(int capacity);
        ~MinHeap();

        City* getCityArr();
        int getSize();
        int getCapacity();
        int isFound(string cityName);
        bool decreaseKey(int index, City oneCitywithNewD);
        bool insert(City oneCity);
        void heapify(int index);
        City getHeapMin() { return cityArr[0]; }
        void extractHeapMin();
        int leftChild(int parentIndex) { return LEFT(parentIndex); }
        int rightChild(int parentIndex) { return RIGHT(parentIndex); }
        int parent(int childIndex) { return PARENT(childIndex); }
        void printHeap();

        void build_min_heap();      //***newly added function
        void swap(City* x, City* y);
        void sort();
 };

//Constructor to dynamically allocate memory for a heap with the specified capacity
MinHeap::MinHeap(int capacity)
{
 	cityArr = new City[capacity];
	this->capacity = capacity;
	size = 0;
}

//Define all remaining functions according to above function declaration
//----

MinHeap::~MinHeap() {
    if (!(getSize() < 1)) {
        for (int i = 0; i < getSize(); i++) {
            LinkedList* toDelete = cityArr[i].arrCityList;
            delete toDelete;
        }
        delete[] cityArr;
    }
}

City* MinHeap::getCityArr() {
    return cityArr;
}

int MinHeap::getSize() { return size; }

int MinHeap::getCapacity() { return capacity; }

int MinHeap::isFound(string cityName) {
    int output = -1;

    if (!(getSize() < 1)) {
        for (int i = 0; i < getSize(); i++) {
            if (cityArr[i].cityName.compare(cityName) == 0) {
                output = i;
            }
        }
    }

    return output;
}

bool MinHeap::decreaseKey(int index, City oneCitywithNewD) {
    cityArr[index] = oneCitywithNewD;

    while (index != 0 && cityArr[PARENT(index)].d > cityArr[index].d) {
        swap(&cityArr[PARENT(index)], &cityArr[index]);
        index = PARENT(index);
    }
}

void MinHeap::swap(City* x, City* y) {
    City temp = *x;
    *x = *y;
    *y = temp;
}

bool MinHeap::insert(City oneCity) {
    bool output = false;

    if (isFound(oneCity.cityName) == -1) {
        if (size < capacity) {
            cityArr[size] = oneCity;
            size += 1;
            build_min_heap();
            output = true;
        } else {
            struct City* tempArr = new City[(capacity * 2) + 1];
			for (int i = 0; i < size; i++) {
				tempArr[i] = cityArr[i];
			}
			delete[] cityArr;
			cityArr = tempArr;
			capacity = 2 * capacity;
            output = insert(oneCity);
        }
    }

    return output;
}

void MinHeap::build_min_heap() {
    for (int i = (size / 2) - 1; i >= 0; i--) {
		heapify(i);	
	}
}

void MinHeap::heapify(int index) {
    int smallest = index;
    int left = LEFT(index);
    int right = RIGHT(index);

    if (left < size && cityArr[left].d < cityArr[index].d) { smallest = left; }
    if (right < size && cityArr[right].d < cityArr[index].d) { smallest = right; }
    if (smallest != index) {
        swap(&cityArr[index], &cityArr[smallest]);
        heapify(smallest);
    }
}

//----


//****************************************************************
//**Changed a little bit. Once extractedHeapMin, the procedure will
//put the last element at index 0 and re-heapify the array. We will
//keep the extracted City object
void MinHeap::extractHeapMin()
{
	if (getSize() < 1)
	{
		cout << "\nError: empty heap, cannot extract min" << endl;
	}
	//----
    else {
        // swap first and last
        City temp = cityArr[0];
        cityArr[0] = cityArr[size - 1];
        size -= 1;

        // call heapify
        heapify(0);
    }
	//----
}

//*********************************************************
void MinHeap::printHeap()
{
	if (cityArr == NULL || size == 0)
		cout << "\nEmpty heap, no elements" << endl;
	else
	{
		cout << "\nHeap size = " << getSize() << "\n" << endl;

		cout << left;
		cout << setw(15) << "City Name"
             << setw(12) << "d Value"
             << setw(15) << "PI"
             << "Arrival City List" << endl;

		for (int i = 0; i < getSize(); i++)
		{
		    cout << left;
			cout << setw(15) << cityArr[i].cityName
                 << setw(12) << cityArr[i].d;
            if(cityArr[i].pi != NULL)
                    cout << setw(15) << cityArr[i].pi->cityName;
            else
                    cout << setw(15) << "No Parent";
    		 cityArr[i].arrCityList->printArrCityList();
		}
	}
}