#include <iostream>
#include <string>
#include <random>




   static std::string genRand(int length) {
        std::string randomStr;
        static const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, charset.size() - 1);

        for (int i = 0; i < length; ++i) {
            randomStr += charset[distribution(generator)];
        }

        return randomStr;
    }

