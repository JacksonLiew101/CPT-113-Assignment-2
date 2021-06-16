#pragma once
#ifndef INDEXLINKEDLIST_H
#define INDEXLINKEDLIST_H
#include <iostream>
using namespace std;
template <class T>
class IndexLinkedList
{
private:
	struct IndexNode
	{
		T value;
		struct IndexNode* next;
	};

	IndexNode* head;

	public:
	//constructor
	IndexLinkedList()
	{
		head = nullptr;
	}

	//destructor
	~IndexLinkedList()
	{
		clearNode();
	};

	//operations
	void appendNode(T);
	void clearNode();
	bool search(T) const;
}

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
	IndexNode *newNode;
	IndexNode *nodePtr;

	newNode = new IndexNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	// If there are no nodes in the list
    // make newNode the first node.
	if(!head)
	{
		head = newNode;
	}
	else // Otherwise, insert newNode at end.
	{
		nodePtr = head;

		// Find the last node in the list.
		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		// Insert newNode as the last node.
		nodePtr->next = newNode; 
	}
}

template <class T>
bool LinkedList<T>::search(T searchValue) const
{
	IndexNode* nodePtr;
	IndexNode* previousNode;

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

		// Skip all nodes whose value member is
        // not equal to num.
		while(nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//if it found the node
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
template <class T>
void IndexLinkedList<T>::clearNode();
{
	IndexNode* nodePtr;
	IndexNode* nextNode;

	nodePtr = head;

	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;

		nodePtr = nextNode;
	}
}


#endif