#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Structure to represent an edge in the graph
struct Edge {
  int dest, weight;
};
class Graph {
  int V;                        // Number of vertices
  vector<vector<Edge>> adjList; // Adjacency list to store edges
public:
  Graph(int v) : V(v), adjList(v) {}
  // Function to add an edge to the graph
  void addEdge(int src, int dest, int weight) {
    Edge edge = {dest, weight};
    adjList[src].push_back(edge);
  } // Function to find the shortest path from a single source using Dijkstra's
    // algorithm
  void DijkstraShortestPath(int source) {
    // Create a vector to store distances and initialize with infinity
    vector<int> distances(V, INT_MAX);
    // Mark the distance of the source vertex as 0
    distances[source] = 0;
    // Create a priority queue to store vertices and their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      // Iterate through all adjacent vertices of u
      for (Edge edge : adjList[u]) {
        int v = edge.dest;
        int weight = edge.weight;
        if (distances[v] > distances[u] + weight) { // Relaxation step
          distances[v] = distances[u] + weight;
          pq.push(make_pair(distances[v], v));
        }
      }
    } // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
      cout << " To Vertex " << i << ": ";
      if (distances[i] == INT_MAX)
        cout << "INF\n";
      else
        cout << distances[i] << "\n";
    }
  }
};
int main() {
  // Create a graph representing the city landmarks
  Graph g(6); // Assuming 6 landmarks
  // Add edges with distances
  g.addEdge(0, 1, 4); // Landmark 0 to Landmark 1 with distance 4
  g.addEdge(0, 2, 1); // Landmark 0 to Landmark 2 with distance 1
  g.addEdge(1, 3, 2); // Landmark 1 to Landmark 3 with distance 2
  g.addEdge(2, 1, 3); // Landmark 2 to Landmark 1 with distance 3
  g.addEdge(2, 3, 5); // Landmark 2 to Landmark 3 with distance 5
  g.addEdge(3, 4, 3); // Landmark 3 to Landmark 4 with distance 3
  g.addEdge(4, 0, 6); // Landmark 4 to Landmark 0 with distance 6
  g.addEdge(4, 1, 1); // Landmark 4 to Landmark 1 with distance 1
  g.addEdge(4, 5, 2); // Landmark 4 to Landmark 5 with distance 2
  g.addEdge(5, 3, 1); // Landmark 5 to Landmark 3 with distance 1
  // Find shortest paths from a single source using Dijkstra's algorithm
  int source = 0; // Assuming source is Landmark 0
  g.DijkstraShortestPath(source);
  return 0;
}
