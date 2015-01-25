/***********************************************************************************************************************
Create a node with one string in it and a pointer to point to the next node
Create a function to add a node to the end of the list
Create a function to traverse the list
In the main, read in an unknown number of strings from the user
	Designate how the user quits entering strings
	Build the list by calling add to the end function as the user enters a string
When they are done entering strings, traverse the list
Create a linear search function that traverses the list looking for the search string
Create an insert node function that uses the search method to insert a node in to the list
	If the string is found, insert a node right after the found node.  If not, insert a new node at the end of the list
	Should handle inserting into the beginning, middle, and end of the list
Create a delete function that uses the search function to remove a node from the list
	Should handle deleting from the beginning, middle, and end of the list
***********************************************************************************************************************/

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

// Function Declarations
void addNode(node * &, string); // adds a node to the end of the list
void printNode(node *); // prints a single struct node
void traverse(node *); // traverses the list and prints out contents in the nodes
node * searchList(node * &, string); // searches the list for a user-entered string, returns the pointer to the "found" struct node
void insertNode(node * &, string); // inserts a node in to the list
void deleteNode(node * &, string); // deletes a node from anywhere in the list

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
		if (input == "0")
		{
			break;
		}
		addNode(currentRec, input);
	} while (true);

	// Traverse the linked list
	traverse(root);

	// TEST testing the search method
	cout << "\nThis program will now search for a string in the linked list of nodes.\nPlease enter the string for which you want to search: ";
	string searchInput;
	cin >> searchInput;
	node *mySearchTest = searchList(root, searchInput);

	// TEST testing the insert method
	cout << "\nThis program will now insert a new node.\nType \"0\" to insert at the start of the list, or type the string of the existing node after which you want to insert: ";
	string insertInput;
	cin >> insertInput;
	insertNode(root, insertInput);
	traverse(root);

	// TEST testing the delete method
	cout << "\nThis program will now delete node.\nType the string of the existing node you wish to delete: ";
	string deleteInput;
	cin >> deleteInput;
	deleteNode(root, deleteInput);
	traverse(root);

	system("PAUSE");
	return 0;
}

void addNode(node * &currentRec, string input)
{
	currentRec->nextRec = new node;
	currentRec = currentRec->nextRec;
	currentRec->nextRec = NULL;
	currentRec->myString = input;
	return;
}

void printNode(node * nodeToPrint)
{
	cout << nodeToPrint->myString;
	return;
}

void traverse(node *start)
{
	if (start != NULL)
	{
		node *conductor = start;
		while (conductor != NULL)
		{
			printNode(conductor);
			cout << " ";
			conductor = conductor->nextRec;
		}
		cout << endl;
	}
	return;
}

node * searchList(node * &searchStart, string toFind)
{
	if (searchStart != NULL)
	{
		int listItemNumber = 0;
		node *conductor = searchStart;
		while (conductor != NULL)
		{
			listItemNumber++;
			if (conductor->myString == toFind)
			{
				cout << "That string was found in the #" << listItemNumber << " node in the linked list." << endl;
				return conductor;
			}
			else
			{
				conductor = conductor->nextRec;
			}
		}
		cout << "That string was not found.";
		return NULL;
	}
}

void insertNode(node * &listStart, string toFind)
{
	if (toFind == "0")
	{
		node *newStart = new node;
		// Add the new string to the new node
		cout << "Please enter a string for the new node: ";
		string input;
		cin >> input;
		newStart->myString = input;
		newStart->nextRec = listStart;
		listStart = newStart;
	}
	else
	{
		node *insertLocation = searchList(listStart, toFind);
		if (insertLocation != NULL)
		{
			node *temp = insertLocation->nextRec;
			insertLocation->nextRec = new node; // Have the insertLocation node point to the new node being inserted
			insertLocation = insertLocation->nextRec;
			// Add the new string to the new node
			cout << "Please enter a string for the new node: ";
			string input;
			cin >> input;
			insertLocation->myString = input;
			// Point the newly inserted node to the next node
			insertLocation->nextRec = temp;
		}
		else
		{
			cout << "  Therefore, the program will add a new node at the end of the list." << endl;
			// Reach the end of the linked list to add a new node
			insertLocation = listStart;
			while (insertLocation->nextRec != NULL)
			{
				insertLocation = insertLocation->nextRec;
			}
			// Create a new node at the very end of the list
			insertLocation->nextRec = new node;
			insertLocation = insertLocation->nextRec;
			insertLocation->nextRec = NULL;
			// Add the new string to the new node
			cout << "Please enter a string for the new node: ";
			string input;
			cin >> input;
			insertLocation->myString = input;
		}
	}
}

void deleteNode(node * &listStart, string toFind)
{
	// https://www.youtube.com/watch?v=Y0n86K43GO4
	
	node* deleteLocation = searchList(listStart, toFind);
	node* temp1 = listStart;
	if (listStart = deleteLocation)
	{
		listStart = temp1->nextRec;
		// TODO: destroy the excluded node?? How??
		delete temp1;
	}
	else
	{
		// Reach the node preceding the one to be deleted
		while (temp1->nextRec != deleteLocation)
		{
			temp1 = temp1->nextRec;
		}
		node* temp2 = deleteLocation->nextRec; // Reach the node following the one to be deleted
		temp1->nextRec = temp2;
		delete deleteLocation;
	}
}