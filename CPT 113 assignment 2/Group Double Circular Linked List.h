#ifndef GROUPDOUBLECIRCULARLINKEDLIST_H
#define GROUPDOUBLECIRCULARLINKEDLIST_H
#include"HandDeck Linked List.h"


template <class G, class C>
//inherit HandDeckLinkedList
class GroupDoubleCircularLinkedList : public HandDeckLinkedList<C>
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

template<class G, class C>
void addNewGroupAtEnd(G);

template<class G, class C>
void NextGroup();

template<class G, class C>
void PreviousGroup();

template<class G, class C>
void RemoveGroup(G&);

template<class G, class C>
void setFlagReverse();

template<class G, class C>
bool getFlagReverse();

template<class G, class C>
bool checkWinner();

template<class G, class C>
void skipTurn();

template<class G, class C>
void reverse();
template<class G, class C>

#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
