#pragma once
#include "Main.h"

#include "GameStats.h"

class Player {
public:
	Player();

	void RecordPlay(PlayType playType);

	const std::string& Name() const {
		return name;
	}

	const GameStats& GetGameStats() const {
		return gameStats;
	}
private:
	std::string name;

	GameStats gameStats;
};