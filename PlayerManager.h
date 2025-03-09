#pragma once
#include "Main.h"
#include "Player.h"

class PlayerManager {
public:
	PlayerManager();

	void DisplayList();

	Player SelectRandomOpponent(const Player& humanPlayerSelection);

	Player SelectHumanPlayer();
private:
	void LoadPlayers();

	std::vector<Player> players;
};