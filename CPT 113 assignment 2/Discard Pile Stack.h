#ifndef DISCARDPILESTACK_H
#define DISCARDPILESTACK_H
#include"Card.h"

// This is the template class for Discard Pile Stack
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
	DiscardPileStack(); 
	~DiscardPileStack(); 
	void setActionStatement(string);
	string getActionStatement();
	bool isEmpty(); 
	void displayStack();
	void push(C); 
	void peek(C&); 
	
};

// Constructor
template <class C>
DiscardPileStack<C>::DiscardPileStack()
{
	top = nullptr;
	action_statement = "";
}

// Destructor
template <class C>
DiscardPileStack<C>::~DiscardPileStack()
{
	CardNode* Node_ptr = nullptr;

	// delete every card node until the stack is empty
	while (!isEmpty()) {
		Node_ptr = top;

		top = top->next;

		delete Node_ptr;
	}
}

// Action Setter
template<class C>
void DiscardPileStack<C>::setActionStatement(string action)
{
	action_statement = action;
}

// Action Getter
template<class C>
string DiscardPileStack<C>::getActionStatement()
{
	return action_statement;
}

// Return true if the discard pile stack is empty
template <class C>
bool DiscardPileStack<C>::isEmpty() {
	return (top == nullptr);
}

// Display all the cards available in the discard pile stack
template<class C>
void DiscardPileStack<C>::displayStack()
{
	CardNode* Node_ptr = nullptr;
	Node_ptr = top;

	// display all the cards in the stack, from top to bottom stack
	while (!(Node_ptr == nullptr)) {
		Node_ptr->value.displayCard();
		cout << endl;
		Node_ptr = Node_ptr->next;
	}
}

// Push the cards to the discard pile stack, only stores numbers and colours on the stack
template<class C>
void DiscardPileStack<C>::push(C new_card)
{
	// allocate a new node
	CardNode* New_node = nullptr;
	New_node = new CardNode;
	New_node->value.setCard(new_card.getValue(), new_card.getColour(), new_card.getScore());
	New_node->next = nullptr;
	string Check_value = new_card.getValue();


	// Update action statement according to the last card played
	// Only push number card to stack without changing values
	// For action cards, change the action statement and colour but remain the previous top stack number values
	if (new_card.compareStrings(Check_value, "Skip") 
		|| new_card.compareStrings(Check_value, "Reverse") 
		|| new_card.compareStrings(Check_value, "Draw Two") 
		|| new_card.compareStrings(Check_value, "Wild") 
		|| new_card.compareStrings(Check_value, "Wild Draw Four"))
	{
		// Override the colour of the top stack card, no need push card
		top->value.setColour(new_card.getColour()); 
		setActionStatement(Check_value);
	}
	else // If it is a number card, then only push card to the stack
	{
		setActionStatement("");
		
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
	}

}

// Peek the top card and store to a temp card object
template<class C>
void DiscardPileStack<C>::peek(C &store_card)
{
	store_card.setCard(top->value.getValue(), top->value.getColour(), top->value.getScore());
}

#endif // !DISCARDPILESTACK_H