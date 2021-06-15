#ifndef GROUPDOUBLECIRCULARLINKEDLIST_H
#define GROUPDOUBLECIRCULARLINKEDLIST_H
#include"HandDeck Linked List.h"
#include"Discard Pile Stack.h"

template <class G, class C>
//inherit HandDeckLinkedList
class GroupDoubleCircularLinkedList
{
private:
	struct GroupNode
	{
		HandDeckLinkedList<C> handDeck = new HandDeckLinkedList;
		G value;
		GroupNode* next;
		GroupNode* previous;
	};
	GroupNode* head; // 1st Group
	GroupNode* current; // to keep track of whose turns
	int no_of_group;
	bool flag_reverse;

public:
	//constructor
	GroupDoubleCircularLinkedList();
	// destructor
	~GroupDoubleCircularLinkedList();

	void isEmpty();				// done
	void addNewGroupAtEnd(G);	// done
	void NextGroup();
	void PreviousGroup();
	void RemoveGroup(G&);
	void setFlagReverse(); // detect the reverse card at the main function
	bool getFlagReverse();
	bool checkWinner(); // detect it at the main function
	void skipTurn();
	void reverse();

};
//constructor
template<class G, class C>
GroupDoubleCircularLinkedList<G,C>::GroupDoubleCircularLinkedList() :HandDeckLinkedList<C>()
{
	head = nullptr; 
	current = nullptr;
	flag_reverse = false;
	no_of_group = 0;
}

//destructor
template<class G, class C>
GroupDoubleCircularLinkedList<G,C>::~GroupDoubleCircularLinkedList()
{
	GroupNode* Node_ptr = nullptr;

	for (int i = 0; i < no_of_group; i++) {
		Node_ptr = head;
		head->next;
		delete nodePtr;
		no_of_group--;
	}
	head = nullptr;
	end = nullptr;
	current = nullptr;
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::addNewGroupAtEnd(G new_group) {
	
	GroupNode* New_node = new GroupNode; // allocate a new node
	GroupNode* Node_ptr = nullptr; // tracker to move through list

	// store value inside new node and point to head
	New_node->value = new_group;
	New_node->next = head;
	
	Node_ptr = head;
	
	if (isEmpty()) {
		New_node->next = New_node;
		New_node->previous = New_node;
		head = New_node;
		current = head;
	}
	else {
		(head->previous)->next = New_node;
		New_node->previous = head->previous;
		New_node->next = head;
		head->previous = New_node;
	}
	no_of_group++;


}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::NextGroup() {
	current = current->next;
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::PreviousGroup() {
	current = current->previous;
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::RemoveGroup(G& out_group) {
	
	// the current group is immediately removed when they lose, i.e. more than max cards
	// possible number of groups for this function are 2,3,4
	if (no_of_group == 2) {
		return;
	}

}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::setFlagReverse() {
	flag_reverse = !flag_reverse;
}

template<class G, class C>
bool GroupDoubleCircularLinkedList<G, C>::getFlagReverse() {
	return flag_reverse;
}

template<class G, class C>
bool GroupDoubleCircularLinkedList<G, C>::checkWinner() {
	
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::skipTurn() {
	
	if(flag_reverse)
	{
		// change to previousgroup() x2 function?
		current = (current->previous)->previous;
	}
	else
	{
		current = (current->next)->next;
	}
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::reverse() {


}


#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
