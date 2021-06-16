#ifndef HANDDECKLINKEDLIST_H
#define HANDDECKLINKEDLIST_H
#include "Card.h"
#include "Index Linked List.h"
#include <iostream>
#include <string>
using namespace std;

// This is the template class for Hand Deck Linked List
template <class C >
class HandDeckLinkedList
{
private:
	struct CardNode
	{
		C value;
		CardNode* next;
	};
	CardNode* head;
	IndexLinkedList<int> Indexes;
	int number_of_hand_cards;
	
public:
	HandDeckLinkedList();
	~HandDeckLinkedList();
	int getNumberOfHandCards() const;
	bool isEmpty();			
	void showHandCards(); 
	void showValidCard(C); 
	void copyValidChosenCard(int, C&); 
	void playCard(C, C&);	
	void drawCard(C);		
	int showIndexLinkedListHead();
	bool searchIndex(int) const;
	void clearIndexList();
	bool matchCard(C, C);	
	void promptColour(int&, string&);

};

// Constructor
template <class C>
HandDeckLinkedList<C>::HandDeckLinkedList()
{
	head = nullptr;
	number_of_hand_cards = 0;
}

// Destructor
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

// Number of hand cards getter
template <class C>
int HandDeckLinkedList<C>::getNumberOfHandCards() const
{
	return number_of_hand_cards;
}

/*
	Linked List methods
*/
// Return true if the Linked List is empty
template<class C>
bool HandDeckLinkedList<C>::isEmpty()
{
	return head == nullptr;
}

// Show all the available cards on hand deck
template<class C>
void HandDeckLinkedList<C>::showHandCards()
{
	CardNode* nodePtr = nullptr;
	nodePtr = head;

	while (nodePtr)
	{
		nodePtr->value.displayCard();
		cout << " | ";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

// Show all the valid cards to be played
template<class C>
void HandDeckLinkedList<C>::showValidCard(C searchCard)
{
	CardNode* nodePtr = nullptr;
	int i = 0;

	// if the list is empty, do nothing
	if (!head)
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

	while (!(nodePtr == nullptr))
	{
		i++;
		//same number or same colour
		if (searchCard.compareStrings(nodePtr->value.getValue(), searchCard.getValue()) || searchCard.compareStrings(nodePtr->value.getColour(), searchCard.getColour()))
		{
			//If this node is the last card in the hand
			if (nodePtr->next == nullptr)
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
		if (searchCard.compareStrings(nodePtr->value.getValue(), "Wild Draw Four") || searchCard.compareStrings(nodePtr->value.getValue(), "Wild"))
		{
			// If this node is the last card in the hand
			if (nodePtr->next == nullptr)
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

// Find the chosen card based on index and save the card details
template<class C>
void HandDeckLinkedList<C>::copyValidChosenCard(int index, C& temp_card)
{
	CardNode* nodePtr;
	int i = 0;

	nodePtr = head;
	while (!(nodePtr == nullptr))
	{
		i++;
		if (i == index)
		{
			break;
		}
		nodePtr = nodePtr->next;
	}
	temp_card.setCard(nodePtr->value.getValue(), nodePtr->value.getColour(), nodePtr->value.getScore());
}

// The chosen card will be pass to a temp class obj in the main
// Both of the card must be from different objects
template<class C>
void HandDeckLinkedList<C>::playCard(C card, C& out_card)
{
	CardNode* Node_ptr = nullptr;
	CardNode* Previous_node = nullptr;
	int Choice = 0;
	string Colour_change = "";

	// Tackle the first case of head being the deleted ones
	// Class that store data is passed into the function
	if (matchCard(head->value, card)) {
		// Store the value of the card first
		// Before playing the "Wild" or "Wild Draw Four", must states the colour first
		if (card.compareStrings(head->value.getValue(), "Wild") 
			|| card.compareStrings(head->value.getValue(), "Wild Draw Four")) 
		{
			out_card.setCard(head->value.getValue(), head->value.getColour(), head->value.getScore());
			
			// prompt to change colour
			promptColour(Choice, Colour_change);
			out_card.setColour(Colour_change);
		}
		else {
			out_card.setCard(head->value.getValue(), head->value.getColour(), head->value.getScore());
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
			// Update the card details to the parameter first
			// Before playing the "Wild" or "Wild Draw Four", must states the colour first
			if (card.compareStrings(Node_ptr->value.getValue(), "Wild") 
				|| card.compareStrings(Node_ptr->value.getValue(), "Wild Draw Four")) 
			{
				out_card.setCard(Node_ptr->value.getValue(), Node_ptr->value.getColour(), Node_ptr->value.getScore());

				// prompt to change colour
				promptColour(Choice, Colour_change);
				out_card.setColour(Colour_change);
			}
			else {
				out_card.setCard(Node_ptr->value.getValue(), Node_ptr->value.getColour(), Node_ptr->value.getScore());
			}

			// delete the node
			Previous_node->next = Node_ptr->next;
			delete Node_ptr;
		}
	}
	number_of_hand_cards--;
}

// Help draw card from the Draw Pile to HandDeck
template<class C>
void HandDeckLinkedList<C>::drawCard(C new_card)
{
	CardNode* newNode = nullptr;
	CardNode* nodePtr = nullptr; 

	newNode = new CardNode;
	newNode->value.setCard(new_card.getValue(), new_card.getColour(), new_card.getScore());
	newNode->next = nullptr;

	// If there are no nodes in the list, make newNode the first node.
	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;
		// Find the last node in the list.
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
	number_of_hand_cards++;
}

/*
	Methods for Index Linked List 
*/
// Show the head value of the Index Linked List
template <class C>
int HandDeckLinkedList<C>::showIndexLinkedListHead()
{
	return Indexes.showHeadValue();
}

// Return true if the index is found in the Index Linked List
template <class C>
bool HandDeckLinkedList<C>::searchIndex(int index) const
{
	return Indexes.search(index);
}

// Reset the Index List for next group player
template <class C>
void HandDeckLinkedList<C>::clearIndexList()
{
	Indexes.clearNode();
}

/*
	General methods
*/
// Return true if both cards are similar
template<class C>
bool HandDeckLinkedList<C>::matchCard(C search_card, C this_card)
{
	if (search_card.compareStrings(search_card.getValue(), this_card.getValue())
		&& search_card.compareStrings(search_card.getColour(), this_card.getColour())) {
		return true;
	}
	else {
		return false;
	}
}

// Prompt for colour change during "Wild" and "Wild Draw Four" cards are used
template<class C>
void HandDeckLinkedList<C>::promptColour(int& choice, string& colour_change)
{
	// Ask for user choice
	cout << "\nWhat colour do you pick now?\n";
	cout << "1. Red 2. Green 3. Blue 4. Yellow\n";
	do {
		cout << "->";
		cin >> choice;

		if (choice < 1 || choice > 4) {
			cout << "Invalid colour choice. Try again\n";
		}

	} while (choice < 1 || choice >4);

	// Update the colour change
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

#endif // !HANDDECKLINKEDLIST_H