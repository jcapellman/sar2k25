#include "Main.h"

#include "Game.h"
#include "RandomNumberGenerator.h"

static void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void LoadPlayersFromFile(const std::string& filename, std::vector<Player>& players) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, team, attr;
        PlayerAttributes attributes = { 0, 0, 0, 0, 0 };

        // Parse the line
        std::getline(iss, name, ',');
        std::getline(iss, team, ',');
        while (std::getline(iss, attr, ',')) {
            std::string key = attr.substr(0, attr.find('='));
            int value = std::stoi(attr.substr(attr.find('=') + 1));
            if (key == "Block") attributes.block = value;
            else if (key == "Steal") attributes.steal = value;
            else if (key == "FieldGoal") attributes.fieldgoal = value;
            else if (key == "ThreePoint") attributes.threepoint = value;
            else if (key == "Clutch") attributes.clutch = value;
        }

        players.emplace_back(name, team, attributes);
    }

    file.close();
}

static void PlayGame() {
    ClearScreen();

    std::vector<Player> players;

    LoadPlayersFromFile("players.txt", players);

    std::cout << "Shoot a Rama 2025" << std::endl;

    std::cout << "Available Players:" << std::endl;
    int index = 1;
    for (const auto& player : players) {
        std::cout << index++ << ". " << player.GetName() << " (" << player.GetTeam() << ")" << std::endl;
    }

    int choice;
    auto isValidPlayerChoice = [&choice, &players]() {
        return choice >= 1 && choice <= static_cast<int>(players.size());
    };

    while (true) {
        std::cout << "Select a player by number: ";
        std::cin >> choice;

        if (isValidPlayerChoice()) {
            break;
        }

        std::cerr << "Invalid choice!" << std::endl;
    }

    const Player& userPlayer = players[choice - 1];
    std::cout << "You selected: " << userPlayer.GetName() << " (" << userPlayer.GetTeam() << ")" << std::endl;

    // Randomly assign a player to the computer    
    int randomIndex;

    do {
        randomIndex = RandomNumberGenerator::Generate(1, static_cast<int>(players.size()));
    } while (randomIndex == choice - 1); // Ensure the computer doesn't choose the same player

    const Player& computerPlayer = players[randomIndex];

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