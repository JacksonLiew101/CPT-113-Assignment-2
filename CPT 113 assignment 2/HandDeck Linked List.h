#pragma once
#ifndef HANDDECKLINKEDLIST_H
#define HANDDECKLINKEDLIST_H
#include<iostream>
#include <string>
#include "DrawPile Stack.h"
#include "Index Linked List.h"
using namespace std;

template <class C >
class HandDeckLinkedList
{
private:
	//declare a structure for the list
	struct CardNode
	{
		C value; // value in this node
		struct CardNode* next; // point to next node
	};
	CardNode* head; // list head pointer
	int NumberOfHandCards;
	string HandDeckName;
	IndexLinkedList<int> Indexes;
public:
	//constructor
	HandDeckLinkedList();
	//~destructor
	~HandDeckLinkedList();

	//linked list operations
	bool isEmpty();			// done
	bool matchCard(C, C);	// done
	void playCard(C, C&);	//	done
	void drawCard(C);		// done
	//void draw2Cards(C&); // at main function
	//void draw4Cards(C&);// at main function
	void showHandCards(); // done
	//void initialHandCards(); // draw 5 cards/ at main function
	//bool checkCardValidity(C);  no need this function
	void showValidCard(C); // done
	void copyValidChosenCard(int, C&); // done
	void setHandDeckName(string); //done
	string getHandDeckName(); //done
	int getNumberOfHandCards(); //done
	void clearNode();
	bool searchIndex(int) const;
	void clearIndexList();
	int getIndexListLength();
	void promptColour(int& choice, string& colour_change);
	void showIndexLinkedList();
	int showIndexLinkedListHead();
};


template <class C>
int HandDeckLinkedList<C>::showIndexLinkedListHead()
{
	return Indexes.showHeadValue();
}

template <class C>
void HandDeckLinkedList<C>::showIndexLinkedList()
{
	return Indexes.displayList();
}
template <class C>
int HandDeckLinkedList<C>::getIndexListLength()
{
	return Indexes.getlength();
}
template<class C>
void HandDeckLinkedList<C>::promptColour(int& choice, string& colour_change)
{
	cout << "\nWhat colour do you pick now?\n";
	cout << "1. Red 2. Green 3. Blue 4. Yellow\n";
	do {
		cout << "->";
		cin >> choice;

		if (choice < 1 || choice > 4) {
			cout << "Invalid colour choice. Try again\n";
		}

	} while (choice < 1 || choice >4);
	switch (choice)
	{
	case 1:
		colour_change = "Red";
		break;
	case 2:
		colour_change = "Green";
		break;
	case 3:
		colour_change = "Blue";
		break;
	case 4:
		colour_change = "Yellow";
		break;
	default:
		cout << "Invalid colour detected\n";
		break;
	}
}
template <class C>
void HandDeckLinkedList<C>::clearIndexList()
{
	Indexes.clearNode();
}
template <class C>
bool HandDeckLinkedList<C>::searchIndex(int index) const
{
	return Indexes.search(index);
}
template <class C>
int HandDeckLinkedList<C>::getNumberOfHandCards()
{
	return NumberOfHandCards;
}


template <class C>
void HandDeckLinkedList<C>::setHandDeckName(string name)
{
	HandDeckName = name;
}

template <class C>
string HandDeckLinkedList<C>::getHandDeckName()
{
	return HandDeckName;
}

template <class C> 
HandDeckLinkedList<C>::HandDeckLinkedList()
{
	head = nullptr;
	NumberOfHandCards = 0;
	HandDeckName = "";
	
}

//destructor
template<class C>
HandDeckLinkedList<C>::~HandDeckLinkedList()
{
	CardNode* Node_ptr;

	// delete every card node until the linked list is empty
	while (!isEmpty()) {
		Node_ptr = head;

		head = head->next;

		delete Node_ptr;
	}
}

template<class C>
bool HandDeckLinkedList<C>::isEmpty()
{
	return head == nullptr;
}

template<class C>
bool HandDeckLinkedList<C>::matchCard(C search_card, C this_card)
{
	if (search_card.compareStrings(search_card.getValue(),this_card.getValue()) 
		&& search_card.compareStrings(search_card.getColour(), this_card.getColour()) ) {
		return true;
	}
	else {
		return false;
	}
}

// the card will be pass to a temp class obj in the main
// both of the card must be from different objects
template<class C>
void HandDeckLinkedList<C>::playCard(C card, C& out_card)
{
	// create two pointer trackers
	CardNode* Node_ptr = nullptr;
	CardNode* Previous_node = nullptr;
	int Choice = 0;
	string Colour_change = "";

	// should I add check empty list, because I already pre-checked everything at
	// showValidCard

	// tackle the first case of head being the deleted ones
	// class that store data is passed into the function
	if (matchCard(head->value, card)) {
		// store the value of the card first
		// before playing the "Wild" or "Wild Draw Four", must states the colour first
		if (card.compareStrings(head->value.getValue(), "Wild") || card.compareStrings(head->value.getValue(), "Wild Draw Four")) {
			out_card.setCard(head->value.getValue(), head->value.getColour(), head->value.getScore());
			// prompt to change colour
			promptColour(Choice, Colour_change);
			out_card.setColour(Colour_change);
		}
		else {
			out_card.setCard(head->value.getValue(),head->value.getColour(), head->value.getScore());
		}

		Node_ptr = head->next;
		delete head;
		head = Node_ptr;
	}
	else {
		Node_ptr = head;

		while (Node_ptr != nullptr && !matchCard(Node_ptr->value, card)) {
			Previous_node = Node_ptr;
			Node_ptr = Node_ptr->next;
		}

		// After finding the node
		if (Node_ptr) {
			// update the card details to the parameter first
			// before playing the "Wild" or "Wild Draw Four", must states the colour first
			if (card.compareStrings(Node_ptr->value.getValue(), "Wild") || card.compareStrings(Node_ptr->value.getValue(), "Wild Draw Four")) {
				out_card.setCard(Node_ptr->value.getValue(),Node_ptr->value.getColour(), Node_ptr->value.getScore());
		
				// prompt to change colour
				promptColour(Choice, Colour_change);
				out_card.setColour(Colour_change);
			}
			else {
				out_card.setCard(Node_ptr->value.getValue(),Node_ptr->value.getColour(), Node_ptr->value.getScore());
			}

			// delete the node
			Previous_node->next = Node_ptr->next;
			delete Node_ptr;
		}
	}
	NumberOfHandCards--;
	// Suggestion: wanna add if the card is last card, add "UNO statements??
}

template<class C>
void HandDeckLinkedList<C>::drawCard(C new_card)
{
	CardNode* newNode; 
	CardNode* nodePtr; // move through the linked list

	newNode = new CardNode;
	newNode->value = new_card;
	newNode->next = nullptr;

	 // If there are no nodes in the list
    // make newNode the first node.
	if(isEmpty())
	{
		head = newNode;
	}
	else
	{
	// Initialize nodePtr to head of list.
		nodePtr = head;
		// Find the last node in the list.
		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		 // Insert newNode as the last node.
		nodePtr->next = newNode;
	}
	NumberOfHandCards++;
}

/*template<class C>
void HandDeckLinkedList<C>::draw2Cards(C&)
{
}

template<class C>
void HandDeckLinkedList<C>::draw4Cards(C&)
{
	
}*/

template<class C>
void HandDeckLinkedList<C>::showHandCards()
{
	CardNode* nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		nodePtr->value.displayCard();
		cout << " | ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}


template<class C>
void HandDeckLinkedList<C>::copyValidChosenCard(int index, C& temp_card)
{
	CardNode* nodePtr;
	int i = 0;

	nodePtr = head;
	while(!(nodePtr == nullptr))
	{
		i++;
		if(i == index)
		{
			break;
		}
		nodePtr = nodePtr->next;
	}
	temp_card.setCard(nodePtr->value.getValue(),nodePtr->value.getColour(), nodePtr->value.getScore());
}
/*template<class C>
inline void HandDeckLinkedList<C>::initialHandCards()
{
	
}

template<class C>
bool HandDeckLinkedList<C>::checkCardValidity(C)
{
	CardNode* nodePtr;
	return false;
}*/

template<class C>
void HandDeckLinkedList<C>::showValidCard(C searchCard)
{
	CardNode* nodePtr;
	int i = 0;
	// if the list is empty, do nothing
	if(!head)
	{
		cout << "You don't have any cards in your hand\n";
		return;
	}

	//determine if the first node is the one
	/*
		since the top of discard pile is always number card
		check for number card condition can ady
		number card condition:
		same number or same colour
	*/
	nodePtr = head;
	string Check_value = searchCard.getValue();
	cout << "These are the cards that can be used: ";
	
	while(!(nodePtr == nullptr))
	{
		i++;
		//same number or same colour
		if(searchCard.compareStrings(nodePtr->value.getValue(), searchCard.getValue()) || searchCard.compareStrings(nodePtr->value.getColour(), searchCard.getColour()))
		{
			//If this node is the last card in the hand
			if(nodePtr->next == nullptr)
			{
				cout << i << ". ";
				nodePtr->value.displayCard();
				cout << "\n";
			}
			else
			{
				cout << i << ". ";
				nodePtr->value.displayCard();
				cout << " , ";
			}
			Indexes.appendNode(i);
			
		}
		//for wild card
		//wild card always can be used
		if(searchCard.compareStrings(nodePtr->value.getValue(), "Wild Draw Four") || searchCard.compareStrings(nodePtr->value.getValue(), "Wild"))
		{
			//If this node is the last card in the hand
			if(nodePtr->next == nullptr)
			{
				cout << i << ". ";
				nodePtr->value.displayCard();
				cout << "\n";
			}
			else
			{
				cout << i << ". ";
				nodePtr->value.displayCard();
				cout << " , ";
			}
			Indexes.appendNode(i);
			
		}
		nodePtr = nodePtr->next;
	}
}


#endif // !HANDDECKLINKEDLIST_H