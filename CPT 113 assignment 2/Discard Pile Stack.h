#pragma once
#ifndef DISCARDPILESTACK_H
#define DISCARDPILESTACK_H
#include <iostream>
#include <string>
using namespace std;

template <class T>
class DiscardPileStack
{
private:
	struct DiscardPileStackNode
	{
		T value;
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
	void push(T);
	void peek();
	void setActionStatement(string action);
	string getActionStatement();
};
#endif // !DISCARDPILESTACK_H