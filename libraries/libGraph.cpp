#include "libGraph.h"
#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int countVertex(std::vector<std::pair<int,int>>& con) {
    std::unordered_map<int,int> vertexes;

    for (auto connection: con) {
        vertexes[connection.first] += connection.first;
        vertexes[connection.second] += connection.second;
    }

    return vertexes.size();
}

void printAdjacencyList(const vector<list<int>>& adjacencyList, int vertexes) {
    for (int i = 1; i <= vertexes; i++) {
        cout << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printDegrees(const vector<list<int>>& adjacencyList, int vertexes) {
    for (int i = 1; i <= vertexes; i++) {
        cout << i << ": " << adjacencyList[i].size() << endl;
    }
}

vector<list<int>> buildAdjacencyList(const vector<pair<int, int>>& connections, int vertexes) {
    vector<list<int>> adjacencyList(vertexes + 1);
    for (const auto& conn : connections) {
        adjacencyList[conn.first].push_back(conn.second);
        adjacencyList[conn.second].push_back(conn.first);
    }
    return adjacencyList;
}

void printDirectedNeighbors(const vector<pair<int, int>>& connections, int vertexes, int edges) {
    for (int i = 1; i <= vertexes; i++) {
        cout << i << " :";
        for (int j = 0; j < edges; j++) {
            if (connections[j].first == i) {
                cout << connections[j].second << " ";
            }
        }
        cout << endl;
    }
}

void printIncidentMatrix(const vector<vector<int>>& incidentMatrix, int vertexes, int edges) {
    for (int i = 0; i < vertexes; i++) {
        for (int j = 0; j < edges; j++) {
            cout << incidentMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> buildIncidentMatrix(const vector<pair<int, int>>& connections, int vertexes, int edges) {
    vector<vector<int>> incidentMatrix(vertexes, vector<int>(edges, 0));
    for (int i = 0; i < edges; i++) {
        incidentMatrix[connections[i].first - 1][i] = -1;
        incidentMatrix[connections[i].second - 1][i] = 1;
    }
    return incidentMatrix;
}
