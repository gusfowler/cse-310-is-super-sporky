//********************************************************
// Assignment: ASU CSE310 HW#7
// Your Name:
// ASU ID:
// ASU Email address:
// Description:
//********************************************************
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
        City getHeapMin();
        void extractHeapMin();
        int leftChild(int parentIndex);
        int rightChild(int parentIndex);
        int parent(int childIndex);
        void printHeap();

        void build_min_heap();      //***newly added function
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