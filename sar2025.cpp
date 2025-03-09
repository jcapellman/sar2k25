#include "Main.h"

#include "Game.h"
#include "RandomNumberGenerator.h"
#include "PlayerManager.h"

static void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void PlayGame() {
    ClearScreen();

    auto playerManager = PlayerManager();

    std::cout << "Shoot a Rama 2025" << std::endl;

    std::cout << "Available Players:" << std::endl;
    playerManager.DisplayList();

    const Player& userPlayer = playerManager.SelectHumanPlayer();

    std::cout << "You selected: " << userPlayer.GetName() << " (" << userPlayer.GetTeam() << ")" << std::endl;

    auto computerPlayer = playerManager.SelectRandomOpponent(userPlayer);

    std::cout << "Computer selected: " << computerPlayer.GetName() << " (" << computerPlayer.GetTeam() << ")" << std::endl;

    auto currentGame = Game(userPlayer, computerPlayer);

    currentGame.Play();

    currentGame.ShowResults();
}

int main()
{
    PlayGame();
   
    do {
        char choice = 0;

        std::cout << "Do you want to play again? (y/n)" << std::endl;
        
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            PlayGame();
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            std::cout << "invalid option - y or n" << std::endl;
        }
    } while (true);
}