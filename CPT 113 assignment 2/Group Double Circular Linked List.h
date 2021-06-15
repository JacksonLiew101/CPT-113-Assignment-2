#ifndef GROUPDOUBLECIRCULARLINKEDLIST_H
#define GROUPDOUBLECIRCULARLINKEDLIST_H
#include"HandDeck Linked List.h"


template <class G, class C>
//inherit HandDeckLinkedList
class GroupDoubleCircularLinkedList : public HandDeckLinkedList<T2>
{
private:
	struct GroupNode
	{
		G value;
		GroupNode* next;
		GroupNode* previous;
	};
	GroupNode* head;
	GroupNode* last;
	GroupNode* current;
	bool flag_reverse;

public:
	//constructor
	GroupDoubleCircularLinkedList();
	// destructor
	~GroupDoubleCircularLinkedList();
	void addNewGroupAtEnd(G);
	void NextGroup();
	void PreviousGroup();
	void RemoveGroup(G&);
	void setFlagReverse();
	bool getFlagReverse();
	bool checkWinner();
	void skipTurn();
	void reverse();





};
//constructor
template<class G, class C>
GroupDoubleCircularLinkedList<G,C>::GroupDoubleCircularLinkedList() :HandDeckLinkedList<C>()
{
	head = nullptr; 
	last = nullptr;
	current = nullptr;
	flag_reverse = false;
}
//destructor
template<class G, class C>
GroupDoubleCircularLinkedList<G,C>::~GroupDoubleCircularLinkedList()
{
	//destroy function
}

#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
