#ifndef LIBFILE_H
#define LIBFILE_H
#include <iosfwd>
#include <fstream>

/*
 * Funkcja służąca do bezpiecznego otworzenia pliku
 * @Param fileName - nazwa pliku do otworzenia
 * @return otworzony plik
*/

std::fstream openFile(const std::string& fileName);

/*
 * Funkcja służąca do bezpiecznego zamknięcia pliku
 * @Param file - plik fstream do zamknięcia
*/
void closeFile(std::fstream& file);

#endif //LIBFILE_H