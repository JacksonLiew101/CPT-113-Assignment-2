#ifndef GROUP_H
#define GROUP_H
#include<iostream>
#include<string>
using namespace std;

// This is a Group class to store details for each group
class Group
{
private:
	int score;
	string player1_name, player2_name, groupname;
	
public:
	Group();
	void setGroup(int, string, string, string);
	void setScore(int);
	void setPlayer1Name(string);
	void setPlayer2Name(string);
	void setGroupName(string);
	int getScore() const;
	string getPlayer1Name() const;
	string getPlayer2Name() const;
	string getGroupName() const;
	void addScore(int);
	bool compareStrings(string, string);
};

// Constructor for Group Class
Group::Group() {
	score = 0;
	player1_name = "";
	player2_name = "";
	groupname = "";
};

/*
	Setters
*/
// Group Class Data Setter
void Group::setGroup(int score, string player1_name, string player2_name, string group_name) {
	this->score = score;
	this->player1_name = player1_name;
	this->player2_name = player2_name;
	this->groupname = group_name;
}

// Group score Setter
void Group::setScore(int s) {
	score = s;
}

// Player 1 name setter
void Group::setPlayer1Name(string name) {
	player1_name = name;
}

// Player 2 name setter
void Group::setPlayer2Name(string name) {
	player2_name = name;
}

// Group Name setter
void Group::setGroupName(string name) {
	groupname = name;
}

/*
	Getters
*/
// Score getter
int Group::getScore() const {
	return score;
}

// Player 1 Name getter
string Group::getPlayer1Name() const {
	return player1_name;
}

// Player 2 Name getter
string Group::getPlayer2Name() const {
	return player2_name;
}

// Group Name getter
string Group::getGroupName() const {
	return groupname;
}

// Add the scores to the total score of the group
void Group::addScore(int s) {
	score += s;
}

// Returns true if both strings are the same after comparing
bool Group::compareStrings(string s1, string s2)
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

#endif // !GROUP_H
