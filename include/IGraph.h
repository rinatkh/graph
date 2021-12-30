#pragma once

#include <vector>

struct IGraph {
    virtual ~IGraph() = default;

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

    void CopyGraph(const IGraph &other);
};

void
BFS(const IGraph &graph, int vertex, std::vector<bool> &visited,
    void (*visit)(int));

void
DFS(const IGraph &graph, int vertex, std::vector<bool> &visited,
    void (*visit)(int));

void mainDFS(const IGraph &graph, void (*visit)(int));

void mainBFS(const IGraph &graph, void (*visit)(int));