#include "GameStats.h"

GameStats::GameStats() {
	blocks = 0;
	steals = 0;
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
	auto printStat = [](int made, int attempts) {
        if (attempts > 0) {
			return std::round((static_cast<float>(made) / attempts) * 100);
        }
		return 0.0f;
	};

	std::cout << "FGM\tFGA\tFG%\t3PM\t3PA\t3P%\tREB\tSTL\tBLK\tPTS" << std::endl;
	std::cout << fieldgoal_made << "\t" << fieldgoal_attempts << "\t" << printStat(fieldgoal_made, fieldgoal_attempts) << "\t" << threepoint_made << "\t" << threepoint_attempts << "\t" << printStat(threepoint_made, threepoint_attempts) << "\t"
		<< rebounds << "\t" << steals << "\t" << blocks << "\t" << TotalPoints() << std::endl;
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