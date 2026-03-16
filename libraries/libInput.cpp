#include "libInput.h"
#include <iostream>
#include <limits>

int inputInteger() {
    bool check = false;
    int input;

    while (!check) {
        std::cin >> input;
        if (!std::cin.fail()) {
            check = true;
        } else {
            std::cout << "Nie podano liczby" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return input;
}

std::string& inputString() {
    bool check = false;
    std::string input;

    while (!check) {
        std::cin >> input;
        if (!std::cin.fail()) {
            check = true;
        } else {
            std::cout << "Nie podano ciągu znaków" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
};

int inputPositiveInteger() {
    bool check = false;
    int input;

    while (!check) {
        input = inputInteger();
        if (input >= 0) {
            check = true;
        } else {
            std::cout << "Podano liczbe ujemna lub 0" << std::endl;
        }
    }
    return input;
}

int inputWithinRange(int min, int max) {
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    int input = 0;
    input = inputInteger();
    while(input < min || input > max) {
        input = inputInteger();
        std::cout << "Input not within range " << min << " - " << max << std::endl;
    }
    return input;
}