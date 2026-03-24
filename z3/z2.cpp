#include <iostream>
#include <vector>
#include <string>
#include "../libraries/libFile.h"
#include "../libraries/libArray.h"
#include "../libraries/libInput.h"

using namespace std;

//n -> totalElements
//k -> subsetSize
//A -> currentSubset
//p -> activePosition

// glowna funkcja generujaca podzbiory k-elementowe
void divideLex(int totalElements, int subsetSize, const std::string& filename) {
    std::fstream outFile = createOutputFile(filename);

    std::vector<int> currentSubset(subsetSize + 1, 0);

    // inicjalizacja pierwszego podzbioru
    for (int i = 1; i <= subsetSize; ++i) {
        currentSubset[i] = i;
    }

    int activePosition = subsetSize;

    while (activePosition >= 1) {
        saveSubsetToFile(currentSubset, subsetSize, outFile);

        // szukamy elementu, ktory mozemy zwiekszyc
        if (currentSubset[subsetSize] == totalElements) {
            activePosition = activePosition - 1;
        } else {
            activePosition = subsetSize;
        }

        // jesli activePosition >= 1, nadpisujemy ogon podzbioru
        if (activePosition >= 1) {
            for (int i = subsetSize; i >= activePosition; --i) {
                currentSubset[i] = currentSubset[activePosition] + i - activePosition + 1;
            }
        }
    }

    outFile.close();
}

int main() {
    int totalElements = inputPositiveInteger();

    int subsetSize = inputPositiveInteger();

    if (subsetSize >= totalElements) {
        cout << "Dane zostaly niepoprawnie wprowadzone";
        return 1;
    }

    divideLex(totalElements, subsetSize, "output_program02.txt");

    return 0;
}