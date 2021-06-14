#ifndef DRAWPILE_STACK_H
#define DRAWPILE_STACK_H
#include<iostream>
using namespace std;

template <class T>
class DrawPileStack
{
private:
	//structure for the queue node
	struct CardNode
	{
		T value; // value in a node
		CardNode* next; // pointer to the next node
	};
	CardNode* TopStack;
public:
	//constructor
	DrawPileStack();
	//destructor
	~DrawPileStack();
	bool isEmpty();
	void pushCard(T);
	void popCard(T&);
	void generateDeck();
};

template <class T>
DrawPileStack<T>::DrawPileStack() {
	generateDeck();
}

template <class T>
DrawPileStack<T>::~DrawPileStack() {
	//destroy deck
}

template <class T>
bool DrawPileStack<T>::isEmpty() {
	return (TopStack == nullptr);
}

template <class T>
void DrawPileStack<T>::popCard(T& value) {
	if (isEmpty()) {
		cout << "The stack is empty now." << endl;
	}
	else {

	}
};

void generateDeck() {

};




#endif  // !DRAWPILE_STACK_H
