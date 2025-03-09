#include "Main.h"

#include "Game.h"

static void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void PlayGame() {
    ClearScreen();

    std::cout << "Shoot a Rama 2025" << std::endl;

    std::cout << "Choose your player:" << std::endl;

    // TODO: Allow player to select one

    // TODO: Randomly select a computer player

    PlayerAttributes bronnyAttributes = { 10, 9, 8, 7, 10 };
    Player aiPlayer("LeBronny Jeans", bronnyAttributes);

    PlayerAttributes ramenAttributes = { 6, 5, 10, 10, 8 };
    Player humanPlayer("Steve Ramen", ramenAttributes);


    auto currentGame = Game(humanPlayer, aiPlayer);

    currentGame.Play();

    currentGame.ShowResults();
}

int main()
{
    // TODO: Read in player database

    PlayGame();
   
    // TODO: Save results

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