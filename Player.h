#pragma once
#include "Main.h"

#include "GameStats.h"

enum AvailablePlays {
	OFFENSE_FIELDGOAL,
	OFFENSE_THREE_POINT_FIELDGOAL,
	DEFENSE_STEAL,
	DEFENSE_BLOCK
};

class Player {
public:
	Player(std::string argName, int argBlock, int argSteal, int argFieldGoal, int argThreePoint, int argClutch)
		: name(argName), block(argBlock), steal(argSteal), fieldgoal(argFieldGoal), threepoint(argThreePoint), clutch(argClutch), gameStats() {
	}

	void AttemptPlay(AvailablePlays play, Player opponent);

	const std::string& Name() const {
		return name;
	}

	const int& Block() const {
		return block;
	}

	const int& Steal() const {
		return steal;
	}

	const int& FieldGoal() const {
		return fieldgoal;
	}

	const int& ThreePoint() const {
		return threepoint;
	}

	const int& Clutch() const {
		return clutch;
	}

	const GameStats& GetGameStats() const {
		return gameStats;
	}
private:
	std::string name;

	int block;

	int steal;

	int fieldgoal;

	int threepoint;

	int clutch;

	GameStats gameStats;

	int generateRandomRange(int start, int end) {
		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<> distrib(start, end);

		return distrib(gen);
	}
};