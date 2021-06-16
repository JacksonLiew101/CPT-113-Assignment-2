// Testing DrawPileStack Class
/*
	Card card1;
	DrawPileStack<Card> drawpile1;
	drawpile1.displayStack();
	system("pause");
	cout << endl;
	drawpile1.popCard(card1);
	card1.displayCard();
	system("pause");

	cout << endl;
	drawpile1.displayStack();
*/

// Testing DiscardPileStack Class
/*
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	Card card5;
	DiscardPileStack<Card> discardpile1;

	
	//test discard pile
	// condition 1: action card after number card
	card1.setCard("1", "Red", 1);
	cout << "This Discard pile is empty: " << discardpile1.isEmpty() << endl;
	discardpile1.push(card1);

	cout << "After 1st push" << endl;
	discardpile1.displayStack();


	card2 = discardpile1.peek();
	card2.displayCard();

	card2.setCard("Skip", "White", 50);
	discardpile1.push(card2);
	discardpile1.displayStack();
	cout << discardpile1.getActionStatement() << endl;

	// condition 2: action card after action card
	card3.setCard("Reverse", "Blue", 50);
	discardpile1.push(card3);
	discardpile1.displayStack();
	cout << discardpile1.getActionStatement() << endl;

	// condition 3: number card after action card
	card4.setCard("4", "Red", 4);
	discardpile1.push(card4);
	discardpile1.displayStack();
	cout << discardpile1.getActionStatement() << endl;

	// condition 4: number card after number card
	card5.setCard("5", "Yellow", 5);
	discardpile1.push(card5);
	discardpile1.displayStack();
	cout << discardpile1.getActionStatement() << endl;
*/

// Testing GroupDoubleCircularLinkedList Class
/*
	GroupDoubleCircularLinkedList<Group, Card> GroupsLinkedList;
	Group temp_group;
	string player1;
	string player2;
	for(int i =0; i<3; i++)
	{
		cout << "Enter the first player's name for team " << i + 1 << " : ";
		cin >> player1;
		cout << "Enter the second player's name for team " << i + 1 << " : ";
		cin >> player2;
		temp_group.setPlayer1Name(player1);
		temp_group.setPlayer2Name(player2);
		if(i==0)
		{
			temp_group.setGroupName("A");
		}
		else if(i==1)
		{
			temp_group.setGroupName("B");
		}
		else if(i==2)
		{
			temp_group.setGroupName("C");
		}
		GroupsLinkedList.addNewGroupAtEnd(temp_group);
	}
	GroupsLinkedList.displayList();
	cout << endl;
	//GroupsLinkedList.RemoveGroup(temp_group);
	GroupsLinkedList.displayList();
	cout << endl;
	GroupsLinkedList.NextGroup();
	temp_group = GroupsLinkedList.getCurrentNode();
	cout << temp_group.getGroupName() << ", " << temp_group.getPlayer1Name() << ", " << temp_group.getPlayer2Name();
	cout << endl;
	GroupsLinkedList.reverse();
	GroupsLinkedList.NextGroup();
	temp_group = GroupsLinkedList.getCurrentNode();
	cout << "After reverse: " << endl;
	cout << temp_group.getGroupName() << ", " << temp_group.getPlayer1Name() << ", " << temp_group.getPlayer2Name();
	cout << endl;
	GroupsLinkedList.skipTurn();
	temp_group = GroupsLinkedList.getCurrentNode();
	cout << "After skipping: " << endl;
	cout << temp_group.getGroupName() << ", " << temp_group.getPlayer1Name() << ", " << temp_group.getPlayer2Name();
	cout << endl;
*/

// Testing HandDeckLinkedList Class
/*
	Card card1;
	Card card2;
	DiscardPileStack<Card> discardpile1;
	DrawPileStack<Card> drawpile1;
	drawpile1.displayStack();
	system("pause");
	cout << endl;
	drawpile1.popCard(card1);
	card1.displayCard();
	system("pause");
	cout << endl;
	drawpile1.displayStack();
	cout << endl;
	HandDeckLinkedList<Card> handDeck1;
	handDeck1.drawCard(card1);
	handDeck1.showHandCards();
	cout << endl;
	drawpile1.popCard(card1);
	handDeck1.drawCard(card1);
	handDeck1.showHandCards();
	cout << endl;
	handDeck1.playCard(card1, card2);
	cout << "After using 1 card:\n";
	handDeck1.showHandCards();
	cout << endl;
	discardpile1.push(card2);
	cout << "In the discard pile: " << endl;
	discardpile1.displayStack();
*/
