#pragma once
#include "Main.h"

#include <string>
#include <unordered_map>

enum PlayOutcome {
	REBOUND,
	BLOCKED_SHOT,
	FIELDGOAL_MADE,
	FIELDGOAL_MISS,
	THREEPOINT_MADE,
	THREEPOINT_MISS
};

inline const std::unordered_map<PlayOutcome, std::string> PlayOutcomeStrings {
	{REBOUND, "REBOUND"},
	{BLOCKED_SHOT, "BLOCKED_SHOT"},
	{FIELDGOAL_MADE, "FIELDGOAL_MADE"},
	{FIELDGOAL_MISS, "FIELDGOAL_MISS"},
	{THREEPOINT_MADE, "THREEPOINT_MADE"},
	{THREEPOINT_MISS, "THREEPOINT_MISS"}
};

inline std::string ToString(PlayOutcome outcome) {
	return PlayOutcomeStrings.at(outcome);
}

class GameStats {
public:
	GameStats();

	void RecordPlay(PlayOutcome playType);

	void Print() const;

	int TotalPoints() const;
private:
	int rebounds;
	int blocks;
	int steals;
	int fieldgoal_attempts;
	int fieldgoal_made;
	int threepoint_attempts;
	int threepoint_made;
};