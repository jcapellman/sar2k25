#include "GameStats.h"

GameStats::GameStats() {
	assists = 0;
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
}

void GameStats::RecordPlay(PlayType playType) {
	switch (playType) {
		case ASSIST:
			assists++;
			break;
		case REBOUND:
			rebounds++;
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