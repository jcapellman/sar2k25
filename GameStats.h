#pragma once
#include "Main.h"

enum PlayType {
	REBOUND,
	ASSIST,
	FIELDGOAL_MADE,
	FIELDGOAL_MISS,
	THREEPOINT_MADE,
	THREEPOINT_MISS
};

class GameStats {
public:
	GameStats();

	void RecordPlay(PlayType playType);

	void Print() const;

	int TotalPoints() const;
private:
	int rebounds;
	int blocks;
	int assists;
	int fieldgoal_attempts;
	int fieldgoal_made;
	int threepoint_attempts;
	int threepoint_made;
};