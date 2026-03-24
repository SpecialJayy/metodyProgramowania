#include <iostream>
#include <vector>
#include <string>
#include "../libraries/libFile.h"
#include "../libraries/libInput.h"

using namespace std;

// S -> partValues
// R -> partCounts
// d -> uniquePartsCount
void savePartToFile(const std::vector<int>& partValues, const std::vector<int>& partCounts, int uniquePartsCount, std::fstream& outFile) {
    bool isFirst = true;
    for (int i = 1; i <= uniquePartsCount; ++i) {
        // wypisujemy dany skladnik partValues[i] dokladnie partCounts[i] razy
        for (int j = 0; j < partCounts[i]; ++j) {
            if (!isFirst) {
                outFile << " ";
            }
            outFile << partValues[i];
            isFirst = false;
        }
    }
    outFile << "\n";
}

// glowna funkcja generujaca podzialy liczby
void generatePartitions(int targetNumber, const std::string& filename) {
    std::fstream outFile = createOutputFile(filename);

    std::vector<int> partValues(targetNumber + 1, 0);
    std::vector<int> partCounts(targetNumber + 1, 0);
    int uniquePartsCount = 1;

    partValues[1] = targetNumber;
    partCounts[1] = 1;

    savePartToFile(partValues, partCounts, uniquePartsCount, outFile);

    while (partValues[1] > 1) {
        int removedSum = 0;

        // jesli na koncu mamy jedynki to je zdejmujemy i dodajemy do puli
        if (partValues[uniquePartsCount] == 1) {
            removedSum = removedSum + partCounts[uniquePartsCount];
            uniquePartsCount = uniquePartsCount - 1;
        }

        removedSum = removedSum + partValues[uniquePartsCount];
        partCounts[uniquePartsCount] = partCounts[uniquePartsCount] - 1;

        // wyliczamy nowy mniejszy skladnik, na ktory bedziemy rozbijac pule
        int newPartSize = partValues[uniquePartsCount] - 1;

        // jesli cos jeszcze zostalo z obecnego skladnika przesuwamy index na nowy
        if (partCounts[uniquePartsCount] > 0) {
            uniquePartsCount = uniquePartsCount + 1;
        }

        // upychamy ile wlezie nowych skladnikow
        partValues[uniquePartsCount] = newPartSize;
        partCounts[uniquePartsCount] = removedSum / newPartSize;

        // sprawdzamy czy zostala jakas reszta do wrzucenia na sam koniec
        int remainder = removedSum % newPartSize;

        if (remainder != 0) {
            uniquePartsCount = uniquePartsCount + 1;
            partValues[uniquePartsCount] = remainder;
            partCounts[uniquePartsCount] = 1;
        }

        savePartToFile(partValues, partCounts, uniquePartsCount, outFile);
    }

    outFile.close();
}

int main() {
    int numberToPartition = inputPositiveInteger();

    generatePartitions(numberToPartition, "output_program03.txt");

    return 0;
}