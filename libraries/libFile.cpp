#include "libFile.h"
#include <fstream>
#include <iostream>
#include <string>

std::fstream openFile(const std::string& fileName) {
    std::fstream file;

    file.open(fileName, std::ios::in);

    if (!file.is_open()) {
        throw std::runtime_error("Critical error: Nie udalo sie otowrzyc pliku -> " + fileName);
    }

    return file;
}

void closeFile(std::fstream& file) {
    if (file.is_open()) {
        file.close();
    }
}