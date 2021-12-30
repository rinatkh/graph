#include <functional>
#include "IGraph.h"
#include "queue"

void IGraph::CopyGraph(const IGraph &other) {
    for (int vertex = 0; vertex < other.VerticesCount(); vertex++) {
        std::vector<int> nextVertices = other.GetNextVertices(vertex);
        for (const auto &v: nextVertices) {
            AddEdge(vertex, v);
        }
    }
}

void
BFS(const IGraph &graph, int vertex, std::vector<bool> &visited,
    void (*visit)(int)) {
    std::queue<int> queue;
    queue.push(vertex);
    visited[vertex] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        visit(current);
        for (int nextVertex: graph.GetNextVertices(current)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                queue.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph &graph, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i])
            BFS(graph, i, visited, visit);
    }
}

void
DFS(const IGraph &graph, int vertex, std::vector<bool> &visited,
    void (*visit)(int)) {
    visited[vertex] = true;
    visit(vertex);

    for (int nextVertex: graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, visit);
    }

}

void mainDFS(const IGraph &graph, void (*visit)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++) {
        if (!visited[i])
            DFS(graph, i, visited, visit);
    }
}
