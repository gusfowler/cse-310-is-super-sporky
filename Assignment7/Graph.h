//********************************************************************
// ASU CSE310 Assignment #7
// Name of Author: August Fowler
// ASU ID: 1214774210
// Description: This is the header file that defines a directed graph
//********************************************************************

#include "MinHeap.h"

using namespace std;

class Graph
{
   private:
   int numOfNode;        //number of nodes in the graph
   MinHeap* cityHeap;    //a min-heap of departure City objects

   //feel free to add other necessary functions
   public:
   Graph(int numOfNode, MinHeap* cityHeap);
   void destructor();
   void printGraph();
   void initialize_single_source(string sourceCityName);
   void relax(City u, City v);
   int findOneCity(string aCityName);

   void dijkstra(string sourceCityName);
   void printDijkstraPath(string sourceCityName);
};

//*******************************************************************
//Constructor
Graph::Graph(int numOfNode, MinHeap* cityHeap)
{
   this->numOfNode = numOfNode;
   this->cityHeap = cityHeap;
}

//*******************************************************************
//Destructor Graph::~Graph()
void Graph::destructor()
{
   delete [] cityHeap;
   cityHeap = NULL;
   numOfNode = 0;
}

//Define all remaining functions according to above function declaration
//----

void Graph::printGraph() {
    cityHeap->printHeap();
}

void Graph::initialize_single_source(string sourceCityName) {
    for (int i = 0; i < numOfNode; i++) {
        cityHeap->getCityArr()[i].d = 2000;
        cityHeap->getCityArr()[i].pi = NULL;
        if (cityHeap->getCityArr()[i].cityName.compare(sourceCityName) == 0) {
            cityHeap->getCityArr()[i].d = 0;
        } 
    }
    cityHeap->heapify(0);
}

void Graph::relax(City u, City v) {
    int weight;
    if (u.arrCityList->findArrCity(v.cityName) != NULL) {
        weight = u.arrCityList->findArrCity(v.cityName)->price;
    }

    if (v.d > u.d + weight) {
        v.d = u.d + weight;
        v.pi = &u;
    }

}

int Graph::findOneCity(string aCityName) { return cityHeap->isFound(aCityName); }

//----


//*******************************************************************
//This function performs the dijkstra's shortest path algorithm
void Graph::dijkstra(string sourceCityName)
{
   //----
   int i = 0; //counter
   initialize_single_source(sourceCityName);                    // init source on top
   MinHeap* shortestPathHeap = new MinHeap(numOfNode);          // heap to auto sort to minimum path distance
   
   while (cityHeap->getSize() > 0) {
       City u = cityHeap->getHeapMin();                         // extract least distance City
       cityHeap->extractHeapMin();
       
       for (int i = 0; i < cityHeap->getSize(); i++) {
           relax(u, cityHeap->getCityArr()[i]);                 // calculate distance between src city u and all remaining cities
           cityHeap->heapify(i);                                // run heapify to keep Heap built
       }

       shortestPathHeap->insert(u);                             // insert least distance City into shortestPath
   }
   
   if (cityHeap->getSize() == 0) {
       delete cityHeap;
       cityHeap = shortestPathHeap;
   }
   //----
}

//*********************************************************************************
//This function prints the cheapest price and path after the Dijkstra's algorithm
void Graph::printDijkstraPath(string sourceCityName)
{
   cout << "\nSource City: " << sourceCityName << endl;
   cout << left;
   cout << setw(15) << "\nArrival City" << setw(15) << "Lowest Price"   << setw(15) << "Shortest Path" << endl;
   //----
   dijkstra(sourceCityName);
   printGraph();
   //----

}