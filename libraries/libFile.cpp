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

std::fstream createOutputFile(const std::string& fileName) {
    std::fstream file;

    // budowanie sciezki do folderu outputs
    std::string path = "../outputs/" + fileName;

    // zabezpieczenie: dodanie .txt jesli brakuje
    if (path.find(".txt") == std::string::npos) {
        path += ".txt";
    }

    // otwieranie w trybie zapisu (std::ios::out)
    file.open(path, std::ios::out);

    if (!file.is_open()) {
        throw std::runtime_error("critical error: nie udalo sie utworzyc pliku wyjsciowego -> " + path);
    }

    return file;
}