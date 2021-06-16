#ifndef GROUPDOUBLECIRCULARLINKEDLIST_H
#define GROUPDOUBLECIRCULARLINKEDLIST_H
#include"Group.h"


// This is the template class for Group Double Circular Linked List
template <class G>
class GroupDoubleCircularLinkedList
{
private:
	struct GroupNode
	{
		G value;
		struct GroupNode* next;
		struct GroupNode* previous;
	};
	GroupNode* head; // 1st Group
	GroupNode* current; // to keep track of whose turns
	int no_of_group;
	bool flag_reverse;
	int player_turn; // put here instead of Group.h because for whole round will keep the same player going

public:
	//constructor
	GroupDoubleCircularLinkedList();
	// destructor
	~GroupDoubleCircularLinkedList();

	bool isEmpty();				
	void displayList();
	void addNewGroupAtEnd(G);	// done
	void NextGroup();			// done
	void RemoveGroup();		// done
	void setFlagReverse(); // detect the reverse card at the main function, probably won't need
	bool getFlagReverse();		// done, probably won't need
	void skipTurn();			// done
	void reverse();				// done, probably need to only keep reverse() or setFlagReverse
	//string getGroupNameFromList(); // done, probably need to removed
	void getCurrentNode(G&);
	int getPlayerTurn();
	void updateGroupScore(G);
	int getNoOfGroup();
	void findHighestScoreGroup(G&);
};

//constructor
template<class G>
GroupDoubleCircularLinkedList<G>::GroupDoubleCircularLinkedList()
{
	head = nullptr; 
	current = nullptr;
	flag_reverse = false;
	no_of_group = 0;
	player_turn = 0;
}

//destructor
template<class G>
GroupDoubleCircularLinkedList<G>::~GroupDoubleCircularLinkedList()
{
	GroupNode* Node_ptr = nullptr;

	for (int i = 0; i < no_of_group; i++) {
		Node_ptr = head;
		head = head->next;
		delete Node_ptr;
		no_of_group--;
	}
	head = nullptr;
	current = nullptr;
}

template<class G>
bool GroupDoubleCircularLinkedList<G>::isEmpty() {
	return head == nullptr;
}

template<class G>
void GroupDoubleCircularLinkedList<G>::displayList() {
	GroupNode* Node_ptr = nullptr;
	Node_ptr = head;

	for (int i = 0; i < no_of_group; i++, Node_ptr = Node_ptr->next) {
		cout << Node_ptr->value.getScore() << ", "
			<< Node_ptr->value.getPlayer1Name() << ", "
			<< Node_ptr->value.getPlayer2Name() << ", "
			<< Node_ptr->value.getGroupName() << endl;
	}

}


template<class G>
void GroupDoubleCircularLinkedList<G>::addNewGroupAtEnd(G new_group) {
	
	GroupNode* New_node; 
	New_node = new GroupNode; // allocate a new node
	GroupNode* Node_ptr;
	Node_ptr= nullptr; // tracker to move through list

	// store value inside new node and point to head
	New_node->value = new_group;
	New_node->next = head;
	
	Node_ptr = head;
	
	if (isEmpty() == true) {
		New_node->next = New_node;
		New_node->previous = New_node;
		head = New_node;
		current = head;
	}
	else {
		//here got problem
		(head->previous)->next = New_node;	
		New_node->previous = head->previous;
		New_node->next = head;
		head->previous = New_node;
		current = New_node; // I changed this liao, from current = head->previous
	}
	no_of_group++;


}

template<class G>
void GroupDoubleCircularLinkedList<G>::NextGroup() {
	if (flag_reverse == true) {
		current = current->previous;
	}
	else
	{
		current = current->next;
	}

	// After changing current group, check if need to switch player or not
	if (current == head) {
		//automatic flips between 0 and 1 when called
		player_turn = 1 - player_turn;
	}
}

template<class G>
void GroupDoubleCircularLinkedList<G>::RemoveGroup() {
	
	// the current group is immediately removed when they lose, i.e. more than max cards
	// possible number of groups for this function are 2,3,4
	// Hence, when using this function, the list will not be empty

	Group removed_group;
	GroupNode* Node_ptr = nullptr;
	GroupNode* Previous_node = nullptr;

	removed_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());

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


	// after removal display a message first
	cout << "\t\t\tYou Lose! You have more than 10 cards already.\n";
	cout << "\t\t\tNice try. Good luck next time.\n";
	cout << "\t\t\t\t\tGroup " << removed_group.getGroupName() << " is dropped out.\n";
	system("pause");


}

template<class G>
void GroupDoubleCircularLinkedList<G>::setFlagReverse() {
	flag_reverse = !flag_reverse;
}

template<class G>
bool GroupDoubleCircularLinkedList<G>::getFlagReverse() {
	return flag_reverse;
}

template<class G>
void GroupDoubleCircularLinkedList<G>::skipTurn() {
	
	//run 2 times to skip the next player
	NextGroup();
	NextGroup();
}

template<class G>
void GroupDoubleCircularLinkedList<G>::reverse() {
	// probably using one function enough
	setFlagReverse();
	//  suggestion: immediately change to next player here
	NextGroup();
}

/*
template<class G, class C>
string GroupDoubleCircularLinkedList<G, C>::getGroupNameFromList()
{
	return current->value.getGroupName();
}
*/

template<class G>
void GroupDoubleCircularLinkedList<G>::getCurrentNode(G& store_group) {
	store_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());
}

template<class G>
int GroupDoubleCircularLinkedList<G>::getPlayerTurn() {
	return player_turn;
}

template<class G>
void GroupDoubleCircularLinkedList<G>::updateGroupScore(G group) {
	current->value.setGroup(group.getScore(), group.getPlayer1Name(), group.getPlayer2Name(), group.getGroupName());
}

template<class G>
int GroupDoubleCircularLinkedList<G>::getNoOfGroup() {
	return no_of_group;
}

template<class G>
void GroupDoubleCircularLinkedList<G>::findHighestScoreGroup(G& winner_group) {
	int Highest = current->value.getScore();

	// find the highest
	for (int i = 0; i < no_of_group; i++) {
		if (current->value.getScore() > Highest) {
			Highest = current->value.getScore();
		}
		NextGroup();
	}

	// find the group with the highest score
	for (int i = 0; i < no_of_group; i++) {
		if (current->value.getScore() == Highest) {
			winner_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());
			break;
		}
		NextGroup();
	}
}

#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
