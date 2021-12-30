#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include <iostream>

void print(int vertex) {
    std::cout << vertex << " ";
}

void tests() {
    ListGraph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddEdge(2, 4);

    mainBFS(graph, print);
    std::cout << std::endl;
    mainDFS(graph, print);
    std::cout << std::endl << std::endl;

    //переход от list к arc
    SetGraph set(graph);
    MatrixGraph matrix(set);
    ArcGraph arc(matrix);

    mainBFS(arc, print);
    std::cout << std::endl;
    mainDFS(arc, print);
    std::cout << std::endl;
}

int main() {
    tests();
    return 0;
}
