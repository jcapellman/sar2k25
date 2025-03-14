#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <compare>

#include <cstdlib>

constexpr auto POINTS_TO_WIN = 21;

constexpr auto DEFAULT_FIELD_GOAL_THRESHOLD = 1;
constexpr auto DEFAULT_THREE_POINT_FIELD_GOAL_THRESHOLD = 10;
constexpr auto DEFAULT_CONTESTED_RIM = 0;

constexpr auto PLAYER_DATABASE = "players.txt";

inline void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}