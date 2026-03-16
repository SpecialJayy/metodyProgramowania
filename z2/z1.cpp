#include <fstream>
#include <iostream>
#include "../libraries/libFile.h"
#include "../libraries/libArray.h"

using namespace std;

int main() {
    fstream seak,seakMesh,seb,sebMesh;
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

    findMatch(measuredSEAKEngines,unknownSEAKEngine);

    //dla silnika SEB

    cout << endl << endl << endl << "Wyniki dla Silnika elektrycznego bezszczotkowego" << endl;

    double measuredSEBEngines[81][106][2]{};
    double unknownSEBEngine[106][2]{};

    applyEngines(measuredSEBEngines,sebMesh);
    applyEngine(unknownSEBEngine,seb);

    findMatch(measuredSEBEngines,unknownSEBEngine);

    closeFile(seak);
    closeFile(seakMesh);
    closeFile(seb);
    closeFile(sebMesh);
    return 0;
}
