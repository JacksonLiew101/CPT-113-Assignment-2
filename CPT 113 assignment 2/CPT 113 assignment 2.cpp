#include"Group.h"
#include"Group Double Circular Linked List.h"
#include"HandDeck Linked List.h"
#include"Discard Pile Stack.h"
#include"DrawPile Stack.h"

#include<iostream>
#include<string>
using namespace std;
void Welcome();
void Rule();
int main() {
	Card card1;
	//GroupDoubleCircularLinkedList<Group, Card> gameplay1;
	DrawPileStack<Card> drawpile1;
	DiscardPileStack<Card> discardpile1;
	card1.setCard("1", "Red", 1);
	GroupDoubleCircularLinkedList<Group, Card> Team;
	
	return 0;
}

void Welcome()
{
    cout << "\t\t\t"
         << "   " << dt << endl;

    cout << "\t**************************************************************" << endl
         << endl; //Greet the user
    cout << "\t\t\tWelcome to the UNO card multiplayer games"  << endl
         << endl;
    cout << "\t\t\tBefore starting the game, please go through the README text file in the same folders for the instruction and game rules" << endl
         << endl;
    cout << "\t**************************************************************" << endl
         << endl;
    system("pause");
}

void Rule()
{
        cout << "\t**************************************************************" << endl
         << endl; //Greet the user
    cout << "\t\t\tThis game is a multiplayer game."  << endl
         << endl;
             cout << "\t\t\tSpecifically, you should have at least 2 groups of players for the gameplay and each group will involve 2 players playing the same deck."  << endl
         << endl;
             cout << "\t\t\tTo win the game, the 2 players of the same group should" << endl
                 << "1.accumulate the highest scores when the Draw Pile is empty or,\n"
                 << "2. be the first group which empty the Hand Decks\n";
             << "3. be the last group in the game\n";
         << endl;
    cout << "\t**************************************************************" << endl
         << endl;
    system("pause");
}