#include <fstream>
#include <iostream>
#include "../libraries/libFile.h"
#include "../libraries/libArray.h"
#include "../libraries/libInput.h"

using namespace std;

int mainLKII() {
    fstream seak,seakMesh,seb,sebMesh;

    cout << "Prosze podac nazwe pliku wyjsciowego dla silnikow SEAK" << endl;
    string fileNameSEAK = inputString();

    cout << "Prosze podac nazwe pliku wyjsciowego dla silnikow SEB" << endl;
    string fileNameSEB = inputString();

    try {
        seak = openFile("../assets/Pliki_wejsciowe_laboratorium2/silnikSEAK/nmSEAK.txt");
        seakMesh = openFile("../assets/Pliki_wejsciowe_laboratorium2/silnikSEAK/siatka_SEAK.txt");
        seb = openFile("../assets/Pliki_wejsciowe_laboratorium2/silnikSEB/nmSEB.txt");
        sebMesh = openFile("../assets/Pliki_wejsciowe_laboratorium2/silnikSEB/siatkaSEB.txt");
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    //dla silnika SEAK
    //81 silników, po 100 pomiarów, po 2 wartości (X,Y)

    cout << "Wyniki dla Silnika asynchronicznego klatkowego" << endl;

    double measuredSEAKEngines[81][106][2]{};
    double unknownSEAKEngine[106][2]{};

    applyEngines(measuredSEAKEngines,seakMesh);
    applyEngine(unknownSEAKEngine,seak);

    double mseResultsSEAK[81]{}; // tablica na wyniki
    int bestIdSEAK = calculateMSE(measuredSEAKEngines, unknownSEAKEngine, mseResultsSEAK);
    // printResults(measuredSEAKEngines, mseResultsSEAK, bestIdSEAK);
    saveResultsToFile(measuredSEAKEngines, mseResultsSEAK, bestIdSEAK, fileNameSEAK);

    //dla silnika SEB

    cout << endl << endl << endl << "Wyniki dla Silnika elektrycznego bezszczotkowego" << endl;

    double measuredSEBEngines[81][106][2]{};
    double unknownSEBEngine[106][2]{};

    applyEngines(measuredSEBEngines,sebMesh);
    applyEngine(unknownSEBEngine,seb);

    double mseResultsSEB[81]{}; // tablica na wyniki
    int bestIdSEB = calculateMSE(measuredSEBEngines, unknownSEBEngine, mseResultsSEB);
    // printResults(measuredSEBEngines, mseResultsSEB, bestIdSEB);
    saveResultsToFile(measuredSEBEngines, mseResultsSEB, bestIdSEB, fileNameSEB);

    closeFile(seak);
    closeFile(seakMesh);
    closeFile(seb);
    closeFile(sebMesh);
    return 0;
}
