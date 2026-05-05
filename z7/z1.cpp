#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <set>
#include <chrono>
#include <fstream>
#include <string>

#include "../libraries/libFile.h"
#include "../libraries/libInput.h"
#include "../libraries/libRandom.h"
using namespace std;

int main() {
    int xMax, n, choice;

    cout << "Podaj maksymalna wartosc Xmax: ";
    xMax = inputPositiveInteger();

    cout << "Podaj ilosc liczb do wygenerowania n:";
    n = inputPositiveInteger();

    cout << "\nWybierz tryb pracy generatora:" << endl;
    cout << "1. Liniowa metoda kongruencyjna (LCG multiplikatywny, c == 0)" << endl;
    cout << "2. Addytywna metoda kongruencyjna (LCG addytywny, c != 0)" << endl;

    choice = inputWithinRange(1,2);

    vector<int> randomNumbers = Random(xMax, n, choice);

    fstream outFile = createOutputFile("output_program07");
    saveVectorToFile(randomNumbers,outFile);

    return 0;
}