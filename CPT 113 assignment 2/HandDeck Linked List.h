#pragma once
#ifndef HANDDECKLINKEDLIST_H
#define HANDDECKLINKEDLIST_H
#include<iostream>
#include <string>
using namespace std;

template <class T>
class HandDeckLinkedList
{
private:
	//declare a structure for the list
	struct HandDeckNode
	{
		T value; // value in this node
		struct HandDeckNode* next; // point to next node
	};
	HandDeckNode* head; // list head pointer

public:
	//constructor
	LinkedList()
	{
		head = nullptr;
	}
};
#endif // !HANDDECKLINKEDLIST_H