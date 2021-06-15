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
	struct HandDeckNode
	{
		C value; // value in this node
		struct HandDeckNode* next; // point to next node
	};
	HandDeckNode* head; // list head pointer

public:
	//constructor
	HandDeckLinkedList()
	{
		head = nullptr;
		initialHandCards();
	}
	//~destructor
	~HandDeckLinkedList();

	//linked list operations
	void playCard(C);
	void drawCard(C&);
	void draw2Cards(C&);
	void draw4Cards(C&);
	void showHandCards();
	void initialHandCards(); // draw 5 cards
	bool checkCardValidity(C);
	void showValidCard();
	


};

//destructor
template<class C>
HandDeckLinkedList<C>::~HandDeckLinkedList()
{
	//destroy function
}
#endif // !HANDDECKLINKEDLIST_H