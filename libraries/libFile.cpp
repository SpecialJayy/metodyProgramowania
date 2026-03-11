#include "libFile/libFile.h"
#include <fstream>
#include <iostream>
#include <string>

std::fstream openFile(const std::string& fileName) {
    std::fstream file;
    file.open(fileName, std::ios::in | std::ios::out);

    if (!file) {
        std::cerr << "Error while opening the file: " << fileName << std::endl;
    }

    return file;
}

void closeFile(std::fstream& file) {
    if (file.is_open()) {
        file.close();
    }
}