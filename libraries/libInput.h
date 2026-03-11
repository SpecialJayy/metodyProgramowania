#ifndef LIBINPUT_H
#define LIBINPUT_H
#include <string>

/*
 * funckcja pytająca o wprowadzenie dowolnej liczby całkowitej
 * @return zwraca liczbe podaną przez użytkownika
*/
int inputInteger();

/*
 * funckcja pytająca o wprowadzenie dowolnego ciągu znaków
 * @return zwraca ciąg znaków podany przez użytkownika
*/
std::string& inputString();

/*
 * funckcja pytająca o wprowadzenie dowolnej liczby całkowitej dodatniej
 * @return zwraca liczbe podaną przez użytkownika
*/
int inputPositiveInteger();

/*
 * funckja pytająca o wprowadzenie dowolnej liczby całkowitej znajdującej się między 2 wartościami
 * @param min - zakres dolny
 * @param max - zakres górny
 * @return zwraca liczbe podaną przez użytkownika
*/
int inputWithinRange(int min, int max);

#endif //LIBINPUT_H