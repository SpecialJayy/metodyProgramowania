#include <iosfwd>
#include <iostream>
#include <unordered_map>
#include "../libraries/libFile.h"
#include "../libraries/libGraph.h"
#include "../libraries/libArray.h"
using namespace std;

int main() {
    fstream file = openFile("../assets/z5/input.txt");

    int edges,vertexes;
    file >> edges;

    vector<pair<int,int>> connections;

    for (int i = 0; i < edges; i++) {
        int out,in;
        file >> out;
        file >> in;
        connections.push_back({out, in});
    }

    vertexes = countVertex(connections);

    vector<vector<int>> incidentMatrix(connections.size(), vector<int>(vertexes, 0));

    for (int i = 0; i < connections.size(); i++) {
        for (int j = 0; j < vertexes; j++) {
            if (connections[j].first == j+1) {
                incidentMatrix[i][j] = -1;
            } else if (connections[j].second == j+1) {
                incidentMatrix[i][j] = 1;
            } else {
                incidentMatrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < connections.size(); i++) {
        for (int j = 0; j < vertexes; j++) {
            cout << incidentMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}