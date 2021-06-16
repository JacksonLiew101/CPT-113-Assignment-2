#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

// This is a Card class to store details for each card
class Card
{
private:
	string value, colour;
	int score;

public:
	Card();
	void setCard(string, string, int);
	void setValue(string);
	void setColour(string);
	void setScore(int);
	string getValue() const;
	string getColour() const;
	int getScore() const;
	void displayCard();
	bool compareStrings(string, string);
};

// Constructor for Card class
Card::Card()
{
	value = "";
	colour = "";
	score = 0;
}

/*
	Setters
*/
// Card Class data setter
void Card::setCard(string v, string c, int s)
{
	value = v;
	colour = c;
	score = s;
}

// Value setter
void Card::setValue(string v)
{
	value = v;
}

// Colour setter
void Card::setColour(string c)
{
	colour = c;
}

// Score setter
void Card::setScore(int s)
{
	score = s;
}

/*
	Getters
*/
// Value getter
string Card::getValue() const {
	return value;
}

// Colour getter
string Card::getColour() const {
	return colour;
}

// Score getter
int Card::getScore() const {
	return score;
}

/*
	General methods
*/
// Display card values and colours
void Card::displayCard() {
	cout << "{ " << getValue() << ", " << getColour() << " }";
}

// Returns true if both strings are the same after comparing
bool Card::compareStrings(string s1, string s2)
{
	int compares = s1.compare(s2);
	if (compares == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
};

#endif // !CARD_H
