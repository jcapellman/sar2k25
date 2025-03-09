#pragma once
class RandomNumberGenerator {
public:
    static int Generate(int start, int end) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(start, end);
        return distrib(gen);
    }
};
