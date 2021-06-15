#pragma once
#ifndef DISCARDPILESTACK_H
#define DISCARDPILESTACK_H
#include <iostream>
#include <string>
using namespace std;

template <class C>
class DiscardPileStack
{
private:
	struct DiscardPileStackNode
	{
		C value;
		DiscardPileStackNode* next;
	};
	DiscardPileStackNode* TopStack;
	string ActionStatement;
public:
	//Constructor
	DiscardPileStack()
	{
		TopStack = nullptr;
		ActionStatement = "";
	}

	// Destructor
	~DiscardPileStack();

	// Stack operations
	void push(C);
	void peek();
	void setActionStatement(string action);
	string getActionStatement();
};

template <class C>
DiscardPileStack<C>::~DiscardPileStack()
{
	//destroy function
}
#endif // !DISCARDPILESTACK_H