#include "ArcGraph.h"
#include <cassert>

ArcGraph::ArcGraph(int vertexCount) : vertexsCount(vertexCount) {}

ArcGraph::ArcGraph(const IGraph &graph) : vertexsCount(graph.VerticesCount()) {
    CopyGraph(graph);
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertexsCount);
    assert(to >= 0 && to < vertexsCount);
    std::pair<int, int> pair(from, to);
    edges.push_back(pair);
}

int ArcGraph::VerticesCount() const {
    return vertexsCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (const auto &i: edges) {
        if (i.first == vertex)
            result.push_back(i.second);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (const auto &i: edges) {
        if (i.second == vertex)
            result.push_back(i.first);
    }
    return result;
}
