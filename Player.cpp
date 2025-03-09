#include "Player.h"

void Player::AttemptPlay(AvailablePlays play, Player opponent) {
	int bonus = 0;
	int result = 0;
	PlayType playType = FIELDGOAL_MADE;

	switch (play) {
		case OFFENSE_FIELDGOAL:
			bonus = fieldgoal - opponent.Steal();

			result = generateRandomRange(0 + bonus, 10);

			if (result > 6) {
				playType = FIELDGOAL_MADE;	
			}
			else {
				playType = FIELDGOAL_MISS;
			}

			break;
		case OFFENSE_THREE_POINT_FIELDGOAL:
			bonus = threepoint - opponent.Block();

			result = generateRandomRange(0 + bonus, 10);

			if (result > 3) {
				playType = THREEPOINT_MADE;
			}
			else {
				playType = THREEPOINT_MISS;
			}

			break;
	}

	gameStats.RecordPlay(playType);

	std::cout << name << playType << std::endl;
}