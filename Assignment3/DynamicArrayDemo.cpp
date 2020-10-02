//DynamicArrayDemo.cpp
//Author: Sherry Feng
//Description: this program demonstrates dynamically allocate memory for a 1D
//             array of objects.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Rect represents a rectangle. Each Rect has width and height
struct Rect
{
	int width, height;

	int computeArea()
	{
	    return width * height;
	}
};

int main()
{
    //1D array of Rect objects that will be created dynamically
    struct Rect* rectArr;
    int capacity, size = 0;

    cout << "Enter the capacity of the array: ";
    cin >> capacity;

    //dynamically allocate memory for this array
    rectArr = new Rect[capacity];

    //randomly create few Rect objects and put them inside the rectArr.
    //For demonstration purpose, for ptrRect, I used pointer on purpose.
    struct Rect* ptrRect = new (struct Rect);
    ptrRect->width = 7;
	ptrRect->height = 5;

	//put ptrRect inside the array
	rectArr[0] = *ptrRect;
	size++;

	//create another Rect object by using the constructor
	Rect newRect2, newRect3;
	newRect2.width = 3;
	newRect2.height = 2;

	newRect3.width = 7;
	newRect3.height = 4;

	//put newRect2 inside the array. Notice the difference between ptrRect and newRect2
	rectArr[1] = newRect2;
	size++;

	rectArr[2] = newRect3;
	size++;

    //compute and output the area of these two Rect objects
    cout << "Area for 1st rectangle is: " << ptrRect->computeArea() << endl;
    cout << "Area for 2nd rectangle is: " << newRect2.computeArea() << endl;

    //we can also use index to traverse the array instead
    int totalArea = 0;
    for(int i = 0; i < size; i++)
    {
        totalArea += rectArr[i].computeArea();
    }
    cout << "There are " << size << " rectangles and total area is " << totalArea << endl;

    //delete the rectArr
    cout << "Deleting the array..." << endl;
    delete[] rectArr;
}
