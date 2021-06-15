#pragma once
#ifndef HANDDECKLINKEDLIST_H
#define HANDDECKLINKEDLIST_H
#include<iostream>
#include <string>
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

public:
	//constructor
	HandDeckLinkedList();
	//~destructor
	~HandDeckLinkedList();

	//linked list operations
	bool isEmpty();
	bool matchCard(C, C);
	void playCard(C, C&);
	void drawCard(C&);
	void draw2Cards(C&);
	void draw4Cards(C&);
	void showHandCards();
	void initialHandCards(); // draw 5 cards
	bool checkCardValidity(C);
	void showValidCard();
	


};

template <class C> 
HandDeckLinkedList<C>::HandDeckLinkedList()
{
	head = nullptr;
	initialHandCards();
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
	if (search_card.getValue() == this_card.getValue() && search_card.getValue() == this_card.getColour() && search_card.getScore() == this_card.getScore()) {
		return true;
	}
	else {
		return false;
	}
}

//someway in main must return back the values of card select to check back in the 
// playCard method

template<class C>
void HandDeckLinkedList<C>::playCard(C card, C& out_card)
{
	// create two pointer trackers
	CardNode* Node_ptr = nullptr;
	CardNode* Previous_node = nullptr;

	// should I add check empty list, because I already pre-checked everything at
	// showValidCard

	// tackle the first case of head being the deleted ones
	// class that store data is passed into the function
	if (matchCard(head->value, card)) {
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

		// Delete the selected card
		if (Node_ptr) {
			// update the card details to the parameter first
			out_card = Node_ptr->value;

			Previous_node->next = Node_ptr->next;
			delete Node_ptr;
		}
	}
}

template<class C>
void HandDeckLinkedList<C>::drawCard(C&)
{
}

template<class C>
void HandDeckLinkedList<C>::draw2Cards(C&)
{
}

template<class C>
void HandDeckLinkedList<C>::draw4Cards(C&)
{
}

template<class C>
void HandDeckLinkedList<C>::showHandCards()
{
}

template<class C>
inline void HandDeckLinkedList<C>::initialHandCards()
{
}

template<class C>
bool HandDeckLinkedList<C>::checkCardValidity(C)
{
	return false;
}
template<class C>
void HandDeckLinkedList<C>::showValidCard()
{
}
#endif // !HANDDECKLINKEDLIST_H