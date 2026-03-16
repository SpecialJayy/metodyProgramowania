#include <cmath>
#include <iostream>
#include <fstream>
#include "libArray.h"
#include "libFile.h"

void printEngine(double engineList[106][2]) {
    // wypisywanie 6 parametrow z poczatku wiersza (indeksy 0-5)
    std::cout << "parametry y: ";
    for(int p = 0; p < 6; p++) std::cout << engineList[p][1] << " ";
    std::cout << "\nparametry x: ";
    for(int p = 0; p < 6; p++) std::cout << engineList[p][0] << " ";
    std::cout << "\n\n";

    // wypisywanie 100 wlasciwych pomiarow (indeksy 6-105)
    for (int measurement = 6; measurement < 106; measurement++) {
        std::cout << "measurement [" << measurement - 5 << "]: "
                  << "X = " << engineList[measurement][0]
                  << " | Y = " << engineList[measurement][1]
                  << "\n";
    }
    std::cout << "\n";
}

int calculateMSE(double engineList[81][106][2], double unknownEngine[106][2], double mseResults[81]) {
    double best = 0.0;
    int bestId = 0;

    for (int engine = 0; engine < 81; engine++) {
        double mse = 0.0;

        for (int measurement = 6; measurement < 106; measurement++) {
            double a = pow(unknownEngine[measurement][1] - engineList[engine][measurement][1], 2);
            double b = pow(unknownEngine[measurement][0] - engineList[engine][measurement][0], 2);
            mse += a + b;
        }

        mse = sqrt(mse);
        mseResults[engine] = mse;

        if (engine == 0 || mse < best) {
            best = mse;
            bestId = engine;
        }
    }

    return bestId;
}

void printResults(double engineList[81][106][2], double mseResults[81], int bestId) {
    std::cout << "\n=== tabela policzonych mse ===\n";
    for (int i = 0; i < 81; i++) {
        std::cout << "silnik [" << i << "] mse = " << mseResults[i] << "\n";
    }

    std::cout << "==============================\n";
    std::cout << "najlepsze mse: " << mseResults[bestId] << "\n";
    std::cout << "najlepszy silnik: " << bestId << "\n";
    std::cout << "==============================\n\n";

    std::cout << "dane pomiarowe dla silnika " << bestId << ":\n";
    printEngine(engineList[bestId]); // korzysta z twojej funkcji printEngine
}

void saveResultsToFile(double engineList[81][106][2], double mseResults[81], int bestId, const std::string& filename) {
    try {
        std::fstream outFile = createOutputFile(filename);

        outFile << "=== tabela policzonych mse ===\n";
        for (int i = 0; i < 81; i++) {
            outFile << "silnik [" << i << "] mse = " << mseResults[i] << "\n";
        }

        outFile << "==============================\n";
        outFile << "najlepsze mse: " << mseResults[bestId] << "\n";
        outFile << "najlepszy silnik: " << bestId << "\n";
        outFile << "==============================\n\n";

        outFile << "dane pomiarowe dla silnika " << bestId << ":\n";

        outFile << "parametry y: ";
        for(int p = 0; p < 6; p++) outFile << engineList[bestId][p][1] << " ";
        outFile << "\nparametry x: ";
        for(int p = 0; p < 6; p++) outFile << engineList[bestId][p][0] << " ";
        outFile << "\n\n";

        for (int measurement = 6; measurement < 106; measurement++) {
            outFile << "measurement [" << measurement - 5 << "]: "
                      << "X = " << engineList[bestId][measurement][0]
                      << " | Y = " << engineList[bestId][measurement][1]
                      << "\n";
        }

        closeFile(outFile);
        std::cout << "poprawnie zapisano wyniki do pliku: " << filename << "\n";

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
}

void applyEngine(double engineList[106][2], std::fstream& file) {
    // bierzemy caly wiersz y (106 wartosci: 6 parametrow + 100 pomiarow)
    for (int i = 0; i < 106; i++) {
        file >> engineList[i][1];
    }

    // bierzemy caly wiersz x (106 wartosci: 6 parametrow + 100 pomiarow)
    for (int i = 0; i < 106; i++) {
        file >> engineList[i][0];
    }
}

void applyEngines(double engineList[81][106][2], std::fstream& file) {
    for (int engine = 0; engine < 81; engine++) {
        applyEngine(engineList[engine], file);
    }
}

void printEngines(double engineList[81][106][2]) {
    for (int engine = 0; engine < 81; engine++) {
        std::cout << "====================================\n";
        std::cout << "engine nr: " << engine << "\n";
        std::cout << "====================================\n";

        // wypluwamy dane konkretnego kandydata
        printEngine(engineList[engine]);
    }
}