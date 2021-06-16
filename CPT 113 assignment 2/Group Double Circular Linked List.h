#ifndef GROUPDOUBLECIRCULARLINKEDLIST_H
#define GROUPDOUBLECIRCULARLINKEDLIST_H
#include"Group.h"
#include <iostream>
#include <string>
using namespace std;

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
	GroupNode* head; // First Group added 
	GroupNode* current; // To keep track of which group's turn
	int no_of_group;
	int player_turn; // To keep track of which player's turn
	bool flag_reverse; // To track the direction of the flow of the game

public:
	GroupDoubleCircularLinkedList();
	~GroupDoubleCircularLinkedList();
	int getNoOfGroup();
	int getPlayerTurn(); 
	void getCurrentNode(G&);
	void updateGroupScore(G);
	void findHighestScoreGroup(G&);
	bool isEmpty();				
	void displayList();
	void addNewGroupAtEnd(G);	
	void NextGroup();
	void RemoveGroup();
	void skipTurn();
	void reverse();		

};

// Constructor
template<class G>
GroupDoubleCircularLinkedList<G>::GroupDoubleCircularLinkedList()
{
	head = nullptr; 
	current = nullptr;
	flag_reverse = false;
	no_of_group = 0;
	player_turn = 0;
}

// Destructor
template<class G>
GroupDoubleCircularLinkedList<G>::~GroupDoubleCircularLinkedList()
{
	GroupNode* Node_ptr = nullptr;

	// Delete all the nodes in the double circular linked list
	for (int i = 0; i < no_of_group; i++) {
		Node_ptr = head;
		head = head->next;
		delete Node_ptr;
		no_of_group--;
	}
	head = nullptr;
	current = nullptr;
}

/*
	Setters and Getters
*/
// Number of group getter
template<class G>
int GroupDoubleCircularLinkedList<G>::getNoOfGroup() {
	return no_of_group;
}

// Player Turn getter
template<class G>
int GroupDoubleCircularLinkedList<G>::getPlayerTurn() {
	return player_turn;
}

// Save the group data of current group to main group object
template<class G>
void GroupDoubleCircularLinkedList<G>::getCurrentNode(G& store_group) {
	store_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());
}

// Save the updated scored from main to current group
template<class G>
void GroupDoubleCircularLinkedList<G>::updateGroupScore(G group) {
	current->value.setGroup(group.getScore(), group.getPlayer1Name(), group.getPlayer2Name(), group.getGroupName());
}

// Save the group with the highest score to main group object
template<class G>
void GroupDoubleCircularLinkedList<G>::findHighestScoreGroup(G& winner_group) {
	int Highest = current->value.getScore();

	// Find the highest
	for (int i = 0; i < no_of_group; i++) {
		if (current->value.getScore() > Highest) {
			Highest = current->value.getScore();
		}
		NextGroup();
	}

	// Find the group with the highest score
	for (int i = 0; i < no_of_group; i++) {
		if (current->value.getScore() == Highest) {
			winner_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());
			break;
		}
		NextGroup();
	}
}

/*
	Methods for Double Circular Linked List
*/
// Return true if the double circular linked list is empty
template<class G>
bool GroupDoubleCircularLinkedList<G>::isEmpty() {
	return head == nullptr;
}

// Display all the group in the linked list
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

// Add new group at the end of double circular linked list
template<class G>
void GroupDoubleCircularLinkedList<G>::addNewGroupAtEnd(G new_group) {
	
	GroupNode* New_node; 

	// Allocate a new node
	New_node = new GroupNode; 
	GroupNode* Node_ptr;
	Node_ptr= nullptr; 

	// Store value inside new node and point to head
	New_node->value.setGroup(new_group.getScore(), new_group.getPlayer1Name(), new_group.getPlayer2Name(), new_group.getGroupName());
	New_node->next = head;
	
	Node_ptr = head;
	
	if (isEmpty() == true) {
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
		current = New_node; 
	}
	no_of_group++;
}

// Transverse to next group based on the direction of gameplay
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

// Remove the current group
template<class G>
void GroupDoubleCircularLinkedList<G>::RemoveGroup() {
	
	// The current group is immediately removed when they lose, i.e. more than max cards(10)
	// Possible number of groups for this method are 2,3,4
	// Hence, when using this function, no need to check for empty list

	Group removed_group;
	GroupNode* Node_ptr = nullptr;
	GroupNode* Previous_node = nullptr;

	// Store the details of the removed group
	removed_group.setGroup(current->value.getScore(), current->value.getPlayer1Name(), current->value.getPlayer2Name(), current->value.getGroupName());

	// If the node needed to be deleted is at head
	if (current == head) {
		Node_ptr = head;
		Previous_node = Node_ptr->previous;

		// Change head (head will always points to some nodes)
		// and update current pointer
		head = head->next;
		current = head;

		// Connect back to remaining nodes
		head->previous = Previous_node;
		Previous_node->next = head;

		delete Node_ptr;
	}
	else // If the node needed to be deleted is at place other than head
	{
		Node_ptr = current;
		Previous_node = Node_ptr->previous;
		Previous_node->next = Node_ptr->next;

		// If the node needed to be deleted is someway in the middle
		if (Node_ptr->next != head) {
			Node_ptr->next->previous = Previous_node;
		}
		// If the node needed to be deleted is at the end
		else {
			// Connect by the head node to previous node as a double cicular linked list
			head->previous = Previous_node;
		}

		// Update current pointer
		current = current->next;

		delete Node_ptr;
	}
	no_of_group--;

	// After removal, display a message first
	cout << "\t\t\tYou Lose! You have more than 10 cards already.\n";
	cout << "\t\t\tNice try. Good luck next time.\n";
	cout << "\t\t\t\t\tGroup " << removed_group.getGroupName() << " is dropped out.\n";
	system("pause");
}

// Skip the next player
template<class G>
void GroupDoubleCircularLinkedList<G>::skipTurn() {
	
	// Run 2 times to skip the next player
	NextGroup();
	NextGroup();
}

// Reverse the current direction of the gameplay
template<class G>
void GroupDoubleCircularLinkedList<G>::reverse() {
	flag_reverse = !flag_reverse;
	NextGroup();
}

#endif // !GROUPDOUBLECIRCULARLINKEDLIST_H
