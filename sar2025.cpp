#include "Main.h"

#include "Game.h"
#include "RandomNumberGenerator.h"
#include "PlayerManager.h"

static void PlayGame() {
    ClearScreen();

    PlayerManager playerManager;

    std::cout << "Shoot a Rama 2025" << std::endl;

    std::cout << "Available Players:" << std::endl;
    playerManager.DisplayList();

    const Player& userPlayer = playerManager.SelectHumanPlayer();

    std::cout << "You selected: " << userPlayer.GetName() << " (" << userPlayer.GetTeam() << ")" << std::endl;

    const Player& computerPlayer = playerManager.SelectRandomOpponent(userPlayer);

    std::cout << "Computer selected: " << computerPlayer.GetName() << " (" << computerPlayer.GetTeam() << ")" << std::endl;

    Game currentGame(userPlayer, computerPlayer);

    currentGame.Play();

    ClearScreen();

    currentGame.ShowResults();
}

int main()
{
    do {
        PlayGame();

        char choice = 0;

        std::cout << "\n\nDo you want to play again? (y/n)" << std::endl;
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        } else if (choice != 'y' && choice != 'Y') {
            std::cout << "invalid option - y or n" << std::endl;
        }
    } while (true);

    return 0;
}