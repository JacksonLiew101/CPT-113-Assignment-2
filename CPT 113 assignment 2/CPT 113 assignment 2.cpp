//#include"Group.h"
//#include"Group Double Circular Linked List.h"
#include"HandDeck Linked List.h"
#include"Discard Pile Stack.h"
#include"DrawPile Stack.h"
//#include"Card.h"

#include<iostream>
#include<string>
using namespace std;

int main() {
	Card card1;
	//GroupDoubleCircularLinkedList<Group, Card> gameplay1;
	DrawPileStack<Card> drawpile1;
	DiscardPileStack<Card> discardpile1;
	card1.setCard("1", "Red", 1);
	
	
	return 0;
}