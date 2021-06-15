#ifndef DRAWPILE_STACK_H
#define DRAWPILE_STACK_H
#include<iostream>
using namespace std;

template <class C>
class DrawPileStack
{
private:
	//structure for the queue node
	struct CardNode
	{
		C value; // value in a node
		CardNode* next; // pointer to the next node
	};
	CardNode* TopStack;
public:
	//constructor
	DrawPileStack();
	//destructor
	~DrawPileStack();
	bool isEmpty();
	void pushCard(C);
	void popCard(C&);
	void generateDeck();
};

template <class C>
DrawPileStack<C>::DrawPileStack() {
	generateDeck();
}

template <class C>
DrawPileStack<C>::~DrawPileStack() {
	//destroy deck
}

template <class C>
bool DrawPileStack<C>::isEmpty() {
	return (TopStack == nullptr);
}

template<class C>
void DrawPileStack<C>::pushCard(C)
{
}

template <class C>
void DrawPileStack<C>::popCard(C& value) {
	if (isEmpty()) {
		cout << "The stack is empty now." << endl;
	}
	else {

	}
};

template <class C>
void DrawPileStack<C>::generateDeck() {

};




#endif  // !DRAWPILE_STACK_H
