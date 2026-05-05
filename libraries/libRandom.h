#ifndef METODYPROGRAMOWANIA_LIBRANDOM_H
#define METODYPROGRAMOWANIA_LIBRANDOM_H
#include <chrono>
#include <vector>

/*
 * Funkcja służąca do zczytania pseudolosowej liczby na podstawie zegara procesora
*/
long long chronoRandom();

/*
 * Funkcja zwracająca wektor pseudolosowo wygenerowanych liczb metodą kongruencyjną addytywną/liniową
 * @Param int xMax - maksymalna liczba do wygenerowania
 * @Param int n - ilość liczb do wygenerowania
 * @Param int choice - wybór sposobu generowania (1 - liniowa, 2- addytywna)
*/
std::vector<int> Random(int xMax, int n, int choice);

#endif //METODYPROGRAMOWANIA_LIBRANDOM_H