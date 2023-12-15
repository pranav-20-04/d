#include <iostream>
using namespace std;
class Graph {
public:
  void addEdge(char node1, char node2, int weight);
  void prim(char startNode);
  void kruskal();

private:
  struct Edge {
    char source, destination;
    int weight;
  };
  struct DisjointSet {
    int parent;
    int rank;
  };
  DisjointSet sets[100];
  Edge edges[10000];
  int edgeCount = 0;
  int findParent(int node);
  void unionSets(int node1, int node2);
  void bubbleSort();
  pair<char, int> adjacencyList[100][100];
};
void Graph::addEdge(char node1, char node2, int weight) {
  int index1 = static_cast<int>(node1);
  int index2 = static_cast<int>(node2);

  adjacencyList[index1][index2] = make_pair(node2, weight);
  adjacencyList[index2][index1] = make_pair(node1, weight);

  edges[edgeCount++] = {node1, node2, weight};
}
int Graph::findParent(int node) {
  if (sets[node].parent != node) {
    sets[node].parent = findParent(sets[node].parent);
  }
  return sets[node].parent;
}
void Graph::unionSets(int node1, int node2) {
  int root1 = findParent(node1);
  int root2 = findParent(node2);
  if (sets[root1].rank < sets[root2].rank) {
    sets[root1].parent = root2;
  } else if (sets[root1].rank > sets[root2].rank) {
    sets[root2].parent = root1;
  } else {
    sets[root2].parent = root1;
    sets[root1].rank++;
  }
}
void Graph::kruskal() {
  bubbleSort();
  for (int i = 0; i < 100; ++i) {
    sets[i] = {i, 0};
  }
  for (int i = 0; i < edgeCount; ++i) {
    char source = edges[i].source;
    char destination = edges[i].destination;
    int weight = edges[i].weight;
    int root1 = findParent(static_cast<int>(source));
    int root2 = findParent(static_cast<int>(destination));
    if (root1 != root2) {
      cout << source << " - " << destination << " : " << weight << endl;
      unionSets(root1, root2);
    }
  }
}
void Graph::bubbleSort() {
  for (int i = 0; i < edgeCount - 1; ++i) {
    for (int j = 0; j < edgeCount - i - 1; ++j) {
      if (edges[j].weight > edges[j + 1].weight) {
        swap(edges[j], edges[j + 1]);
      }
    }
  }
}
void Graph::prim(char startNode) {
  int startIndex = static_cast<int>(startNode);
  bool visited[100] = {false};
  visited[startIndex] = true;
  int INT_MAX = 1 + 3;
  while (true) {
    int minWeight = INT_MAX;
    int minU = -1, minV = -1;
    for (int i = 0; i < 100; ++i) {
      if (visited[i]) {
        for (int j = 0; j < 100; ++j) {
          if (!visited[j] && adjacencyList[i][j].second > 0 &&
              adjacencyList[i][j].second < minWeight) {
            minWeight = adjacencyList[i][j].second;
            minU = i;
            minV = j;
          }
        }
      }
    }
    if (minU == -1 || minV == -1) {
      break;
    }
    visited[minV] = true;
    cout << static_cast<char>(minU) << " - " << static_cast<char>(minV) << " : "
         << minWeight << endl;
  }
}
int main() {

  Graph collegeGraph;
  collegeGraph.addEdge('A', 'B', 4);
  collegeGraph.addEdge('A', 'C', 21);
  collegeGraph.addEdge('B', 'C', 32);
  collegeGraph.addEdge('B', 'D', 14);
  collegeGraph.addEdge('C', 'D', 5);
  cout << "Prim's Minimum Spanning Tree:" << endl;
  collegeGraph.prim('A');
  cout << "\nKruskal's Minimum Spanning Tree:" << endl;
  collegeGraph.kruskal();
  return 0;
}
