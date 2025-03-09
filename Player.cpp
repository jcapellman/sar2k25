#include "Player.h"
#include "RandomNumberGenerator.h"

void Player::AttemptPlay(AvailablePlays play, Player& opponent) {
    auto rollCheck = [](int playerAttribute, int opponentAttribute) -> int {
        int playerRoll = RandomNumberGenerator::Generate(1, 20) + playerAttribute;
        int opponentRoll = RandomNumberGenerator::Generate(1, 20) + opponentAttribute;

        return playerRoll - opponentRoll;
    };

    PlayOutcome outcome;

    switch (play) {
    case OFFENSE_FIELDGOAL: {
        int result = rollCheck(this->GetAttributes().fieldgoal, opponent.GetAttributes().block);

        if (result >= 10) {
            outcome = PlayOutcome::FIELDGOAL_MADE;
        }
        else if (result > 0) {
            outcome = PlayOutcome::FIELDGOAL_MADE;
        }
        else if (result == 0) {
            outcome = PlayOutcome::FIELDGOAL_MISS;
            opponent.RecordPlay(PlayOutcome::REBOUND);
        }
        else {
            outcome = PlayOutcome::FIELDGOAL_MISS;
            opponent.RecordPlay(PlayOutcome::BLOCKED_SHOT);
        }

        break;
    }

    case OFFENSE_THREE_POINT_FIELDGOAL: {
        int result = rollCheck(this->GetAttributes().threepoint, opponent.GetAttributes().block);
        if (result >= 10) {
            outcome = PlayOutcome::THREEPOINT_MADE;
        }
        else if (result > 0) {
            outcome = PlayOutcome::THREEPOINT_MADE;
        }
        else if (result == 0) {
            outcome = PlayOutcome::THREEPOINT_MISS;
            opponent.RecordPlay(PlayOutcome::REBOUND);
        }
        else {
            outcome = PlayOutcome::THREEPOINT_MISS;
            opponent.RecordPlay(PlayOutcome::BLOCKED_SHOT);
        }
        break;
    }

    default:
        std::cerr << "Invalid play selected!" << std::endl;
        return;
    }

    gameStats.RecordPlay(outcome);

    std::cout << name << " attempted a play: " << outcome << std::endl;
}
