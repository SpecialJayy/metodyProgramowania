#ifndef LIBFILE_H
#define LIBFILE_H
#include <iosfwd>
#include <fstream>
#include <vector>

/*
 * Funkcja służąca do bezpiecznego otworzenia pliku
 * @Param fileName - sciezka pliku do otworzenia
 * @return otworzony plik
*/

std::fstream openFile(const std::string& fileName);

/*
 * Funkcja służąca do bezpiecznego zamknięcia pliku
 * @Param file - plik fstream do zamknięcia
*/
void closeFile(std::fstream& file);

/*
 * Funkcja służąca do stworzenia i zwrócenia pliku gotowego do zapisu danych
 * @Param fileName - nazwa pliku
*/
std::fstream createOutputFile(const std::string &fileName);

/*
 * Funkcja służąca do zapisania podzbioru do pliku
 * @Param vector<int> arr - tablica
 * @Param int size - rozmiar
 * @Param fstream outFile - plik wyjściowy
*/
void saveSubsetToFile(const std::vector<int>& arr, int size, std::fstream outFile);


/*
 * Funkcja służąca do zapisania wektoru intów do pliku
 * @Param vector<int> arr - tablica
 * @Param fstream outFile - plik wyjściowy
*/
void saveVectorToFile(const std::vector<int>& arr, std::fstream& outFile);

#endif //LIBFILE_H