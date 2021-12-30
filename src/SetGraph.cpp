#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int vertexCount) : set(vertexCount) {}

SetGraph::SetGraph(const IGraph &graph) : set(graph.VerticesCount()) {
    CopyGraph(graph);
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < set.size());
    assert(0 <= to && to < set.size());
    set[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return (int) set.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < set.size());
    std::vector<int> result;
    for (const auto &i: set[vertex]) {
        result.push_back(i);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < set.size());
    std::vector<int> result;
    for (int from = 0; from < set.size(); from++) {
        for (const int &to: set[from]) {
            if (to == vertex) {
                result.push_back(from);
            }
        }
    }
    return result;
}
