#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int vertexCount) : matrix(vertexCount,
                                                   std::vector<bool>(vertexCount, false)) {}

MatrixGraph::MatrixGraph(const IGraph &graph) :
        matrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    CopyGraph(graph);
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < matrix.size());
    assert(to >= 0 && to < matrix.size());
    matrix[from][to] = true;
}


int MatrixGraph::VerticesCount() const {
    return (int) matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}
