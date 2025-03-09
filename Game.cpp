#include "Game.h"

Game::Game(Player argPlayer1, Player argPlayer2) {
	player1 = argPlayer1;
	player2 = argPlayer2;
}

void Game::Play() {
	while (player1.GetGameStats().TotalPoints() + player2.GetGameStats().TotalPoints() < POINTS_TO_WIN) {
		player1.RecordPlay(FIELDGOAL_MADE);
		player2.RecordPlay(THREEPOINT_MADE);
	}
}

void Game::ShowResults() {
	if (player1.GetGameStats().TotalPoints() > player2.GetGameStats().TotalPoints()) {
		std::cout << "Player 1 (" << player1.Name() << ") has won!" << std::endl;
	}
	else {
		std::cout << "Player 2 (" << player2.Name() << ") has won!" << std::endl;
	}

	std::cout << "\n" << "Player 1 (" << player1.Name() << ") Stats:" << std::endl;

	player1.GetGameStats().Print();

	std::cout << "\n" << "Player 2 (" << player1.Name() << ") Stats:" << std::endl;

	player2.GetGameStats().Print();
}