//************************************************************************
// ASU CSE310 Assignment #6 Fall 2020
// Author: August Fowler
// ASU ID: 1214774210
// Description: this is the main program that reads input from keyboard,
// it then execute various red-black tree operations which is given in the input.
//**************************************************************************

#include "RedBlackTree.h"

using namespace std;

//This function used to get the key of a Food
void getFoodKey(string oneLine, string& foodID, string& name, string& supplierID);

//This function used to get all info. of a Food
void getFoodInfo(string oneLine, string& foodID, string& name, string& supplierID, double& price);

int main()
{
   string foodID, name, supplierID;
   double price;
   string command, oneLine, token;
   string delimiter = ",";

   int pos = 0;

   RedBlackTree *rbTree = new RedBlackTree();
   do
   {
      getline(cin, oneLine);
      pos = oneLine.find(delimiter);
      token = oneLine.substr(0, pos);
      command = token;
      oneLine.erase(0, pos + delimiter.length());

      if(command.compare("quit")==0)
      {
         cout << "\nCommand: quit" << endl;

         //call destructor
         //----
         break;
      }
      else if(command.compare("tree_preorder")==0)
      {
         cout << "\nCommand: tree_preorder" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_inorder")==0)
      {
         cout << "\nCommand: tree_inorder" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_postorder")==0)
      {
         cout << "\nCommand: tree_postorder" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_minimum")==0)
      {
         cout << "\nCommand: tree_minimum" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_maximum")==0)
      {
         cout << "\nCommand: tree_maximum" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_predecessor")==0)
      {
         getKey(oneLine, foodID, name, supplierID);
         cout << "\nCommand: tree_predecessor" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_successor")==0)
      {
         getKey(oneLine, foodID, name, supplierID);
         cout << "\nCommand: tree_successor" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_search")==0)
      {
         getKey(oneLine, foodID, name, supplierID);
         cout << "\nCommand: tree_search" << endl;

         //call the relevant function
         //----
      }
      else if(command.compare("tree_insert")==0)
      {
         getProductInfo(oneLine, foodID, name, supplierID, price);
         cout << "\nCommand: tree_insert" << endl;
         cout << left;
         cout << setw(5) << foodID
              << setw(35) << name
              << setw(15) << supplierID
              << setw(5) << fixed << setprecision(2) << price << endl;

         //call the relevant function
         //----
      }
   } while(true);  //continue until 'quit'
   return 0;
}

//********************************************************************
//This function from one line, extracts the foodID, name, supplierID
//information of a Food
void getFoodKey(string oneLine, string& foodID, string& name, string& supplierID)
{
   //----
   //----
}

//**************************************************************
//This function from one line, get all Food's info.
void getFoodInfo(string oneLine, string& foodID, string& name, string& supplierID, double& price)
{
   //----
   //
}