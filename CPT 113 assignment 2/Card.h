#pragma once
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;


class Card
{
private:
	string value;
	string colour;
	int score;
public:
	//constructor
	Card()
	{
		value = "";
		colour = "";
		score = 0;
	}
	void setCard(string v, string c, int s)
	{
		value = v;
		colour = c;
		score = s;
	}
	void setValue(string v)
	{
		value = v;
	}
	void setColour(string c)
	{
		colour = c;
	}
	void setScore(int s)
	{
		score = s;
	}
	string getValue() const {
		return value;
	}
	string getColour() const {
		return colour;
	}
	int getScore() const {
		return score;
	}
	bool compareStrings(string s1, string s2)
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
	void displayCard() {
		//cout << "{ " << getValue() << ", " << getColour() << ", " << getScore() << " }" << endl;
		cout << "{ " << getValue() << ", " << getColour() << " }" << endl;
	}
	
};
#endif // !CARD_H
