#ifndef LIBGRAPH_H
#define LIBGRAPH_H
#include <iosfwd>
#include <vector>

/*
 * funckcja licząca ilosc wierzchołków w grafie skierowanym
 * @param1 - wektor par liczb całkowitych oznaczających połaczenie 2 wierzchołków (wyjściowy - wejściowy)
 * @return zwraca liczbe wierzchołków w grafie
*/
int countVertex(std::vector<std::pair<int,int>>& con);


#endif //LIBGRAPH_H