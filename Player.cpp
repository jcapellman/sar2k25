#include "Player.h"

Player::Player() {
	gameStats = GameStats();
}

void Player::RecordPlay(PlayType playType) {
	gameStats.RecordPlay(playType);
}