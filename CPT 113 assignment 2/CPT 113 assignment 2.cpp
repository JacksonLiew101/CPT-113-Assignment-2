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
void UpdateHandDeckPtr(Group, HandDeckLinkedList<Card> *&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&);
void End();

int main() {
    // Data Structures, Objects and Variables needed
    DrawPileStack<Card> drawpile;
    DiscardPileStack<Card> discardpile;
    GroupDoubleCircularLinkedList<Group> groupsinplay;
    //IndexLinkedList indexvalidcard;???
    HandDeckLinkedList<Card> HandDeckA;
    HandDeckLinkedList<Card> HandDeckB;
    HandDeckLinkedList<Card> HandDeckC;
    HandDeckLinkedList<Card> HandDeckD;
    HandDeckLinkedList<Card>* current_deck = nullptr;
    Card temp_card;
    Card choose_card;
    Group temp_group;
    int number_of_groups = 0;
    int player_choice_card_index = 0;
    string group_name, player1_name, player2_name, action;
    string group_list = "ABCD";
    bool winner_flag = false; 

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
            // change group before starting, first card start at first group
            groupsinplay.NextGroup();

            // change deck based on current group
            groupsinplay.getCurrentNode(temp_group);
            UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

            // add one card for each group at a time
            drawpile.popCard(temp_card);
            current_deck->drawCard(temp_card);
        }
    }
	
    
    //pop out 1 card from drawpile as starting card
    //change the starting card if the first popped out card is action card
    drawpile.popCard(temp_card);

    if(temp_card.compareStrings(temp_card.getValue(),"Draw Two")||temp_card.compareStrings(temp_card.getValue(),"Skip")||temp_card.compareStrings(temp_card.getValue(),"Reverse"))
    {
        temp_card.setValue("1");
    }
    else if(temp_card.compareStrings(temp_card.getValue(),"Wild Draw Four")||temp_card.compareStrings(temp_card.getValue(),"Wild"))
    {
        temp_card.setValue("1");
        temp_card.setColour("Red");
    }
    discardpile.push(temp_card);
    

    //start game
    //before starting the card details is stored in the temp_card
    while (!winner_flag) {
        
        // check action
        action = discardpile.getActionStatement();

        if (action == "Reverse")
        {
            // change direction of the gameplay 
            groupsinplay.reverse();
            groupsinplay.getCurrentNode(temp_group);
            UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);
            
        }
        else if (action == "Skip") {
            // skip the next player in turn
            groupsinplay.skipTurn();
            groupsinplay.getCurrentNode(temp_group);
            UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);
        }
        else {
            // for cards that don't involve changing player turns by force
            groupsinplay.NextGroup();
            groupsinplay.getCurrentNode(temp_group);
            UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

            if (action == "Draw Two") {
                for (int i = 0; i < 2; i++) {
                    drawpile.popCard(temp_card);
                    if (drawpile.isEmpty()) {
                        winner_flag = true;
                    }
                    current_deck->drawCard(temp_card);
                }
            }

            if (action == "Wild Draw Four") {
                for (int i = 0; i < 4; i++) {
                    drawpile.popCard(temp_card);
                    if (drawpile.isEmpty()) {
                        winner_flag = true;
                    }
                    current_deck->drawCard(temp_card);
                }
            }
        }
        
        // for player starts to check card, update back the card to the card at the top of discard pile first
        discardpile.peek(temp_card);


        // interface for gameplay
        //system("cls");
        cout << "\t\t\t" << "Current Number Card" << endl;
        cout << "\t\t\t";
        temp_card.displayCard();

        // display message for action cards (if exist)
        if (action == "Draw Two") {
            cout << "\n\n'Draw Two' card is used. 2 cards is drawed to your hand deck\n\n";
        }
        else if (action == "Wild Draw Four") {
            cout << "\n\n'Wild Draw Four' card is used. 4 cards is drawed to your hand deck.\n" 
                 << temp_card.getColour() << " is the new colour.\n\n";
        }
        else if (action == "Wild") {
            cout << "\n\n'Wild' card is used.\n"
                << temp_card.getColour() << " is the new colour.\n\n";
        }
        else if (action == "Skip") {
            cout << "\n\n'Skip' card is used. It is your turn now.\n\n";
        }
        else if (action == "Reverse") {
            cout << "\n\n'Reverse' card is used. Direction is changed. It is your turn now.\n\n";
        }
        else {
            cout << "\n\n";
        }

        cout << "\t\t\tYour turn now!\n";
        if (groupsinplay.getPlayerTurn() == 0) {
            cout << temp_group.getPlayer1Name() << " from Group " << temp_group.getGroupName() << endl;
        }
        else {
            cout << temp_group.getPlayer2Name() << " from Group " << temp_group.getGroupName() << endl;
        }

         //first, show all the hand cards
        cout << "This is your current hand cards\n";
        current_deck->showHandCards();
        cout << "\n\n";

         // check current hand card >10, drop group
         if (current_deck->getNumberOfHandCards() > 10) {
             //remove the group
             groupsinplay.RemoveGroup();
             //update to the remaining group
             groupsinplay.getCurrentNode(temp_group);
         }
         else
         {
             //second, show all the valid cards, if still less than 10 cards
             current_deck->showValidCard(temp_card);
             while (current_deck->showIndexLinkedListHead() == 0 && !drawpile.isEmpty())
             {
                 cout << "Looks like you don't have any valid card in your hand\n";
                 cout << "You need to draw one more card until you have at least 1 valid card\n";
                 system("pause");
                 if (current_deck->showIndexLinkedListHead() == 0)
                 {
                     current_deck->clearIndexList();
                     drawpile.popCard(choose_card);
                     if (drawpile.isEmpty()) {
                         winner_flag = true;
                         break;
                     }
                     current_deck->drawCard(choose_card);
                     cout << endl << endl;
                     temp_card.displayCard();
                     current_deck->showHandCards();
                     current_deck->showValidCard(temp_card);
                 }
             }

             cout << endl;
             //prompt the valid card index
             do
             {
                 cout << "Please play a card(choose the valid card index): ";
                 cin >> player_choice_card_index;
                 if (current_deck->searchIndex(player_choice_card_index) == false)
                 {
                     cout << "Invalid input. Please choose a valid card index\n";
                 }
             } while (current_deck->searchIndex(player_choice_card_index) == false);

             //after getting the valid card index, use that card index to copy the card to temp card
             current_deck->copyValidChosenCard(player_choice_card_index, choose_card);

             //play that card and save that card into temp_card
             current_deck->playCard(choose_card, temp_card);
             current_deck->showIndexLinkedList();
             //add score to the group
             temp_group.addScore(temp_card.getScore());
             groupsinplay.updateGroupScore(temp_group);

             //after played that card, need to clear the index linked list
             current_deck->clearIndexList();
             //send that out card to discard pile
             discardpile.push(temp_card);
             // end this turn, go to the next player by repeating this loop
         }

        // check winner 
        if (drawpile.isEmpty()) {
            winner_flag = true;
            groupsinplay.findHighestScoreGroup(temp_group);
        }
        else if (current_deck->isEmpty()) {
            winner_flag = true;
        }
        else if (groupsinplay.getNoOfGroup()==1) {
            winner_flag = true;
        }

    }

    // display the winners
    cout << "\t\t\tCongratulations\n";
    cout << temp_group.getPlayer1Name() << " and " << temp_group.getPlayer2Name() << " from\n";
    cout << "Group " << temp_group.getGroupName() << " wins the game!!!!\n";
    cout << "With a score of " << temp_group.getScore();
    cout << "\n\nThe game is now ended. To play again, run the game program file from the folder.\n";

  
	return 0;
}

void Welcome()
{
 

    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; //Greet the user
    cout<<"\t\t                                                                                                   .         .                          \n";
    cout<<"\t\t `8.`888b                 ,8' 8 8888888888   8 8888         ,o888888o.        ,o888888o.           ,8.       ,8.          8 8888888888   \n";
    cout<<"\t\t  `8.`888b               ,8'  8 8888         8 8888        8888     `88.   . 8888     `88.        ,888.     ,888.         8 8888         \n";
    cout<<"\t\t   `8.`888b             ,8'   8 8888         8 8888     ,8 8888       `8. ,8 8888       `8b      .`8888.   .`8888.        8 8888         \n";
    cout<<"\t\t    `8.`888b     .b    ,8'    8 8888         8 8888     88 8888           88 8888        `8b    ,8.`8888. ,8.`8888.       8 8888         \n";
    cout<<"\t\t    `8.`888b    88b  ,8'     8 888888888888 8 8888     88 8888           88 8888         88   ,8'8.`8888,8^8.`8888.      8 888888888888  \n";
    cout<<"\t\t      `8.`888b .`888b,8'      8 8888         8 8888     88 8888           88 8888         88  ,8' `8.`8888' `8.`8888.     8 8888         \n";
    cout<<"\t\t       `8.`888b8.`8888'       8 8888         8 8888     88 8888           88 8888        ,8P ,8'   `8.`88'   `8.`8888.    8 8888         \n";
    cout<<"\t\t        `8.`888`8.`88'        8 8888         8 8888     `8 8888       .8' `8 8888       ,8P ,8'     `8.`'     `8.`8888.   8 8888         \n";
    cout<<"\t\t        `8.`8' `8,`'         8 8888         8 8888        8888     ,88'   ` 8888     ,88' ,8'       `8        `8.`8888.  8 8888          \n";
    cout<<"\t\t         `8.`   `8'          8 888888888888 8 888888888888 `8888888P'        `8888888P'  ,8'         `         `8.`8888. 8 888888888888  \n"
         << endl;
    cout<<"\t\t\t\t\t\t\t\t8888888 8888888888 ,o888888o.     \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888    . 8888     `88.   \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888   ,8 8888       `8b  \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888   88 8888        `8b \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888   88 8888         88 \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888   88 8888         88 \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888   88 8888        ,8P \n";
	cout<<"\t\t\t\t\t\t\t\t     8 8888   `8 8888       ,8P  \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888    ` 8888     ,88'   \n";
	cout<<"\t\t\t\t\t\t\t\t      8 8888       `8888888P'     \n";   
	cout << endl;
    cout<<"\t\t\t\t\t\t8 8888      88           b.             8               ,o888888o.     \n";
    cout<<"\t\t\t\t\t\t8 8888      88           888o.          8            . 8888     `88.   \n";
    cout<<"\t\t\t\t\t\t8 8888      88           Y88888o.       8           ,8 8888       `8b  \n";
    cout<<"\t\t\t\t\t\t8 8888      88           .`Y888888o.    8           88 8888        `8b \n";
    cout<<"\t\t\t\t\t\t8 8888      88           8o. `Y888888o. 8           88 8888         88 \n";
    cout<<"\t\t\t\t\t\t8 8888      88           8`Y8o. `Y88888o8           88 8888         88 \n";
    cout<<"\t\t\t\t\t\t8 8888      88           8   `Y8o. `Y8888           88 8888        ,8P \n";
    cout<<"\t\t\t\t\t\t  8888     ,8P           8      `Y8o. `Y8           `8 8888       ,8P   \n";
    cout<<"\t\t\t\t\t\t  8888   ,d8P            8         `Y8o.`            ` 8888     ,88'    \n";
    cout<<"\t\t\t\t\t\t   `Y88888P'             8            `Yo               `8888888P'     \n";
    cout << endl;
    
    cout << "\t\t\tBefore starting the game, please go through the README text file in the same folders for the instruction and game rules" << endl
         << endl;
    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl;
    system("pause");
}

void Rule()
{
    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; //Greet the user
    cout << "\t\t\tThis game is a multiplayer game."  << endl
         << endl;
             cout << "\t\t\tSpecifically, you should have at least 2 groups of players for the gameplay and \n\t\t\teach group will involve 2 players playing the same deck."  << endl
         << endl;
             cout << "\t\t\tTo win the game, the 2 players of the same group should:" << endl
                 << "\t\t\t1.accumulate the highest scores when the Draw Pile is empty or,\n"
                 << "\t\t\t2. be the first group which empty the Hand Decks\n"
                << "\t\t\t3. be the last group in the game\n"
         << endl;
    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl;     
    system("pause");
}

void UpdateHandDeckPtr(Group temp_group, HandDeckLinkedList<Card> *&current_deck, HandDeckLinkedList<Card> &HandDeckA, HandDeckLinkedList<Card> &HandDeckB, HandDeckLinkedList<Card> &HandDeckC, HandDeckLinkedList<Card> &HandDeckD)
{
    if (temp_group.compareStrings(temp_group.getGroupName(), "A")) {
        current_deck = &HandDeckA;
    }
    else if (temp_group.compareStrings(temp_group.getGroupName(), "B")) {
        current_deck = &HandDeckB;
    }
    else if (temp_group.compareStrings(temp_group.getGroupName(), "C")) {
        current_deck = &HandDeckC;
    }
    else if (temp_group.compareStrings(temp_group.getGroupName(), "D")) {
        current_deck = &HandDeckD;
    }
    else {
        cout << "There is a problem in the retrieve group name\n";
    }
}

void end()
{
    cout << endl;  
    cout << endl;                                                                                                                                                
   cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; //goodbye message
    cout<<"\t8888888 8888888888 8 8888        8          .8.          b.             8 8 8888     ,88'           `8.`8888.      ,8'  ,o888888o.     8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8         .888.         888o.          8 8 8888    ,88'             `8.`8888.    ,8'. 8888     `88.   8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8        :88888.        Y88888o.       8 8 8888   ,88'               `8.`8888.  ,8',8 8888       `8b  8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8       . `88888.       .`Y888888o.    8 8 8888  ,88'                 `8.`8888.,8' 88 8888        `8b 8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8      .8. `88888.      8o. `Y888888o. 8 8 8888 ,88'                   `8.`88888'  88 8888         88 8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8     .8`8. `88888.     8`Y8o. `Y88888o8 8 8888 88'                     `8. 8888   88 8888         88 8 8888      88 \n";
    cout<<"\t      8 8888       8 8888888888888    .8' `8. `88888.    8   `Y8o. `Y8888 8 888888<                       `8 8888   88 8888        ,8P 8 8888      88 \n";
    cout<<"\t      8 8888       8 8888        8   .8'   `8. `88888.   8      `Y8o. `Y8 8 8888 `Y8.                      8 8888   `8 8888       ,8P  ` 8888     ,8P \n";
    cout<<"\t      8 8888       8 8888        8  .888888888. `88888.  8         `Y8o.` 8 8888   `Y8.                    8 8888    ` 8888     ,88'     8888   ,d8P  \n";
    cout<<"\t      8 8888       8 8888        8 .8'       `8. `88888. 8            `Yo 8 8888     `Y8.                  8 8888       `8888888P'        `Y88888P'   \n";   

    cout << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t\t     Thank you for playing!" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t\t      Hope to see you again!" << endl
         << endl;                                                               
     cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; 
}