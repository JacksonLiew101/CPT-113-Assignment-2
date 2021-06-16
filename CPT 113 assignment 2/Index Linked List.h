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
		struct IndexNode* next;
	};
	int length;
	IndexNode* head;

public:
	//constructor
	IndexLinkedList()
	{
		head = nullptr;
		length = 0;
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
	void displayList() const;
	T showHeadValue() const;
	int getlength()
	{
		return length;
	}
};

template <class T>
T IndexLinkedList<T>::showHeadValue() const
{
	if(head == nullptr)
	{
		return 0;
	}
	else
	{
		return head->value;
	}
}
template <class T>
void IndexLinkedList<T>::appendNode(T newValue)
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
		while(nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}
		// Insert newNode as the last node.
		nodePtr->next = newNode; 
	}
	length++;
}

template <class T>
bool IndexLinkedList<T>::search(T searchValue) const
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
void IndexLinkedList<T>::clearNode()
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
	head = nullptr;
	length--;
}

template <class T>
void IndexLinkedList<T>::displayList() const
{
    IndexNode *nodePtr; // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

#endif