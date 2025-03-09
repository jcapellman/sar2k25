#pragma once
#include "Main.h"
#include "Player.h"

class Game {
public:
	Game(Player argPlayer1, Player argPlayer2) : player1(argPlayer1), player2(argPlayer2) {
	}

	void Play();

	void ShowResults();
private:
	Player player1;
	Player player2;
};