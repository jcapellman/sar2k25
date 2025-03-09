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
	Player(const std::string& name, const std::string& team, const PlayerAttributes& attributes)
		: name(name), team(team), attributes(attributes) {
	}

	void AttemptPlay(AvailablePlays play, Player& opponent);

	const std::string& GetName() const { return name; }

	const std::string& GetTeam() const { return team; }

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
	std::string team;

	PlayerAttributes attributes;

	GameStats gameStats;
};