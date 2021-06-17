#include"Group Double Circular Linked List.h"
#include"HandDeck Linked List.h"
#include"Discard Pile Stack.h"
#include"DrawPile Stack.h"
#include<iostream>
#include<string>
using namespace std;

const int STARTING_CARD_NO = 5;
const int MAXIMUM_CARD_NO = 10;

void Welcome();
void Rule();
void CreateGroups(Group&, GroupDoubleCircularLinkedList<Group>&);
void UpdateHandDeckPtr(Group&, HandDeckLinkedList<Card>*&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&);
void InitializeAllHandDecks(Card&, Group&, GroupDoubleCircularLinkedList<Group>&, DrawPileStack<Card>&, HandDeckLinkedList<Card>*&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&);
void StartFirstCard(Card&, DrawPileStack<Card>&, DiscardPileStack<Card>&);
void CheckActionCard(bool&, Card&, Group&, DrawPileStack<Card>&, DiscardPileStack<Card>&, GroupDoubleCircularLinkedList<Group>&, HandDeckLinkedList<Card>*&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&, HandDeckLinkedList<Card>&);
void GameplayInterfaceHead(Card&, Group&, DiscardPileStack<Card>&, GroupDoubleCircularLinkedList<Group>&);
void CurrentGroupLose(Group&, DiscardPileStack<Card>&, GroupDoubleCircularLinkedList<Group>&);
void ContinueDrawCardTillValid(bool&, Card&, Card&, DrawPileStack<Card>&, HandDeckLinkedList<Card>*&);
void PlayValidCard(Card&, Card&, Group&, DiscardPileStack<Card>&, GroupDoubleCircularLinkedList<Group>&, HandDeckLinkedList<Card>*&);
void CheckWinner(bool&, Group&, DrawPileStack<Card>&, GroupDoubleCircularLinkedList<Group>&, HandDeckLinkedList<Card>*&);
void DisplayWinner(Group& temp_group);
void End();

int main() {
    // Data Structures, Objects and Variables needed
    DrawPileStack<Card> drawpile;
    DiscardPileStack<Card> discardpile;
    GroupDoubleCircularLinkedList<Group> groupsinplay;
    HandDeckLinkedList<Card> HandDeckA, HandDeckB, HandDeckC, HandDeckD;
    HandDeckLinkedList<Card>* current_deck = nullptr;
    Card temp_card, choose_card;
    Group temp_group;
    bool winner_flag = false; 

    Welcome();
    Rule();

    CreateGroups(temp_group, groupsinplay);

    InitializeAllHandDecks(temp_card, temp_group, groupsinplay, drawpile, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);
    
    StartFirstCard(temp_card, drawpile, discardpile);

    // Start game
    while (!winner_flag) {
        
        // Check Action and determine group player's turn
        CheckActionCard(winner_flag, temp_card, temp_group, drawpile, discardpile, groupsinplay, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

        // Save the top cards for later matching card
        discardpile.peek(temp_card);

        GameplayInterfaceHead(temp_card, temp_group, discardpile, groupsinplay);

        // Show all available on hand cards first
        current_deck->showHandCards();
        cout << "\n\n";
        
        if (current_deck->getNumberOfHandCards() > MAXIMUM_CARD_NO) {
            CurrentGroupLose(temp_group, discardpile, groupsinplay);
        }
        else
        {
             // Show all the valid cards, after matching with the top card from discard pile
             current_deck->showValidCard(temp_card);

             // Repeatedly draw card if no valid card to be played
             ContinueDrawCardTillValid(winner_flag, temp_card, choose_card, drawpile, current_deck);

             // If the draw card suddenly reach more than 10 break out of if else statement
             if (current_deck->getNumberOfHandCards() > 10) {
                 break;
             }
             // Prompt to choose cards and play the card to discard pile
             else {
                PlayValidCard(temp_card, choose_card, temp_group, discardpile, groupsinplay, current_deck);
             }
        }

        CheckWinner(winner_flag, temp_group, drawpile, groupsinplay, current_deck);
    }

    DisplayWinner(temp_group);
    End();
  
	return 0;
}

// Greet the user
void Welcome()
{
    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; 
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

// Explain the rules before gameplay
void Rule()
{
    system("cls");
    cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; 
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

// Create number of group nodes based on user inputs
void CreateGroups(Group& temp_group, GroupDoubleCircularLinkedList<Group>& groupsinplay) {
    int Number_of_groups = 0;
    string Group_name, Player1_name, Player2_name;
    string Group_list = "ABCD";

    // Prompt input to get every player's name
    do
    {
        cout << "\n\n\t\t\tEnter the number of groups to play: ";
        cin >> Number_of_groups;
        // Clear input buffer
        while (getchar() != '\n') cin.clear();
        if (Number_of_groups < 2 || Number_of_groups > 4)
        {
            cout << "Invalid value. Please make sure that the number of groups is between 2 to 4\n";
        }
    } while (Number_of_groups < 2 || Number_of_groups > 4);

    // Create groups according to the number of groups
    for (int i = 0; i < Number_of_groups; i++) {
        cout << "\nEnter player 1's name for this group " << Group_list[i] << ": ";
        getline(cin, Player1_name);
        cout << "\nEnter player 2's name for this group " << Group_list[i] << ": ";
        getline(cin, Player2_name);
        Group_name = Group_list[i];
        temp_group.setGroup(0, Player1_name, Player2_name, Group_name);
        groupsinplay.addNewGroupAtEnd(temp_group);
    }
}

// Update the pointer to point to current handdeck
void UpdateHandDeckPtr(Group& temp_group, HandDeckLinkedList<Card>*& current_deck, HandDeckLinkedList<Card>& HandDeckA, HandDeckLinkedList<Card>& HandDeckB, HandDeckLinkedList<Card>& HandDeckC, HandDeckLinkedList<Card>& HandDeckD)
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

// Initialise the handdeck by giving every handdeck a total of 5 cards
void InitializeAllHandDecks(Card& temp_card, Group& temp_group, GroupDoubleCircularLinkedList<Group>& groupsinplay, DrawPileStack<Card>& drawpile, HandDeckLinkedList<Card>*& current_deck, HandDeckLinkedList<Card>& HandDeckA, HandDeckLinkedList<Card>& HandDeckB, HandDeckLinkedList<Card>& HandDeckC, HandDeckLinkedList<Card>& HandDeckD) {
    
    // Give cards to each group one at a time
    for (int i = 0; i < STARTING_CARD_NO; i++) {

        for (int j = 0; j < groupsinplay.getNoOfGroup(); j++) {
            // Change group before starting, first card start at first group
            groupsinplay.NextGroup();

            // Change deck based on current group
            groupsinplay.getCurrentNode(temp_group);
            UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

            // Add one card to handdeck from drawpile
            drawpile.popCard(temp_card);
            current_deck->drawCard(temp_card);
        }
    }
}

// Pop out 1 card from drawpile as starting card
// Change the starting card if the first popped out card is action card
void StartFirstCard(Card& temp_card, DrawPileStack<Card>& drawpile, DiscardPileStack<Card>& discardpile) {
    drawpile.popCard(temp_card);

    // If first card is action card, overwrite the card to be a number card
    if (temp_card.compareStrings(temp_card.getValue(), "Draw Two") 
        || temp_card.compareStrings(temp_card.getValue(), "Skip") 
        || temp_card.compareStrings(temp_card.getValue(), "Reverse"))
    {
        temp_card.setValue("1");
    }
    else if (temp_card.compareStrings(temp_card.getValue(), "Wild Draw Four") 
        || temp_card.compareStrings(temp_card.getValue(), "Wild"))
    {
        temp_card.setValue("1");
        temp_card.setColour("Red");
    }

    discardpile.push(temp_card);
}

// Check action and do the action first before playing cards
void CheckActionCard(bool& winner_flag, Card& temp_card, Group& temp_group, DrawPileStack<Card>& drawpile, DiscardPileStack<Card>& discardpile, GroupDoubleCircularLinkedList<Group>& groupsinplay, HandDeckLinkedList<Card>*& current_deck, HandDeckLinkedList<Card>& HandDeckA, HandDeckLinkedList<Card>& HandDeckB, HandDeckLinkedList<Card>& HandDeckC, HandDeckLinkedList<Card>& HandDeckD)
{
    string Action;

    Action = discardpile.getActionStatement();

    if (Action == "Reverse")
    {
        // Change direction of the gameplay 
        groupsinplay.reverse();
        groupsinplay.getCurrentNode(temp_group);
        UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

    }
    else if (Action == "Skip") {
        // Skip the next player in turn
        groupsinplay.skipTurn();
        groupsinplay.getCurrentNode(temp_group);
        UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);
    }
    else {
        // For cards that don't involve changing player turns by force
        groupsinplay.NextGroup();
        groupsinplay.getCurrentNode(temp_group);
        UpdateHandDeckPtr(temp_group, current_deck, HandDeckA, HandDeckB, HandDeckC, HandDeckD);

        if (Action == "Draw Two") {
            for (int i = 0; i < 2; i++) {
                drawpile.popCard(temp_card);
                // Immediately stop drawing drawing card if drawpile is empty
                if (drawpile.isEmpty()) {
                    winner_flag = true;
                    break;
                }
                current_deck->drawCard(temp_card);
            }
        }

        if (Action == "Wild Draw Four") {
            for (int i = 0; i < 4; i++) {
                drawpile.popCard(temp_card);
                // Immediately stop drawing drawing card if drawpile is empty
                if (drawpile.isEmpty()) {
                    winner_flag = true;
                    break;
                }
                current_deck->drawCard(temp_card);
            }
        }
    }
}

// Display gameplay interface head part (upper part), including current card, action(if exists), current group player
void GameplayInterfaceHead(Card& temp_card, Group& temp_group, DiscardPileStack<Card>& discardpile, GroupDoubleCircularLinkedList<Group>& groupsinplay)
{
    string Action;

    // Display message for current number card
    system("cls");
    cout << "\t*****************************************************************************************************************************************************" << endl
        << endl;
    cout << "\t\t\t" << "Current Number Card" << endl;
    cout << "\t\t\t";
    temp_card.displayCard();

    // Display message for action cards (if exist)
    Action = discardpile.getActionStatement();
    if (Action == "Draw Two") {
        cout << "\n\n'Draw Two' card is used. 2 cards is drawed to your hand deck\n\n";
    }
    else if (Action == "Wild Draw Four") {
        cout << "\n\n'Wild Draw Four' card is used. 4 cards is drawed to your hand deck.\n"
            << temp_card.getColour() << " is the new colour.\n\n";
    }
    else if (Action == "Wild") {
        cout << "\n\n'Wild' card is used.\n"
            << temp_card.getColour() << " is the new colour.\n\n";
    }
    else if (Action == "Skip") {
        cout << "\n\n'Skip' card is used. It is your turn now.\n\n";
    }
    else if (Action == "Reverse") {
        cout << "\n\n'Reverse' card is used. Direction is changed. It is your turn now.\n\n";
    }
    else {
        cout << "\n\n";
    }

    // Display message for current group player
    cout << "\t\t\tYour turn now!\n";
    cout << "\nCurrent Player: ";
    if (groupsinplay.getPlayerTurn() == 0) {
        cout << temp_group.getPlayer1Name();
    }
    else {
        cout << temp_group.getPlayer2Name();
    }
    cout << " from Group " << temp_group.getGroupName() << endl;
}

// Remove current group which lose and point to the next remaining group
void CurrentGroupLose(Group& temp_group, DiscardPileStack<Card>& discardpile, GroupDoubleCircularLinkedList<Group>& groupsinplay)
{
    // Remove the group
    groupsinplay.RemoveGroup();

    // Reset the action, to avoid carry forward to next player
    discardpile.setActionStatement("");

    // Update the temp group to the next remaining group
    groupsinplay.getCurrentNode(temp_group);
}

// Continue to draw card until handdeck has valid cards to be playerd
void ContinueDrawCardTillValid(bool& winner_flag, Card& temp_card, Card& choose_card, DrawPileStack<Card>& drawpile, HandDeckLinkedList<Card>*& current_deck)
{
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
            current_deck->showHandCards();
            current_deck->showValidCard(temp_card);
        }
        if (current_deck->getNumberOfHandCards() > 10) {
            break;
        }
    }
}

// Prompt user to pick a card and play the card
void PlayValidCard(Card& temp_card, Card& choose_card, Group& temp_group, DiscardPileStack<Card>& discardpile, GroupDoubleCircularLinkedList<Group>& groupsinplay, HandDeckLinkedList<Card>*& current_deck)
{
    int Player_choice_card_index = 0;

    // Prompt the valid card index
    do
    {
        cout << "\nPlease play a card(choose the valid card index): ";
        cin >> Player_choice_card_index;
        if (current_deck->searchIndex(Player_choice_card_index) == false)
        {
            cout << "Invalid input. Please choose a valid card index\n";
        }
    } while (current_deck->searchIndex(Player_choice_card_index) == false);

    // Play the card to discard pile

    // After getting the valid card index, use that card index to copy the card details to choose card
    current_deck->copyValidChosenCard(Player_choice_card_index, choose_card);

    // Play that card and save that card into temp_card
    current_deck->playCard(choose_card, temp_card);

    // Add score to the group
    temp_group.addScore(temp_card.getScore());
    groupsinplay.updateGroupScore(temp_group);

    // After played that card, clear the index linked list to prepare for next round
    current_deck->clearIndexList();

    // Send that card to discard pile
    discardpile.push(temp_card);

    cout << endl;
    system("pause");
}

// Check the winning condition and save the winner group
void CheckWinner(bool& winner_flag, Group& temp_group, DrawPileStack<Card>& drawpile, GroupDoubleCircularLinkedList<Group>& groupsinplay, HandDeckLinkedList<Card>*& current_deck)
{
    if (drawpile.isEmpty()) {
        winner_flag = true;
        groupsinplay.findHighestScoreGroup(temp_group);
        system("cls");
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        cout << "\t\t\t\t\tDraw Pile is already empty. Winner is now determined.\n\n";
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        system("pause");
    }
    else if (current_deck->isEmpty()) {
        winner_flag = true;
        system("cls");
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        cout << "\t\t\t\t\t\t8 8888      88           b.             8               ,o888888o.     \n";
        cout << "\t\t\t\t\t\t8 8888      88           888o.          8            . 8888     `88.   \n";
        cout << "\t\t\t\t\t\t8 8888      88           Y88888o.       8           ,8 8888       `8b  \n";
        cout << "\t\t\t\t\t\t8 8888      88           .`Y888888o.    8           88 8888        `8b \n";
        cout << "\t\t\t\t\t\t8 8888      88           8o. `Y888888o. 8           88 8888         88 \n";
        cout << "\t\t\t\t\t\t8 8888      88           8`Y8o. `Y88888o8           88 8888         88 \n";
        cout << "\t\t\t\t\t\t8 8888      88           8   `Y8o. `Y8888           88 8888        ,8P \n";
        cout << "\t\t\t\t\t\t  8888     ,8P           8      `Y8o. `Y8           `8 8888       ,8P   \n";
        cout << "\t\t\t\t\t\t  8888   ,d8P            8         `Y8o.`            ` 8888     ,88'    \n";
        cout << "\t\t\t\t\t\t   `Y88888P'             8            `Yo               `8888888P'     \n";
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        system("pause");
    }
    else if (groupsinplay.getNoOfGroup() == 1) {
        winner_flag = true;
        system("cls");
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        cout << "\t\t\t\t\tOnly one group left in the gameplay. Winner is now determined.\n\n";
        cout << "\t*****************************************************************************************************************************************************" << endl
            << endl;
        system("pause");
    }
}

// Display all the details of the winner group
void DisplayWinner(Group& temp_group)
{
    system("cls");
    cout << "\t*****************************************************************************************************************************************************" << endl
        << endl;
    cout << "\t\t\t\tCongratulations\n";
    cout << "\t\t\t" << temp_group.getPlayer1Name() << " and " << temp_group.getPlayer2Name() << " from\n";
    cout << "\t\t\tGroup " << temp_group.getGroupName() << " wins the game!!!!\n";
    cout << "\t\t\tWith a score of " << temp_group.getScore() << endl;
    cout << "\t*****************************************************************************************************************************************************" << endl
        << endl;
    system("pause");
}

// Goodbye message
void End()
{
    system("cls");
    cout << endl;  
    cout << endl;                                                                                                                                                
   cout << "\t*****************************************************************************************************************************************************" << endl
         << endl; 
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