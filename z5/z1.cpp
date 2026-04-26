#include <iosfwd>
#include <iostream>
#include <vector>
#include <list>
#include "../libraries/libFile.h"
#include "../libraries/libGraph.h"
using namespace std;

void skierowany(fstream& file) {
    file.clear();
    file.seekg(0, ios::beg);

    int edges;
    file >> edges;

    vector<pair<int, int>> connections;

    for (int i = 0; i < edges; i++) {
        int out, in;
        file >> out;
        file >> in;
        connections.push_back({out, in});
    }

    int vertexes = countVertex(connections);

    vector<vector<int>> incidentMatrix = buildIncidentMatrix(connections, vertexes, edges);

    printIncidentMatrix(incidentMatrix, vertexes, edges);
    printDirectedNeighbors(connections, vertexes, edges);
}

void nieSkierowany(fstream& file) {
    file.clear();
    file.seekg(0, ios::beg);

    int edges;
    file >> edges;

    vector<pair<int, int>> connections;

    for (int i = 0; i < edges; i++) {
        int out, in;
        file >> out;
        file >> in;
        connections.push_back({out, in});
    }

    int vertexes = countVertex(connections);

    vector<list<int>> adjacencyList = buildAdjacencyList(connections, vertexes);

    printAdjacencyList(adjacencyList, vertexes);
    printDegrees(adjacencyList, vertexes);
}

int main() {
    fstream file = openFile("../assets/z5/input.txt");

    skierowany(file);
    cout << endl;
    nieSkierowany(file);

    return 0;
}