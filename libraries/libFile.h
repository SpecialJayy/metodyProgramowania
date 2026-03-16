#ifndef LIBFILE_H
#define LIBFILE_H
#include <iosfwd>
#include <fstream>

/*
 * Funkcja służąca do bezpiecznego otworzenia pliku
 * @Param fileName - nazwa pliku do otworzenia
 * @return otworzony plik
*/

std::fstream openFile(const std::string& fileName) {
 std::fstream file;

 file.open(fileName, std::ios::in);

 if (!file.is_open()) {
  throw std::runtime_error("Critical error: Nie udalo sie otowrzyc pliku -> " + fileName);
 }

 return file;
}

/*
 * Funkcja służąca do bezpiecznego zamknięcia pliku
 * @Param file - plik fstream do zamknięcia
*/
void closeFile(std::fstream& file) {
 if (file.is_open()) {
  file.close();
 }
}

#endif //LIBFILE_H