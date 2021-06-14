#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>
using namespace std;
//testing comments

class Card
{
private:
	string name;
	string colour;
	int score;
public:
	//constructor
	Card()
	{
		name = "";
		colour = "";
		score = 0;
	}
	void setCard(string n, string c, int s)
	{
		name = n;
		colour = c;
		score = s;
	}
	string getName() const {
		return name;
	}
	string getColour() const {
		return colour;
	}
	int getScore() const {
		return score;
	}

};
#endif // !CARD_H
