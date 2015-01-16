/******************************************************************************************************************
Create a node with one string in it and a pointer to point to the next node
Create a function to add a node to the end of the list
Create a function to traverse the list
In the main, read in an unknown number of strings from the user
	Designate how the user quits entering strings
	Build the list by calling add to the end function as the user enters a string
When they are done entering strings, traverse the list
Create a linear search function that traverses the list looking for the search string
Create an insert node function that uses the search method to insert a node in to the list
	Should handle inserting into the beginning, middle, and end of the list
Create a delete function that uses the search function to remove a node from the list
	Should handle deleting from the beginning, middle, and end of the list
******************************************************************************************************************/

// http://www.cprogramming.com/tutorial/lesson15.html
// http://www.cprogramming.com/snippets/source-code/singly-linked-list-insert-remove-add-count

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struct declaration
struct node
{
	string myString;
	struct node *nextRec;
};

// Declaration for function that adds a node to the end of the list
void addNode(node *root, string input);

// Declaration for function that traverses the list
void traverse();

int main()
{
	// Create the root node
	node *root;
	root = new node;
	root->nextRec = NULL;
	// Read in the first string for the root node
	string rootInput;
	cout << "Please enter a string: ";
	cin >> rootInput;
	root->myString = rootInput;
	
	// Add more nodes to the linked list
	string input;
	do
	{
		cout << "Please enter a string, or type \"0\" to quit: ";
		cin >> input;
		addNode(input);
	} while (input != "0");
	
	system("PAUSE");
	return 0;
}

void addNode(string input)
{

}