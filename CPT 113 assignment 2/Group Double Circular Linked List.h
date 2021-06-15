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
	void NextGroup();			// done
	void RemoveGroup(G&);		// done
	void setFlagReverse(); // detect the reverse card at the main function
	bool getFlagReverse();		// done, KIV 
	bool checkWinner(); // detect it at the main function
	void skipTurn();			// done
	void reverse();				// done, probably need to only keep reverse() or setFlagReverse
	string getGroupNameFromList();
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
	if (flag_reverse) {
		current = current->previous;
	}
	else
	{
		current = current->next;
	}
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::RemoveGroup(G& out_group) {
	
	// the current group is immediately removed when they lose, i.e. more than max cards
	// possible number of groups for this function are 2,3,4
	// Hence, when using this function, the list will not be empty

	GroupNode* Node_ptr = nullptr;
	GroupNode* Previous_node = nullptr;

	// if the node needed to be deleted is at head
	if (current == head) {
		// track the node first
		Node_ptr = head;
		Previous_node = Node_ptr->previous;

		// change head, this function only run during 2-4 groups, head will
		// always points to some nodes
		// and update current pointer
		head = head->next;
		current = head;

		// connect to remaining nodes
		head->previous = Previous_node;
		Previous_node->next = head;

		// delete node
		delete Node_ptr;
	}
	// if the node needed to be deleted is at place other than head
	else {
		Node_ptr = current;
		Previous_node = Node_ptr->previous;
		Previous_node->next = Node_ptr->next;

		// if the node needed to be deleted is someway in the middle
		if (Node_ptr->next != head) {
			Node_ptr->next->previous = Previous_node;
		}
		// if the node needed to be deleted is at then end
		else {
			// connect by the head node to previous node as a cicular linked list
			head->previous = Previous_node;
		}

		//update current pointer
		current = current->next;

		// delete node
		delete Node_ptr;
	}
	no_of_group--;
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
	
	//run 2 times to skip the next player
	NextGroup();
	NextGroup();
}

template<class G, class C>
void GroupDoubleCircularLinkedList<G, C>::reverse() {
	// probably using one function enough
	setFlagReverse();
}


template<class G, class C>
string GroupDoubleCircularLinkedList<G, C>::getGroupNameFromList()
{
	return current->value.getGroupName();
}

#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
