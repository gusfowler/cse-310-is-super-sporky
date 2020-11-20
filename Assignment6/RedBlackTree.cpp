//************************************************************************
// ASU CSE310 Assignment #6 Fall 2020
// Name of Author: August Fowler
// ASU ID: 1214774210
// Description: Red black tree implementation. See RedBlackTree.h
//              for the tree definition. You need to add your own
//              code at //---- position
//************************************************************************

#include "RedBlackTree.h"

using namespace std;

//*******************************************************************
//constructor
RedBlackTree::RedBlackTree()
{
	root = NULL;
}

//*******************************************************************
//destructor
RedBlackTree::~RedBlackTree()
{
	int nodeSize = deleteNode(root);
	cout << "The number of nodes deleted: " << nodeSize << endl;
}

//**************************************************************
//This function return the root of the red-black tree
Node* RedBlackTree::getRoot()
{
	return this->root;
}

//*******************************************************************
//delete the sub-tree rooted at 'node' and return number of nodes deleted
//This can be defined as a recursive function
int RedBlackTree::deleteNode(Node *node)
{
    if(node == NULL)
    	return 0;
	else
	{
	    //add your codes here
        Node* left = node->leftChild;
        Node* right = node->rightChild;
        delete node;
        return this->deleteNode(left) + this->deleteNode(right) + 1;
	    //----
	}
}

//****************************************************************
//This is the general BST insertion operation.
//It does not care about the color of the newly added node.
void RedBlackTree::insertNode(Node *node)
{
	if(node == NULL)
		return;
	if(this->root == NULL) // if the tree is empty
   {
		//add your codes here
        this->root = node;
		//----
	}
	else
   {
		//add your codes here
        Node * current = this->root;
        Node * previous = NULL;
        bool right = false;
        while (current != NULL) {
            if (current->foodID.compare(node->foodID) > 0) {
                previous = current;
                current = current->rightChild;
                right = true;
            } else if (current->foodID.compare(node->foodID) < 0) {
                previous = current;
                current = current->leftChild;
            } else {
                if (current->name.compare(node->name) > 0) {
                    previous = current;
                    current = current->rightChild;
                    right = true;
                } else if (current->name.compare(node->name) < 0) {
                    previous = current;
                    current = current->leftChild;
                } else {
                    if (current->supplierID.compare(node->supplierID) > 0) {
                        previous = current;
                        current = current->rightChild;
                        right = true;
                    } else if (current->supplierID.compare(node->supplierID) < 0) {
                        previous = current;
                        current = current->leftChild;
                    }
                }
            }
        }
        node->parent = previous;
        if (right) { previous->rightChild = node; }
        else { previous->leftChild = node; }
		//----
	}

	//At the end, need to call fixup() in case the newly
	//added node's parent is also RED
	fixUp(node);
}

//*******************************************************************
//At beginning, each newly added node will always be RED,
//this may violate the red-black tree property #4. fixUp()
//function will restore the property.
void RedBlackTree::fixUp(Node *z)
{
    if(z == root)
    {
		z->color = "BLACK";
		return;
	 }

	 //if z's color is 'RED' and its parent's color is also 'RED'
    while(z->color.compare("RED") == 0 &&
          z->parent != NULL &&
          z->parent->color.compare("RED") == 0)
    {
       //add your codes here
       //----
       Node* grandparent = z->parent->parent;
       Node* uncle = this->getRoot();
       if(z->parent == grandparent->leftChild) {
                    if(grandparent->rightChild) { 
                        uncle = grandparent->rightChild; 
                    }
                    if(uncle->color.compare("RED") == 0){
                        z->parent->color = "BLACK";
                        uncle->color = "BLACK";
                        grandparent->color = "RED";
                        if(grandparent != root) { z = grandparent; }
                        else { break; }
                    }
                    else if(z == grandparent->leftChild->rightChild) {
                       leftRotate(z->parent);
                    }
                    else {
                        z->parent->color = "BLACK";
                        grandparent->color = "RED";
                        rightRotate(grandparent);
                        if(grandparent!= root) { 
                            z = grandparent; 
                        }
                        else { break; }
                    }
                }
                else {
                    if(grandparent->leftChild) { uncle = grandparent->leftChild; }
                    if(uncle->color.compare("RED") == 0){
                        z->parent->color = "BLACK";
                        uncle->color = "BLACK";
                        grandparent->color = "RED";
                        if(grandparent != root){ 
                            z = grandparent; 
                        }
                        else { break; }
                    }
                    else if(z == grandparent->rightChild->leftChild){
                        rightRotate(z->parent);
                    }
                    else {
                        z->parent->color = "BLACK";
                        grandparent->color = "RED";
                        leftRotate(grandparent);
                        if(grandparent != root){ z = grandparent; }
                        else { break; }
                    }
                }
       //----
    }//end while

    //make sure the root is always 'BLACK'
    this->root->color = "BLACK";
}

//*****************************************************
//This function print the pre-order traversal of the
//subtree rooted at 'node'.It's a recursive function - Root, Left, Right
void RedBlackTree::preOrderTraversal(Node *node)
{
	if(node == NULL)
   {
		return;
	}
	else
   {
       //add your codes here
       //----
       this->print(node);
       this->preOrderTraversal(node->leftChild);
       this->preOrderTraversal(node->rightChild);
	   //----
	}
}

//**************************************************
//This function print the in-order traversal of the
//subtree rooted at 'node'.It's a recursive function - Left, Root, Right
void RedBlackTree::inorderTraversal(Node *node)
{
   if(node == NULL)
   {
		return;
	}
	else
   {
       //add your codes here
       //----
       this->inorderTraversal(node->leftChild);
       this->print(node);
       this->inorderTraversal(node->rightChild);
	   //----
	}
}

//**************************************************
//This function print the post-order traversal of the
//subtree rooted at 'node'.It's a recursive function - Left, Right, Root
void RedBlackTree::postOrderTraversal(Node *node)
{
   if(node == NULL)
   {
		return;
	}
	else
   {
       //add your codes here
       //----
       this->postOrderTraversal(node->leftChild);
       this->postOrderTraversal(node->rightChild);
       this->print(node);
	   //----
	}
}

//**************************************************************
//This function returns a pointer points to the minimum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMinimumNode(Node *node)
{
	if (node == NULL)
   {
		cout << "Tree is empty, no MINIMUM." << endl;
		return node;
	}
    else
    {
       //add your codes here
       //----
       if (node->leftChild != NULL) {
           this->findMinimumNode(node->leftChild);
       } else {
            this->print(node);
       }
	   //----
	 }
}

//**************************************************************
//This function returns a pointer points to the maximum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMaximumNode(Node *node)
{
	if (node == NULL)
   {
		cout << "Tree is empty, no MAXIMUM." << endl;
		return node;
	}
   else
   {
       //add your codes here
       //----
       if (node->rightChild != NULL) {
           this->findMinimumNode(node->rightChild);
       } else {
            this->print(node);
       }
	   //----
	}
}

//**************************************************************
//This function search the tree for a given key of a Food
//Note: key is the combination of foodID, name, supplierID
//It returns a pointer points to the node if founded, otherwise return NULL
Node* RedBlackTree::treeSearch(string foodID, string name, string supplierID)
{
   string key1 = foodID + name + supplierID;
	Node *node = root;
	while(node != NULL)
    {
		//----
        string searchKey = node->foodID + node->name + node->supplierID;
        
		//-----
		if(key1.compare(searchKey) == 0)
		{
	        cout << left;
	        cout << setw(5) << foodID
            << setw(35) << name
            << setw(15) << supplierID
            << " is FOUND." << endl;
            return node;
		}
      else
      {
         cout << left;
         cout << setw(5) << foodID
              << setw(35) << name
              << setw(15) << supplierID
              << " is NOT FOUND." << endl;
         return NULL;
      }
}

//****************************************************
//This function left-rotate the BST at 'node'
void RedBlackTree::leftRotate(Node *node)
{
	if(node == NULL)
		return;

	//add your codes here
    //----
	//----
}

//***************************************************
//This function right-rotate the BST at 'node'
void RedBlackTree::rightRotate(Node *node)
{
	if(node == NULL)
		return;

	//add your codes here
    //----
	//----
}


//**************************************************************
//This function finds the predecessor of the given 'node'
//it prints the relevant predecessor info. on screen.
Node* RedBlackTree::findPredecessorNode(Node *node)
{
   Node* predn;
   if(//----found)
   {
      //add your codes here
      //----
	  cout << left;
      cout << "Its Predecessor is: " << endl;
	  print(predn);
	  return predn;
	}
	else  //not found
	{
	   //add your codes here
      //----
      cout << left;
      cout << "Its Predecessor does NOT EXIST"	<< endl;
      return predn;
	}
}

//**************************************************************
//This function finds the successor of the given 'node'
//it prints the relevant successor info. on screen.
Node* RedBlackTree::findSuccessorNode(Node *node)
{
   Node* sn;
   if(//----found)
   {
      //add your codes here
      //----
      cout << left;
      cout << "Its Successor is: " << endl;
		print(sn);
		return sn;
	}
	else  //not found
   {
      cout << left;
      cout << "Its Successor does NOT EXIST"	<< endl;
      return sn;
	}
}

//**************************************************************
//This function find the minimum node of the entire red-black tree
//It print out the minimum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMinimum()
{
	if (root == NULL)
   {
		cout << "Tree is empty. No Minimum." << endl;
		return;
	}

	//add your codes here
	//----
	//----
}

//**************************************************************
//This function find the maximum node of the entire red-black tree
//It print out the maximum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMaximum()
{
	if (root == NULL)
    {
		cout << "Tree is empty. No Maximum." << endl;
		return;
	}

	//add your codes here
	//----
	//----
}

//******************************************************************
//This function print out the pre-order traversal of the entire tree
void RedBlackTree::treePreorder()
{
	//add your codes here
	//----
	//----
}

//******************************************************************
//This function print out the in-order traversal of the entire tree
void RedBlackTree::treeInorder()
{
	//add your codes here
	//----
	//----
}

//******************************************************************
//This function print out the post-order traversal of the entire tree
void RedBlackTree::treePostorder()
{
	//add your codes here
	//----
	//----
}

//******************************************************************
//Given a Food's key, this function first check whether the
//food is inside the tree or not, if it is inside, it will print
//its predecessor info. on screen, if not, it print an error message
void RedBlackTree::treePredecessor(string foodID, string name, string supplierID)
{
	if (root == NULL)
		cout << "Tree is empty. No Predecessor." << endl;
	else
   {
      //add your codes here
      //----
      //----
	}
}

//******************************************************************
//Given a food's key, this function first check whether the
//food is inside the tree or not, if it is inside, it will print
//its successor info. on screen, if not, it print an error message
void RedBlackTree::treeSucessor(string foodID, string name, string supplierID)
{
	if (root == NULL)
		cout << "Tree is empty. No Successor." << endl;
	else
   {
      //add your codes here
      //----
      //----
	}
}

//**************************************************************
//This function create a node from the given info., then insert
//the node inside the red-black tree. Note: at beginning, the newly
//added node should always be 'RED'
void RedBlackTree::treeInsert(string foodID, string name, string supplierID, double price)
{
	//add your codes here
	//----
    Node* newNode = new Node();
    newNode->foodID = foodID;
    newNode->name = name;
    newNode->supplierID = supplierID;
    newNode->price = price;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->color = "RED";
    if 
	//----
}

//******************************************************************
//Given a 'node', this function prints all its information on screen
void RedBlackTree::print(Node *node)
{
        cout << left;
		cout << setw(5) << node->foodID
             << setw(35) << node->name
             << setw(15) << node->supplierID
            << setw(7) << fixed << setprecision(2) << node->price
            << setw(7) << node->color << endl;
}

//**************************************************************
//Given a Node 'node1', this function compares it with another
//node's key.
//key is a string combination of foodID + name + supplierID
//It returns a negative number if in alphabetical order, key2 is
//in front of 'node1'; otherwise it returns a positive number
int RedBlackTree::compareNodes(Node *node1, string key2)
{
	//add your codes here
	//----
	//----
}
