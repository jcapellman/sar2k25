#include "PlayerManager.h"
#include "RandomNumberGenerator.h"

PlayerManager::PlayerManager() {
	LoadPlayers();
}

void PlayerManager::LoadPlayers() {
    std::ifstream file(PLAYER_DATABASE);

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

void PlayerManager::DisplayList() {
    int index = 1;

    for (const auto& player : players) {
        std::cout << index++ << ". " << player.GetName() << " (" << player.GetTeam() << ")" << std::endl;
    }
}

Player PlayerManager::SelectRandomOpponent(const Player& humanPlayerSelection) {
    int randomIndex;

    while (true) {
        randomIndex = RandomNumberGenerator::Generate(1, static_cast<int>(players.size()));

        const Player& computerPlayer = players[randomIndex];

        if (computerPlayer.GetName() != humanPlayerSelection.GetName()) {
            break;
        }
    };

    return players[randomIndex];
}

Player PlayerManager::SelectHumanPlayer() {
    int choice;
    
    while (true) {
        std::cout << "Select a player by number: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= static_cast<int>(players.size())) {
            break;
        }

        std::cerr << "Invalid choice!" << std::endl;
    }

    return players[static_cast<std::vector<Player, std::allocator<Player>>::size_type>(choice) - 1];
}