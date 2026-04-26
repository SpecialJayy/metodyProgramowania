#ifndef LIBGRAPH_H
#define LIBGRAPH_H
#include <iosfwd>
#include <vector>
#include <list>


/*
 * funckcja licząca ilosc wierzchołków w grafie skierowanym
 * @param1 - wektor par liczb całkowitych oznaczających połaczenie 2 wierzchołków (wyjściowy - wejściowy)
 * @return zwraca liczbe wierzchołków w grafie
*/
int countVertex(std::vector<std::pair<int,int>>& con);


/*
 * funkcja wypisująca listę incydencji (sąsiedztwa) dla każdego wierzchołka
 * @param adjacencyList - wektor list przechowujący sąsiadów danego wierzchołka
 * @param vertexes - całkowita liczba wierzchołków w grafie
*/
void printAdjacencyList(const std::vector<std::list<int>>& adjacencyList, int vertexes);

/*
 * funkcja wypisująca stopnie wszystkich wierzchołków (ilość bezpośrednich sąsiadów)
 * @param adjacencyList - wektor list przechowujący sąsiadów danego wierzchołka
 * @param vertexes - całkowita liczba wierzchołków w grafie
*/
void printDegrees(const std::vector<std::list<int>>& adjacencyList, int vertexes);

/*
 * funkcja budująca tablicę list incydencji dla grafu nieskierowanego
 * @param connections - wektor par liczb całkowitych reprezentujących krawędzie grafu
 * @param vertexes - całkowita liczba wierzchołków
 * @return zwraca wektor list incydencji (indeks wektora odpowiada numerowi wierzchołka)
*/
std::vector<std::list<int>> buildAdjacencyList(const std::vector<std::pair<int, int>>& connections, int vertexes);

/*
 * funkcja wypisująca sąsiadów (krawędzie wychodzące) dla grafu skierowanego
 * @param connections - wektor par liczb całkowitych reprezentujących krawędzie skierowane
 * @param vertexes - całkowita liczba wierzchołków
 * @param edges - całkowita liczba krawędzi
*/
void printDirectedNeighbors(const std::vector<std::pair<int, int>>& connections, int vertexes, int edges);

/*
 * funkcja wypisująca macierz incydencji na standardowe wyjście
 * @param incidentMatrix - dwuwymiarowy wektor reprezentujący macierz incydencji
 * @param vertexes - całkowita liczba wierzchołków (ilość wierszy)
 * @param edges - całkowita liczba krawędzi (ilość kolumn)
*/
void printIncidentMatrix(const std::vector<std::vector<int>>& incidentMatrix, int vertexes, int edges);

/*
 * funkcja budująca macierz incydencji dla grafu skierowanego
 * @param connections - wektor par liczb całkowitych reprezentujących krawędzie
 * @param vertexes - całkowita liczba wierzchołków
 * @param edges - całkowita liczba krawędzi
 * @return zwraca gotową, wypełnioną macierz incydencji (-1 dla wyjścia, 1 dla wejścia, 0 brak)
*/
std::vector<std::vector<int>> buildIncidentMatrix(const std::vector<std::pair<int, int>>& connections, int vertexes, int edges);

#endif //LIBGRAPH_H