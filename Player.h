#pragma once
#include "Main.h"

#include "GameStats.h"

enum AvailablePlays {
	OFFENSE_FIELDGOAL,
	OFFENSE_THREE_POINT_FIELDGOAL,
	DEFENSE_STEAL,
	DEFENSE_BLOCK
};

struct PlayerAttributes {
	int block;      // Defensive ability
	int steal;      // Stealing ability
	int fieldgoal;  // Accuracy for field goals
	int threepoint; // Accuracy for three-pointers
	int clutch;     // Performance under pressure
};

class Player {
public:
	Player(std::string argName, const PlayerAttributes& attr)
		: name(argName), attributes(attr), gameStats() {
	}

	void AttemptPlay(AvailablePlays play, Player& opponent);

	const std::string& Name() const {
		return name;
	}

	const PlayerAttributes& GetAttributes() const {
		return attributes;
	}

	const GameStats& GetGameStats() const {
		return gameStats;
	}

	void RecordPlay(PlayOutcome outcome) {
		gameStats.RecordPlay(outcome);
	}
private:
	std::string name;

	PlayerAttributes attributes;

	GameStats gameStats;
};