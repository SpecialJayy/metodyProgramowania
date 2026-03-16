#include <cmath>
#include <iostream>
#include <fstream>
#include "libArray.h"

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

void findMatch(double engineList[81][106][2], double unknownEngine[106][2]) {
    double best = 0.0;
    int bestId = 0;

    // tablica do przechowania wynikow mse
    double mseResults[81]{};

    for (int engine = 0; engine < 81; engine++) {
        double mse = 0.0;

        // zaczynamy od indeksu 6, zeby pominac parametry w wyliczeniach mse
        for (int measurement = 6; measurement < 106; measurement++) {
            // dla y
            double a = pow(unknownEngine[measurement][1] - engineList[engine][measurement][1], 2);

            // dla x
            double b = pow(unknownEngine[measurement][0] - engineList[engine][measurement][0], 2);

            mse += a + b;
        }

        // oryginalny wzor z pierwiastkiem
        mse = sqrt(mse);

        // zapisanie wyniku do tabeli
        mseResults[engine] = mse;

        // pierwszy blad przypisujemy jako najlepszy startowy
        if (engine == 0) {
            best = mse;
            bestId = engine;
        } else if (mse < best) {
            best = mse;
            bestId = engine;
        }
    }

    // wyswietlenie tabeli wszystkich policzonych mse
    std::cout << "\n=== tabela policzonych mse ===\n";
    for (int i = 0; i < 81; i++) {
        std::cout << "silnik [" << i << "] mse = " << mseResults[i] << "\n";
    }

    // wyswietlenie najlepszego wyniku
    std::cout << "==============================\n";
    std::cout << "najlepsze mse: " << best << "\n";
    std::cout << "najlepszy silnik: " << bestId << "\n";
    std::cout << "==============================\n\n";

    // wyswietlenie danych najlepszego silnika
    std::cout << "dane pomiarowe dla silnika " << bestId << ":\n";
    printEngine(engineList[bestId]);
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