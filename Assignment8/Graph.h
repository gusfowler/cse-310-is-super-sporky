//********************************************************************
// ASU CSE310 Assignment #8 Fall 2020
// Name of Author: August Fowler
// ASU ID: 1214774210
// Description: This is the header file that defines an undirected graph
//              with an array of vertices and edges
//********************************************************************

#include "Edge.h"

using namespace std;

class Graph
{
   private:
      int V, E;         //number of vertices and edges in the graph
      City* cityArr;    //an array of City objects
      Edge* edgeArr;    //an array of Edge objects

   public:
      Graph(int numOfCities, int numOfEdges, City* cityArray, Edge* edgeArray);
      void destructor();
      void make_set(City* aCity);
      City* find_set(City* aCity);
      void link(City* aCity, City* bCity);
      void Union(City* aCity, City* bCity);
      void printEdgeArray();
      void MergeSortEdges();
      void mergeSort(Edge* edgeArray, int start, int end);
      void merge(Edge* edgeArray, int start, int mid, int end);

      void MST_Kruskal();
};

//*******************************************************************
//Constructor
Graph::Graph(int numOfCities, int numOfEdges, City* cityArray, Edge* edgeArray)
{
	//----
    this->V = numOfCities;
    this->E = numOfEdges;
    this->cityArr = cityArray;
    this->edgeArr = edgeArray;
	//----
}

//*******************************************************************
//Destructor
void Graph::destructor()
{
	//----
    for (int i = 0; i < E; i++) {
        edgeArr[i].~Edge();
    }
    delete edgeArr;
    delete cityArr;
	//----
}

//*******************************************************************
//Given a City, this function creates a new set whose only member is
//the City.
void Graph::make_set(City* aCity)
{
	//----
    aCity->parent = aCity;
    aCity->rank = 0;
	//----
}

//*******************************************************************
//Given a City, this function returns a pointer to the representative
//of the (unique) set containing 'aCity'
City* Graph::find_set(City* aCity)
{
	//----
    // find top rank of set - moves with recursion
    if (aCity->cityName.compare(aCity->parent->cityName) != 0) {
        aCity->parent = find_set(aCity->parent);
    }
    return aCity->parent;
	//----
}

//*******************************************************************
//Given two cities, this function checks the dynamic sets that contain
//'aCity' and 'bCity' and update their rank and parent info. accordingly
void Graph::link(City* aCity, City* bCity)
{
	//----
    // if cities disjoint, alphabetically higher vertex combined with lower
    if (aCity->cityName.compare(bCity->cityName) != 0) {
        if (aCity->cityName.compare(bCity->cityName) > 0) {
            bCity->parent = aCity;
        } else {
            aCity->parent = bCity;
            // increase rank for balence
            if (aCity->cityName.compare(bCity->cityName) < 0) { bCity->rank += 1; }
        }
    }
	//----
}

//*******************************************************************
//Given two cities, this function unites the dynamic sets that contain
//'aCity' and 'bCity' into a new set that is the union of the two sets.
void Graph::Union(City* aCity, City* bCity)
{
	//----
    link(find_set(aCity), find_set(bCity));
	//----
}

//*******************************************************************
//This function print each of the edges of edge array. It can be
//used as an auxillary function to check the MergeSort result
void Graph::printEdgeArray()
{
	//----
    for (int i = 0; i < E; i++) edgeArr[i].printEdge();
	//----
}

//*******************************************************************
//This function performs the Merge Sort on the graph edges according
//to the weight. Sort all edges in non-decreasing order
void Graph::MergeSortEdges()
{
	//----
    // starts recursion loop
    mergeSort(edgeArr, 0, E-1);
	//----
}

//*******************************************************************
//This function performs the Merge Sort on a sub edgeArray.
void Graph::mergeSort(Edge* edgeArray, int start, int end)
{
	//----
    if (start < end) {
        int middle = (start + end) / 2; // finds middle

        // create subproblems
        mergeSort(edgeArray, start, middle);
        mergeSort(edgeArray, middle + 1, end);

        merge(edgeArray, start, middle, end); // merges subproblems
    }
	//----
}

//*******************************************************************
//This function merges the two sorted sub edgeArray.
void Graph::merge(Edge* edgeArray, int start, int mid, int end)
{
    int n1 = mid-start+1;  //get the length of the first half subarray
    int n2 = end-mid;      //get the length of the second half subarray

    //Dynamically create two new arrays each stored the sorted half
    Edge* left = (Edge*)malloc(sizeof(Edge) * n1);
	Edge* right = (Edge*)malloc(sizeof(Edge) * n2);

	//----
    // fill arrays with sides of array
    for (int i = 0; i < n1; i++) left[i] = edgeArray[start + i]; 
    for (int j = 0; j < n2; j++) right[j] = edgeArray[(mid + 1) + j];

    int leftCount = 0, rightCount = 0, mergeCount = start;
    while (leftCount < n1 && rightCount < n2) {
        // puts smallest of two current in arrs into merged array
        if (left[leftCount].getPrice() <= right[rightCount].getPrice()) {
            edgeArray[mergeCount] = left[leftCount];
            leftCount++;
        } else {
            edgeArray[mergeCount] = right[rightCount];
            rightCount++;
        }
        mergeCount++;
    }

    // if one side has leftover edges, add to end of the array
    while (leftCount < n1) {
        edgeArray[mergeCount] = left[leftCount];
        mergeCount++;
        leftCount++;
    }
    while (rightCount < n2) {
        edgeArray[mergeCount] = right[rightCount];
        mergeCount++;
        rightCount++;
    }
	//----

	//at the end, release the memory left and right occupied
    delete left;
    delete right;
}


//*******************************************************************
//This function performs the Kruskal algorithm on the graph.
void Graph::MST_Kruskal()
{
   cout << "MST Kruskal Algorithm Result\n" << endl;
   double totalWeight = 0.0;

   //----
   // make set for each edge in flight path
   for (int i = 0; i < V; i++) make_set(&(cityArr[i]));
   MergeSortEdges(); // sorts edges in 'non-decreasing order'

   //----
   for (int j = 0; j < E; j++) {
       City* aCity = edgeArr[j].getCity1();
       City* bCity = edgeArr[j].getCity2();

       // if least rank of each set not equal 
       // new set can be found with minimum gain
       if (find_set(aCity) != find_set(bCity)) {
           Union(aCity, bCity); // add edge as part of path
           totalWeight += edgeArr[j].getPrice(); // add weight
           edgeArr[j].printEdge();
       }
   }
   //----

   cout << "=================================================" << endl;
   cout << "Total Price: " << totalWeight << endl;
}