#ifndef DRAWPILE_STACK_H
#define DRAWPILE_STACK_H
#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include "Card.h" 
using namespace std;
const int NUMBER_OF_LABELS = 2; // value and colour
const int NUMBER_OF_CARDS = 40; 

template <class C>
class DrawPileStack
{
private:
	//structure for the queue node
	struct CardNode
	{
		C value; // value in a node
		struct CardNode* next; // pointer to the next node
	};
	CardNode* top;
	
public:
	//constructor
	DrawPileStack(); // done
	//destructor
	~DrawPileStack(); // done
	bool isEmpty(); // done
	void pushCard(C); // done
	void popCard(C&); // done
	void generateDeck(); // done
	void swap(int*, int*); // done
	void randomize(int arr[], int n); // done
	void displayStack(); // done
	void setStackCard(string, string,int); // done
};

template <class C>
void DrawPileStack<C>::setStackCard(string v, string c, int s)
{
	top->value.setValue(v);
	top->value.setColour(c);
	top->value.setScore(s);

}

template <class C>
void DrawPileStack<C>::displayStack()
{
	CardNode* Node_ptr;
	Node_ptr = top;

	while (!(Node_ptr==nullptr)) {
		Node_ptr->value.displayCard();
		cout << endl;
		Node_ptr = Node_ptr->next;
	}
}

template <class C>
DrawPileStack<C>::DrawPileStack() {
	top = nullptr;
	generateDeck();
}

template <class C>
DrawPileStack<C>::~DrawPileStack() {
	CardNode* Node_ptr = nullptr;

	// delete every card node until the stack is empty
	while (!isEmpty()) {
		Node_ptr = top;

		top = top->next;

		delete Node_ptr;
	}
}

template <class C>
bool DrawPileStack<C>::isEmpty() {
	return (top == nullptr);
}

template<class C>
void DrawPileStack<C>::pushCard(C new_card)
{
	// allocate a new node
	CardNode* New_node = nullptr;
	New_node = new CardNode;
	New_node->value = new_card;
	New_node->next = nullptr;

	if (isEmpty()) {
		// This means it will be the first node, make top point to new node
		top = New_node;
	}
	else {
		// Make new pointer of new node point to the current top
		New_node->next = top;

		// Update top to point to new node
		top = New_node;
	}

	//cout << "Inside pushing" << endl;
	//top->value.displayCard();
	//system("pause");
}

template <class C>
void DrawPileStack<C>::popCard(C& value) {
	// tracker
	CardNode* Node_ptr = nullptr;

	if (isEmpty()) {
		cout << "The Draw Pile is now empty" << endl;
	}
	else {
		// point temp pointer to the top first
		Node_ptr = top;

		// update top to point to next node in line
		top = top->next;

		// store the value into the input variable
		value.setCard(Node_ptr->value.getValue(),Node_ptr->value.getColour(), Node_ptr->value.getScore());

		// delete previous top node
		delete Node_ptr;
	}
};

template <class C>
void DrawPileStack<C>::generateDeck() 
{
	//int total = 0;
	
	int labels[NUMBER_OF_CARDS] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
	string Cards[NUMBER_OF_CARDS][NUMBER_OF_LABELS] =
	{
		{"1","Red"},
		{"2","Red"},
		{"3","Red"},
		{"4","Red"},
		{"5","Red"},

		{"1","Blue"},
		{"2","Blue"},
		{"3","Blue"},
		{"4","Blue"},
		{"5","Blue"},

		{"1","Yellow"},
		{"2","Yellow"},
		{"3","Yellow"},
		{"4","Yellow"},
		{"5","Yellow"},

		{"1","Green"},
		{"2","Green"},
		{"3","Green"},
		{"4","Green"},
		{"5","Green"},

		{"Draw Two","Red"},
		{"Draw Two","Blue"},
		{"Draw Two","Yellow"},
		{"Draw Two","Green"},

		{"Wild Draw Four","White"},
		{"Wild Draw Four","White"},
		{"Wild Draw Four","White"},
		{"Wild Draw Four","White"},

		{"Skip","Red"},
		{"Skip","Blue"},
		{"Skip","Yellow"},
		{"Skip","Green"},

		{"Reverse","Red"},
		{"Reverse","Blue"},
		{"Reverse","Yellow"},
		{"Reverse","Green"},

		{"Wild","White"},
		{"Wild","White"},
		{"Wild","White"},
		{"Wild","White"},
	};
	int n = 40;
	randomize(labels, n);
	Card newcard; // create a new card class
	for(int i = 0; i<NUMBER_OF_CARDS; i++)
	{
	
		//Card newcard;
		int a = labels[i];
		string temp;
		for(int j = 0; j<NUMBER_OF_LABELS; j++)
		{
			temp = Cards[a][j];
			if(j == 0)
			{
				newcard.setValue(temp);
			}
			else if( j == 1)
			{
				newcard.setColour(temp);
			}
		}
		//set the scores for each card
		// if it is skip, reverse, draw two, score is 20 points
		if(newcard.compareStrings(newcard.getValue(),"Skip") || newcard.compareStrings(newcard.getValue(),"Reverse") ||newcard.compareStrings(newcard.getValue(),"Draw Two" ) )
		{
			newcard.setScore(20);
		}
		//if it is wild and wild draw four, score is 50 points
		else if(newcard.compareStrings(newcard.getValue(),"Wild") || newcard.compareStrings(newcard.getValue(),"Wild Draw Four") )
		{
			newcard.setScore(50);
		}

		// if it is number card, score is according to the number value
		if(newcard.compareStrings(newcard.getValue(),"1") )
		{
			newcard.setScore(1);
		}
		else if(newcard.compareStrings(newcard.getValue(),"2"))
		{
			newcard.setScore(2);
		}
		else if(newcard.compareStrings(newcard.getValue(),"3"))
		{
			newcard.setScore(3);
		}
		else if(newcard.compareStrings(newcard.getValue(),"4"))
		{
			newcard.setScore(4);
		}
		else if(newcard.compareStrings(newcard.getValue(),"5"))
		{
			newcard.setScore(5);
		}

		// before push testing
		//cout << "This is before pushing" << endl;
		//newcard.displayCard();
		//system("pause");

		// push this new cardNode into DrawPile Stack
		pushCard(newcard);
		//total++;
		//cout << "After pushing" << endl;
		//displayStack();
		//system("pause");
	}

	//cout << "Total card is pushed:" << total << endl;
	//system("pause");
}

template<class C>
void DrawPileStack<C>::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

template<class C>
void DrawPileStack<C>::randomize(int arr[], int n)
{
	srand(time(NULL));

	for(int i = n-1; i>0; i--)
	{
		int j = rand() % (i+1);

		swap(&arr[i], &arr[j]);
	}
}





#endif  // !DRAWPILE_STACK_H
