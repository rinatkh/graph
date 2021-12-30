#pragma once

#include "IGraph.h"
#include <set>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int vertexCount);

    explicit SetGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> set;
};
