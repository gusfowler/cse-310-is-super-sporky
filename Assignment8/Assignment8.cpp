//************************************************************************
// ASU CSE310 Assignment #8 Fall 2020
// ASU ID:
// Name:
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph.
// //---- is where you need to add your own codes
//**************************************************************************

#include "Graph.h"

using namespace std;

void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price);
int searchCity(City* oneCityArray,int size, string oneCityName);

int main()
{
    int V, E;        //number of vertices and edges

    //cout << "Enter number of vertices and edges: " << endl;
    cin >> V >> E;
    cin.ignore(20, '\n');

    //a City array used to store all vertices (Cities) of the graph
    City* cityArray = new City[V];

    //an array used to store all edges of the graph
    Edge* edgeArray = new Edge[E];

    //----
    //----

    int i = 0, j = 0; //index for cityArray and edgeArray

    //local variables
    City* city1;
    City* city2;
    Edge* aNewEdge;

    string oneLine;

    //cout << "Enter one departure and its arrival city info." << endl;
    getline(cin, oneLine);

    while(oneLine.compare("End") != 0)
    {
        //get one line of the input, extract the first token
        //create a City if it doesn't exist in cityArray,
        //insert it inside the cityArray. This will be first point
        //for aNewEdge
        //----
        string delimiter = ",";
        int pos = oneLine.find(delimiter);
        string departCity = oneLine.substr(0, pos);

        int searchedIndex = searchCity(cityArray, V, departCity);
        if (searchedIndex != -1) {
            // city exists
            city1 = &(cityArray[searchedIndex]);
        } else {
            // add new city
            cityArray[i] = *(new City(departCity));
            city1 = &(cityArray[i]);
            i++;
        }
        oneLine.erase(0, pos + delimiter.length());
        //----

        //extract the arrival city info. check whether it exists in
        //cityArray or not, if not, create a new City, add it inside.
        //This city will be the second point for aNewEdge
        //----
        while (!oneLine.empty()) {
            if (oneLine.compare(",") != 0) {
                string arrivalCity = "";
                double price = 0.0;
                pos = oneLine.find(delimiter);
                getArrCityInfo(oneLine.substr(0, pos), arrivalCity, price);
                oneLine.erase(0, pos + delimiter.length());

                int searchedIndex = searchCity(cityArray, V, arrivalCity);
                if (searchedIndex != -1) {
                    city2 = &(cityArray[searchedIndex]);
                } else {
                    cityArray[i] = *(new City(arrivalCity));
                    city2 = &(cityArray[i]);
                    i++;
                }

                //by using the two cities we got above, create a new edge, add
                //it inside edgeArray
                edgeArray[j] = *(new Edge(city1, city2, price));
                j++;
            } else {
                oneLine.erase(0, oneLine.length());
            }
        }
        
        //get next line
        //cout << "Enter one departure and its arrival city info." << endl;
        getline(cin, oneLine);
    }   //repeat until the 'End'

    //Create a Graph object by using cityArray and edgeArray
    Graph flightGraph = Graph(V, E, cityArray, edgeArray);
    //----

    //Run Kruskal MST algorithm on above graph
    flightGraph.MST_Kruskal();
    //----
}

//****************************************************************
//By giving a string, for example 'Dallas(456.5)', this function
//extract the arrival city name 'Dallas' and air ticket price '456.5'
//Note: the delimeter is left or right parenthesis
//****************************************************************
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price)
{
   string delimiter1 = "(", delimiter2 = ")";
   int pos=oneArrCityInfo.find(delimiter1);
   string token = oneArrCityInfo.substr(0,pos);
   arrCityName = token;

   oneArrCityInfo.erase(0, pos+delimiter1.length());

   pos = oneArrCityInfo.find(delimiter2);
   token = oneArrCityInfo.substr(0,pos);
   price = stod(token);
   oneArrCityInfo.erase(0, pos+delimiter2.length());
}

//*********************************************************************
//Given a city name, this function searches cityArray and it return the
//index of the City if it already exists, otherwise it returns -1
//****************************************************************
int searchCity(City* oneCityArray, int arraySize, string oneCityName)
{
   //----
   int index = -1;
   for (int i = 0; i < arraySize; i++) {
       if (oneCityArray[i].cityName.compare(oneCityName) == 0) index = i;
   }
   return index;
   //----
}