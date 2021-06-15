#ifndef GROUP_H
#define GROUP_H
#include<iostream>
#include<string>
using namespace std;

class Group
{
private:
	int player_turn, score;
	string player1_name, player2_name, groupname;
public:
	Group() {
		player_turn = 0;
		score = 0;
		player1_name = "";
		player2_name = "";
		groupname = "";
	};
	void setGroup(int player_turn, int score, string player1_name, string player2_name, string group_name) {
		this->player_turn = player_turn;
		this->score = score;
		this->player1_name = player1_name;
		this->player2_name = player2_name;
		this->groupname = groupname;
	}
	void setPlayerturn(int turn) {
		player_turn = turn;
	}
	void setScore(int s){
		score = s;
	}
	void setPlayer1Name(string name) {
		player1_name = name;
	}
	void setPlayer2Name(string name) {
		player2_name = name;
	}
	void setGroupName(string name) {
		groupname = name;
	}
	int getPlayerTurn() const {
		return player_turn;
	}
	int getScore() const {
		return score;
	}
	string getPlayer1Name() const {
		return player1_name;
	}
	string getPlayer2Name() const {
		return player2_name;
	}
	string getGroupName() const {
		return groupname;
	}
	int addScore(int s) {
		score += s;
	}

};

#endif // !GROUP_H
