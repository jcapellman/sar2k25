#pragma once
#include "Main.h"
#include "Player.h"

class Game {
public:
	Game(Player argPlayer1, Player argPlayer2);

	void Play();
private:
	Player player1;
	Player player2;
};