#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../libraries/libFile.h"
#include "../libraries/libArray.h"
#include "../libraries/libInput.h"

using namespace std;
//n -> totalElements
//B -> binarySubset
//i -> generatedCount
//p -> bitPosition
//j -> tempCount
//k -> index

// funkcja zapisujaca obecny stan podzbioru do pliku
void saveSubsetToFile(const std::vector<int>& binarySubset, int totalElements, std::fstream& outFile) {
    for (int index = 1; index <= totalElements; ++index) {
        outFile << binarySubset[index] << (index == totalElements ? "" : " ");
    }
    outFile << "\n";
}

// glowna funkcja generujaca podzbiory
void divideSet(int totalElements, const std::string& filename) {
    // tworzenie pliku wyjsciowego z zabezpieczeniem
    std::fstream outFile = createOutputFile(filename);

    // wektor na bity, rozmiar totalElements+1 zeby indeksowac od 1
    std::vector<int> binarySubset(totalElements + 1, 0);
    int generatedCount = 0;
    int bitPosition, tempCount;

    do {
        saveSubsetToFile(binarySubset, totalElements, outFile);

        generatedCount = generatedCount + 1;
        bitPosition = 1;
        tempCount = generatedCount;

        // szukamy najmlodszego bitu do zmiany
        while (tempCount % 2 == 0) {
            tempCount = tempCount / 2;
            bitPosition = bitPosition + 1;
        }

        // flip bitu na pozycji bitPosition
        if (bitPosition <= totalElements) {
            binarySubset[bitPosition] = 1 - binarySubset[bitPosition];
        }

    } while (bitPosition <= totalElements);

    // bezpieczne zamkniecie strumienia
    outFile.close();
}

int main() {
    // bierzemy ilosc elementow zbioru z walidacja wejscia
    int totalElements = inputPositiveInteger();

    divideSet(totalElements, "output_program01.txt");

    return 0;
}