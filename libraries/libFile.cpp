#include "libFile.h"
#include <fstream>
#include <iostream>
#include <string>

enum class EXCEPTION_CODE {
    openError,readError,writeError
};


std::fstream openFile(const std::string& fileName) {
    std::fstream file;

    file.open(fileName, std::ios::in);

    if (!file.is_open()) {
        throw EXCEPTION_CODE::openError;
    }

    return file;
}

void closeFile(std::fstream& file) {
    if (file.is_open()) {
        file.close();
    }
}

std::fstream createOutputFile(const std::string &fileName) {
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

void saveSubsetToFile(const std::vector<int>& arr, int size, std::fstream outFile) {
    for (int i = 1; i <= size; ++i) {
        outFile << arr[i] << (i == size ? "" : " ");
    }
    outFile << "\n";
}

void saveVectorToFile(const std::vector<int>& arr, std::fstream& outFile) {
    for (int i = 0; i < arr.size(); ++i) {
        outFile << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
}

std::pair<int, int> saddleBackHelper(const std::vector<std::vector<int>>& array, int target, int rows, int cols, bool findFirst, int r, int c, int bestRow, int bestCol) {
    if (findFirst) {
        if (r < 0 || c >= cols) return {bestRow, bestCol};

        if (array[r][c] < target) return saddleBackHelper(array, target, rows, cols, findFirst, r, c + 1, bestRow, bestCol);
        if (array[r][c] > target) return saddleBackHelper(array, target, rows, cols, findFirst, r - 1, c, bestRow, bestCol);
        return saddleBackHelper(array, target, rows, cols, findFirst, r - 1, c, r, c);
    }
    if (r >= rows || c < 0) return {bestRow, bestCol};

    if (array[r][c] < target) return saddleBackHelper(array, target, rows, cols, findFirst, r + 1, c, bestRow, bestCol);
    if (array[r][c] > target) return saddleBackHelper(array, target, rows, cols, findFirst, r, c - 1, bestRow, bestCol);
    return saddleBackHelper(array, target, rows, cols, findFirst, r + 1, c, r, c);
}

std::pair<int, int> saddleBackRec(const std::vector<std::vector<int>>& array, int target, bool findFirst) {
    int rows = array.size();
    int cols = array[0].size();
    if (findFirst) {
        return saddleBackHelper(array, target, rows, cols, findFirst, rows - 1, 0, -1, -1);
    }
    return saddleBackHelper(array, target, rows, cols, findFirst, 0, cols - 1, -1, -1);
}

std::pair<int, int> saddleBackIter(const std::vector<std::vector<int>>& array, int target, bool findFirst) {
    int rows = array.size();
    int cols = array[0].size();
    int bestRow = -1;
    int bestCol = -1;

    if (findFirst) {
        //jeżeli szukamy pierwszej instancji zaczynamy od lewego dolnego rogu macierzy
        int r = rows - 1;
        int c = 0;
        while (r >= 0 && c < cols) {
            if (array[r][c] < target) c++;
            else if (array[r][c] > target) r--;
            else {
                bestRow = r;
                bestCol = c;
                r--;
            }
        }
    } else {
        //w przeciwnym wypadku szukanie zaczynamy od prawego górnego rogu
        int r = 0;
        int c = cols - 1;
        while (r < rows && c >= 0) {
            if (array[r][c] < target) r++;
            else if (array[r][c] > target) c--;
            else {
                bestRow = r;
                bestCol = c;
                r++;
            }
        }
    }
    return {bestRow, bestCol};
}