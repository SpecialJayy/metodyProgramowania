#include "libGraph.h"
#include <unordered_map>

int countVertex(std::vector<std::pair<int,int>>& con) {
    std::unordered_map<int,int> vertexes;

    for (auto connection: con) {
        vertexes[connection.first] += connection.first;
        vertexes[connection.second] += connection.second;
    }

    return vertexes.size();
}
