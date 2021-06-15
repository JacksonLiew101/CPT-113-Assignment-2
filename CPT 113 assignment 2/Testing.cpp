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