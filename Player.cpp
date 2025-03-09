#include "Player.h"

void Player::AttemptPlay(AvailablePlays play, Player opponent) {
	auto calculateOutcome = [this](int baseValue, int opponentValue, int successThreshold, PlayType madeType, PlayType missType) -> PlayType {
		int bonus = baseValue - opponentValue;
		int result = generateRandomRange(0 + bonus, 10);

		return (result > successThreshold) ? madeType : missType;
	};

	PlayType playType = FIELDGOAL_MADE;

	switch (play) {
		case OFFENSE_FIELDGOAL:
			playType = calculateOutcome(fieldgoal, opponent.Steal(), DEFAULT_FIELD_GOAL_THRESHOLD, FIELDGOAL_MADE, FIELDGOAL_MISS);
			break;
		case OFFENSE_THREE_POINT_FIELDGOAL:
			playType = calculateOutcome(threepoint, opponent.Block(), DEFAULT_THREE_POINT_FIELD_GOAL_THRESHOLD, THREEPOINT_MADE, THREEPOINT_MISS);
			break;
	}

	gameStats.RecordPlay(playType);

	std::cout << name << playType << std::endl;
}