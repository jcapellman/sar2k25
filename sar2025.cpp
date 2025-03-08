#include "Main.h"

#include "Game.h"

int main()
{
    std::cout << "Shoot a Rama 2025" << std::endl;

    // TODO: Read in player database

    std::cout << "Choose your player:" << std::endl;

    // TODO: Allow player to select one

    // TODO: Randomly select a computer player

    auto humanPlayer = Player();
    auto aiPlayer = Player();

    auto currentGame = Game(humanPlayer, aiPlayer);

    currentGame.Play();
    
    // TODO: Show results

    // TODO: Save results

    // TODO: Ask to play again
}