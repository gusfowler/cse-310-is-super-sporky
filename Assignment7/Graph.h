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
   void relax(City &u, City &v);
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
        if (cityHeap->getCityArr()[i].cityName.compare(sourceCityName) == 0) {
            cityHeap->getCityArr()[i].d = 0;
        } 
    }
    cityHeap->build_min_heap();
}

void Graph::relax(City &u, City &v) {
    int weight = 0;
    bool relaxed = false;
    
    if (u.arrCityList->findArrCity(v.cityName) != NULL) {
        weight = u.arrCityList->findArrCity(v.cityName)->price;
        if (v.d > u.d + weight) {
            v.d = u.d + weight;
            v.pi = &u;
            relaxed = true;
        }
    }
}

int Graph::findOneCity(string aCityName) { return cityHeap->isFound(aCityName); }

//----


//*******************************************************************
//This function performs the dijkstra's shortest path algorithm
void Graph::dijkstra(string sourceCityName)
{
   //----
   initialize_single_source(sourceCityName);                    // init source on top
   int counter = 0;
   int limit = cityHeap->getSize();

   while (limit > counter) {
       for (int i = 0; i < cityHeap->getSize(); i++) {
           relax(cityHeap->getCityArr()[counter], cityHeap->getCityArr()[i]);                 // calculate distance between src city u and all remaining cities
           cityHeap->build_min_heap();                                                        // run build heap to keep the heap in order
       }
       
       counter += 1;
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
    MinHeap tempHeap = MinHeap(numOfNode);              // create a temporary heap to use as an iterator without breaking the pointer connections formed on pi
    for (int i = 0; i < cityHeap->getSize(); i++) {
        tempHeap.insert(cityHeap->getCityArr()[i]);
    }

   while(tempHeap.getSize() > 0) {
       City current = cityHeap->getCityArr()[cityHeap->isFound(tempHeap.getHeapMin().cityName)];    // iterative step
       tempHeap.extractHeapMin();
       cout << setw(15) << current.cityName << setw(15) << current.d << setw(15);       // formatting
       string path = current.cityName;
       if (current.pi != NULL) {
           City* pi = current.pi;
           int count = 0;
           while (pi != NULL && count < cityHeap->getSize()) {
               path = pi->cityName + "->" + path;
               pi = pi->pi;
               count += 1;
           } 
       }
       cout << path << endl; 
   }
   //----

}