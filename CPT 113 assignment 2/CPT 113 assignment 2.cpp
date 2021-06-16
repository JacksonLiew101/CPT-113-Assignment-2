#include"Group Double Circular Linked List.h"
#include"HandDeck Linked List.h"
#include"Discard Pile Stack.h"
#include"DrawPile Stack.h"

#include<iostream>
#include<string>
using namespace std;
const int STARTING_CARD_NO = 5;
void Welcome();
void Rule();
int main() {
    // Data Structures, Objects and Variables needed
    DrawPileStack<Card> drawpile;
    DiscardPileStack<Card> discardpile;
    GroupDoubleCircularLinkedList<Group, Card> groupsinplay;
    //IndexLinkedList indexvalidcard;???
    HandDeckLinkedList<Card> HandDeckA;
    HandDeckLinkedList<Card> HandDeckB;
    HandDeckLinkedList<Card> HandDeckC;
    HandDeckLinkedList<Card> HandDeckD;
    HandDeckLinkedList<Card>* current_deck = nullptr;
    Card temp_card1;
    Card temp_card2;
    Group temp_group;
    int number_of_groups = 0;
    string group_name, player1_name, player2_name, action;
    string group_list = "ABCD";
    
    Welcome();
    Rule();
    do
    {
        cout << "Enter the number of groups to play: ";
        cin >> number_of_groups;
        if(number_of_groups<2 || number_of_groups> 4)
        {
            cout << "Invalid value. Please make sure that the number of groups is between 2 to 4\n";
        }
    }while(number_of_groups<2 || number_of_groups> 4);
   
	// create groups
    for (int i = 0; i < number_of_groups; i++) {
        cout << "\nEnter player 1's name for this group " << group_list[i] << ": ";
        cin >> player1_name;
        cout << "\nEnter player 2's name for this group " << group_list[i] << ": ";
        cin >> player2_name;
        group_name = group_list[i];
        temp_group.setGroup(0, player1_name, player2_name, group_name);
        groupsinplay.addNewGroupAtEnd(temp_group);
    }

    // initialise handdeck for each groups
    // group now is last added group
    for (int i = 0; i < STARTING_CARD_NO; i++) {

        for (int j = 0; j < number_of_groups; j++) {
            //change deck based on current group

            // add one card for each group at a time

            // change group
            
             // function should get the name if name==this, point this to that
            // void name(string name, Class *&, Class &, Class &, Class &, Class &)
        }
    }
	
	return 0;
}

void Welcome()
{
 

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
                 << "2. be the first group which empty the Hand Decks\n"
             << "3. be the last group in the game\n"
         << endl;
    cout << "\t**************************************************************" << endl
         << endl;
    system("pause");
}