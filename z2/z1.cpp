#include <fstream>
#include <iostream>
#include "../libraries/libFile.h"

using namespace std;
int main() {
    fstream seak = openFile("assets/Pliki_wejsciowe_laboratorium2/nmSEAK.txt");
    fstream seakMesh = openFile("assets/Pliki_wejsciowe_laboratorium2/siatka_SEAK.txt");
    fstream seb = openFile("assets/Pliki_wejsciowe_laboratorium2/nmSEB.txt");
    fstream sebMesh = openFile("assets/Pliki_wejsciowe_laboratorium2/siatkaSEB.txt");


    closeFile(seak);
    closeFile(seakMesh);
    closeFile(seb);
    closeFile(sebMesh);
    cout << "All went well :)" << endl;
    return 0;
}
