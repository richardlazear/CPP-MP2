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
#include <string>

using namespace std;

// Struct declaration
struct node
{
	string myString;
	node *nextRec;
};

// Declaration for function that adds a node to the end of the list
void addNode(node *, string);

// Declaration for function that traverses the list
void traverse(node *);

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
	node *currentRec = root;
	string input;
	do
	{
		cout << "Please enter a string, or type \"0\" to quit: ";
		cin >> input;
		addNode(currentRec, input);
	} while (input != "0");

	cout << "Traversing...";
	traverse(root);
	cout << "...End traversing" << endl;

	system("PAUSE");
	return 0;
}

void addNode(node *currentRec, string input)
{
	/*node* temp = new node; // Create a temporary struct pointer
	currentRec->nextRec = temp; // Assign this pointer to the current node's nextRec field
	temp->myString = input; // Assign the user's input to the string field
	cout << temp->myString << endl;
	temp->nextRec = NULL;*/

	cout << currentRec->myString << endl;
	currentRec->nextRec = new node;
	currentRec = currentRec->nextRec;
	currentRec->myString = input;
	cout << currentRec->myString << endl;
	currentRec->nextRec = NULL;
}

void traverse(node *start)
{
	if (start != NULL)
	{
		node *conductor = start;
		while (conductor->nextRec != NULL)
		{
			cout << conductor->myString << " ";
			conductor = conductor->nextRec;
		}
		cout << "End of list.";
	}
}