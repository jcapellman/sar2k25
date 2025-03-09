#include "GameStats.h"

GameStats::GameStats() {
	blocks = 0;
	fieldgoal_attempts = 0;
	fieldgoal_made = 0;
	rebounds = 0;
	threepoint_attempts = 0;
	threepoint_made = 0;
}

int GameStats::TotalPoints() const {
	return (fieldgoal_made * 2) + (threepoint_made * 3);
}

void GameStats::Print() const {
	std::cout << "Field Goals Made:" << fieldgoal_made << std::endl;
	std::cout << "Field Goals Attempt:" << fieldgoal_attempts << std::endl;

	if (fieldgoal_attempts > 0) {
		std::cout << "Field Goal %:" << fieldgoal_made / fieldgoal_attempts << std::endl;
	}
	else {
		std::cout << "Field Goal %: N/A" << std::endl;
	}

	std::cout << "Three Point Field Goals Made:" << threepoint_made << std::endl;
	std::cout << "Three Point Field Goals Attempt:" << threepoint_attempts << std::endl;

	if (threepoint_attempts > 0) {
		std::cout << "Three Point Field Goal %:" << threepoint_made / threepoint_attempts << std::endl;
	}
	else {
		std::cout << "Three Point Field Goal %: N/A" << std::endl;
	}
}

void GameStats::RecordPlay(PlayOutcome outcome) {
	switch (outcome) {
		case REBOUND:
			rebounds++;
			break;
		case BLOCKED_SHOT:
			blocks++;
			break;
		case FIELDGOAL_MADE:
			fieldgoal_attempts++;
			fieldgoal_made++;
			break;
		case FIELDGOAL_MISS:
			fieldgoal_attempts++;
			break;
		case THREEPOINT_MADE:
			threepoint_attempts++;
			threepoint_made++;
			break;
		case THREEPOINT_MISS:
			threepoint_attempts++;
			break;
	}
}