#include <fstream>
#include <iostream>
#include "../libraries/libFile.h"

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

    closeFile(seak);
    closeFile(seakMesh);
    closeFile(seb);
    closeFile(sebMesh);
    cout << "All went well :)" << endl;
    return 0;
}
