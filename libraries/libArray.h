#ifndef LIBARRAY_H
#define LIBARRAY_H
#include <iosfwd>
#include <iostream>
#include <vector>

/*
 * Funkcja służąca do obliczenia błędu średniokwadratowego (MSE) dla całej siatki silników
 * @Param engineList - tablica 3D przechowująca dane 81 silników kandydujących
 * @Param unknownEngine - tablica 2D przechowująca dane nieznanego silnika
 * @Param mseResults - tablica 1D do zapisania obliczonych wyników MSE
 * @return indeks (ID) silnika o najmniejszym błędzie dopasowania
*/
int calculateMSE(double engineList[81][106][2], double unknownEngine[106][2], double mseResults[81]);

/*
 * Funkcja służąca do wypisania tabeli wyników MSE oraz danych najlepszego silnika w konsoli
 * @Param engineList - tablica 3D przechowująca dane 81 silników kandydujących
 * @Param mseResults - tablica 1D przechowująca obliczone wyniki MSE
 * @Param bestId - indeks silnika z najmniejszym błędem MSE
*/
void printResults(double engineList[81][106][2], double mseResults[81], int bestId);

/*
 * Funkcja służąca do zapisu wyników obliczeń oraz danych najlepszego silnika do pliku wyjściowego
 * @Param engineList - tablica 3D przechowująca dane 81 silników kandydujących
 * @Param mseResults - tablica 1D przechowująca obliczone wyniki MSE
 * @Param bestId - indeks silnika z najmniejszym błędem MSE
 * @Param filename - docelowa nazwa pliku wyjściowego
*/
void saveResultsToFile(double engineList[81][106][2], double mseResults[81], int bestId, const std::string& filename);

/*
 * Funkcja służąca do wczytania danych pojedynczego silnika z pliku tekstowego
 * @Param engineList - tablica 2D, do której zostaną wczytane parametry i pomiary
 * @Param file - referencja do otwartego pliku wejściowego fstream
*/
void applyEngine(double engineList[106][2], std::fstream& file);

/*
 * Funkcja służąca do wczytania danych całej siatki (81 silników) z pliku tekstowego
 * @Param engineList - tablica 3D, do której zostaną wczytane dane wszystkich kandydatów
 * @Param file - referencja do otwartego pliku wejściowego fstream
*/
void applyEngines(double engineList[81][106][2], std::fstream& file);

/*
 * Funkcja służąca do wypisania parametrów i pomiarów pojedynczego silnika w konsoli
 * @Param engineList - tablica 2D przechowująca dane silnika do wypisania
*/
void printEngine(double engineList[106][2]);

/*
 * Funkcja służąca do wypisania parametrów i pomiarów wszystkich 81 silników w konsoli
 * @Param engineList - tablica 3D przechowująca dane wszystkich silników siatki
*/
void printEngines(double engineList[81][106][2]);

/*
 * Funkcja pomocnicza służąca do rekurencyjnego przeszukiwania tablicy algorytmem Saddleback
 * @Param array - dwuwymiarowy wektor (macierz) posortowanych danych
 * @Param target - poszukiwana wartość
 * @Param rows - całkowita liczba wierszy w macierzy
 * @Param cols - całkowita liczba kolumn w macierzy
 * @Param findFirst - flaga logiczna określająca czy szukamy pierwszego (true) czy ostatniego (false) wystąpienia
 * @Param r - aktualnie sprawdzany wiersz (stan rekurencji)
 * @Param c - aktualnie sprawdzana kolumna (stan rekurencji)
 * @Param bestRow - zapamiętany wiersz najlepszego dopasowania
 * @Param bestCol - zapamiętana kolumna najlepszego dopasowania
 * @return para liczb całkowitych (wiersz, kolumna) reprezentująca pozycję szukanego elementu
*/
std::pair<int, int> saddleBackHelper(const std::vector<std::vector<int>>& array, int target, int rows, int cols, bool findFirst, int r, int c, int bestRow, int bestCol);

/*
 * Funkcja służąca do wyszukiwania elementu w posortowanej macierzy z wykorzystaniem rekurencyjnego algorytmu Saddleback
 * @Param array - dwuwymiarowy wektor (macierz) posortowanych danych
 * @Param target - poszukiwana wartość
 * @Param findFirst - flaga logiczna określająca czy szukamy pierwszego (true) czy ostatniego (false) wystąpienia
 * @return para liczb całkowitych (wiersz, kolumna) reprezentująca pozycję szukanego elementu
*/
std::pair<int, int> saddleBackRec(const std::vector<std::vector<int>>& array, int target, bool findFirst);

/*
 * Funkcja służąca do wyszukiwania elementu w posortowanej macierzy z wykorzystaniem iteracyjnego algorytmu Saddleback
 * @Param array - dwuwymiarowy wektor (macierz) posortowanych danych
 * @Param target - poszukiwana wartość
 * @Param findFirst - flaga logiczna określająca czy szukamy pierwszego (true) czy ostatniego (false) wystąpienia
 * @return para liczb całkowitych (wiersz, kolumna) reprezentująca pozycję szukanego elementu
*/
std::pair<int, int> saddleBackIter(const std::vector<std::vector<int>>& array, int target, bool findFirst);



#endif //LIBARRAY_H