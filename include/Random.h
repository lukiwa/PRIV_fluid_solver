//
// Created by Lukasz on 17.06.2020.
//

#pragma once

#include <random>

class Random {
    inline static std::mt19937 _random_engine{};
public:

    static void Seed() {
        _random_engine.seed(std::random_device()());
    }

    static double Double(double min, double max) {
        std::uniform_real_distribution<double> distribution(min, max);
        return (distribution(_random_engine));
    }

    static double Int(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        return (distribution(_random_engine));
    }


};




