#include "Game.h"
#include "RandomNumberGenerator.h"

void Game::SimulateComputerPlayerAction() {
	int choice;
	int scoreDifference = player1.GetGameStats().TotalPoints() - player2.GetGameStats().TotalPoints();
	int threePointAttribute = player2.GetAttributes().threepoint;

	if (scoreDifference > 6 && threePointAttribute > 7) {
		// Increase the odds of attempting a three-point field goal
		choice = RandomNumberGenerator::Generate(1, 3) == 3 ? 2 : 1;
	} else {
		choice = RandomNumberGenerator::Generate(1, 2);
	}

	switch (choice) {
	case 1:
		player2.AttemptPlay(OFFENSE_FIELDGOAL, player1);
		break;
	case 2:
		player2.AttemptPlay(OFFENSE_THREE_POINT_FIELDGOAL, player1);
		break;
	}
}

void Game::Play() {
	while (player1.GetGameStats().TotalPoints() < POINTS_TO_WIN && player2.GetGameStats().TotalPoints() < POINTS_TO_WIN) {
		int choice = 0;

		std::cout << "Player 1 (" << player1.GetName() << ") - " << player1.GetGameStats().TotalPoints() << " vs Player 2 (" << player2.GetName() << ") - " << player2.GetGameStats().TotalPoints() << std::endl;

		std::cout << "What play do you want to attempt?" << std::endl;
		std::cout << "1) Field Goal" << std::endl;
		std::cout << "2) Three Point Field Goal" << std::endl;
		std::cout << "Enter your choice (1 or 2): ";

		while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid choice. Please enter 1 or 2: ";
		}

		switch (choice) {
			case 1:
				player1.AttemptPlay(OFFENSE_FIELDGOAL, player2);
				break;
			case 2:
				player1.AttemptPlay(OFFENSE_THREE_POINT_FIELDGOAL, player2);
				break;
		}

		SimulateComputerPlayerAction();
	}
}

void Game::ShowResults() {
	if (player1.GetGameStats().TotalPoints() > player2.GetGameStats().TotalPoints()) {
		std::cout << "Player 1 (" << player1.GetName() << ") has won!" << std::endl;
	}
	else {
		std::cout << "Player 2 (" << player2.GetName() << ") has won!" << std::endl;
	}

	std::cout << "\n" << "Player 1 (" << player1.GetName() << ") Stats:" << std::endl;

	player1.GetGameStats().Print();

	std::cout << "\n" << "Player 2 (" << player2.GetName() << ") Stats:" << std::endl;

	player2.GetGameStats().Print();
}