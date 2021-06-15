#pragma once
#ifndef DISCARDPILESTACK_H
#define DISCARDPILESTACK_H
#include"Card.h"
#include <iostream>
#include <string>
using namespace std;

template <class C>
class DiscardPileStack
{
private:
	struct CardNode
	{
		C value;
		CardNode* next;
	};
	CardNode* top;
	string action_statement;
public:
	//Constructor
	DiscardPileStack(); // done
	// Destructor
	~DiscardPileStack(); // done

	// Stack operations
	bool isEmpty(); // done
	void push(C); // done
	C peek(); // done
	void setActionStatement(string action); // done
	string getActionStatement(); // done
};

template <class C>
DiscardPileStack<C>::DiscardPileStack()
{
	top = nullptr;
	// later test condition must use ""
	action_statement = "";
}

template <class C>
DiscardPileStack<C>::~DiscardPileStack()
{
	CardNode* Node_ptr;

	// delete every card node until the stack is empty
	while (!isEmpty()) {
		Node_ptr = top;

		top = top->next;

		delete Node_ptr;
	}
}

template <class C>
bool DiscardPileStack<C>::isEmpty() {
	return (top == nullptr);
}

template<class C>
void DiscardPileStack<C>::push(C new_card)
{
	// allocate a new node
	CardNode* New_node = nullptr;
	New_node = new CardNode;
	New_node->value = new_card;
	New_node->next = nullptr;
	string Check_value = new_card.getValue();

	if (isEmpty()) {
		// This means it will be the first node, make top point to new node
		top = New_node;
	}
	else {
		// Make new pointer of new node point to the current top
		New_node->next = top;

		// Update top to point to new node
		top = New_node;
	}

	// update action statement according to the new card
	if (newcard.compareStrings(newcard.getValue(),"Skip") || newcard.compareStrings(newcard.getValue(),"Reverse") ||newcard.compareStrings(newcard.getValue(),"Draw Two" newcard.compareStrings(newcard.getValue(),"Wild") || newcard.compareStrings(newcard.getValue(),"Wild Draw Four")) {
		setActionStatement(Check_value);
	}
	else {
		setActionStatement("");
	}
}

template<class C>
C DiscardPileStack<C>::peek()
{
	return top->value;
}

template<class C>
void DiscardPileStack<C>::setActionStatement(string action)
{
	action_statement = action;
}

template<class C>
string DiscardPileStack<C>::getActionStatement()
{
	return action_statement;
}

#endif // !DISCARDPILESTACK_H