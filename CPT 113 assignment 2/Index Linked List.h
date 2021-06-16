#ifndef INDEXLINKEDLIST_H
#define INDEXLINKEDLIST_H
#include <iostream>
using namespace std;

// This is the template class for Index Linked List
template <class T>
class IndexLinkedList
{
private:
	struct IndexNode
	{
		T value;
		IndexNode* next;
	};
	int length;
	IndexNode* head;

public:
	IndexLinkedList();
	~IndexLinkedList();
	int getlength() const;
	T showHeadValue() const;
	bool search(T) const;
	void displayList();
	void appendNode(T);
	void clearNode();
	

};

// Constructor
template <class T>
IndexLinkedList<T>::IndexLinkedList()
{
	head = nullptr;
	length = 0;
}

// Destructor
template <class T>
IndexLinkedList<T>::~IndexLinkedList()
{
	clearNode();
};

// Length Getter
template <class T>
int IndexLinkedList<T>::getlength() const
{
	return length;
}

// Get the value of the head of the Linked List
template <class T>
T IndexLinkedList<T>::showHeadValue() const
{
	if (head == nullptr)
	{
		return 0;
	}
	else
	{
		return head->value;
	}
}

/*
	Linked List Methods
*/
// Returns true if the search value is found in the linked list
template <class T>
bool IndexLinkedList<T>::search(T searchValue) const
{
	IndexNode* nodePtr = nullptr;
	IndexNode* previousNode = nullptr;

	if(!head)
	{
		return false;
	}

	 // Determine if the first node is the one.
	if(head->value == searchValue)
	{
		return true;
	}
	else
	{
		nodePtr = head;

		// Skip all nodes whose value member is not equal to num.
		while(nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If it found
		if(nodePtr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

// Display all the index available in the linked list
template <class T>
void IndexLinkedList<T>::displayList()
{
	IndexNode* nodePtr = nullptr; 

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

// Add new node to the linked list
template <class T>
void IndexLinkedList<T>::appendNode(T newValue)
{
	IndexNode* newNode = nullptr;
	IndexNode* nodePtr = nullptr;

	newNode = new IndexNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	// If there are no nodes in the list, make newNode the first node.
	if (!head)
	{
		head = newNode;
	}
	else // Otherwise, insert newNode at end.
	{
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
	length++;
}

// Remove every node from the linked list
template <class T>
void IndexLinkedList<T>::clearNode()
{
	IndexNode* nodePtr = nullptr;
	IndexNode* nextNode = nullptr;

	nodePtr = head;

	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;

		nodePtr = nextNode;
		length--;
	}
	head = nullptr;
}

#endif