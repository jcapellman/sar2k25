#include "Game.h"

void Game::Play() {
	while (player1.GetGameStats().TotalPoints() < POINTS_TO_WIN && player2.GetGameStats().TotalPoints() < POINTS_TO_WIN) {
		int choice = 0;

		std::cout << "Player 1 (" << player1.Name() << ") - " << player1.GetGameStats().TotalPoints() << " vs Player 2 (" << player2.Name() << ") - " << player2.GetGameStats().TotalPoints() << std::endl;

		std::cout << "What play do you want to attempt?" << std::endl;
		std::cout << "1)Field Goal" << std::endl;
		std::cout << "2)Three Point Field Goal" << std::endl;

		std::cin >> choice;

		switch (choice) {
			case 1:
				player1.AttemptPlay(OFFENSE_FIELDGOAL, player2);
				break;
			case 2:
				player1.AttemptPlay(OFFENSE_THREE_POINT_FIELDGOAL, player2);
				break;
		}

		player2.AttemptPlay(OFFENSE_FIELDGOAL, player1);
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

	std::cout << "\n" << "Player 2 (" << player2.Name() << ") Stats:" << std::endl;

	player2.GetGameStats().Print();
}