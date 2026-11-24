#include <iostream>
using namespace std;
class Graph {
 int vertices;
 int adj[20][20];
 bool visited[20];
public:
 void createGraph();
 void displayGraph();
 void resetVisited();
 void DFS(int start);
};
// Create road network (undirected graph)
void Graph::createGraph() {
 int edges, u, v;
 cout << "Enter number of intersections (vertices, max 20): ";
 cin >> vertices;
 // Initialize matrix with 0
 for (int i = 0; i < vertices; i++) {
 visited[i] = false;
 for (int j = 0; j < vertices; j++)
 adj[i][j] = 0;
 }
 cout << "Enter number of roads (edges): ";
 cin >> edges; for (int k = 1; k <= edges; k++) {
 cout << "Enter road " << k << " (intersection1 intersection2): ";
 cin >> u >> v;
 if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
 cout << "Invalid vertices! Try again.\n";
 k--;
 continue;
 }
 adj[u][v] = 1;
 adj[v][u] = 1;
 }
}
void Graph::displayGraph() {
 cout << "\nAdjacency Matrix:\n ";
 for (int i = 0; i < vertices; i++)
 cout << i << " ";
 cout << endl;
 for (int i = 0; i < vertices; i++) {
 cout << i << " ";
 for (int j = 0; j < vertices; j++)
 cout << adj[i][j] << " ";
 cout << endl;
 }
}
void Graph::resetVisited() {
 for (int i = 0; i < vertices; i++)
 visited[i] = false;
} // Recursive DFS
void Graph::DFS(int v) {
 visited[v] = true; // mark visited
 cout << v << " "; // display vertex
 for (int i = 0; i < vertices; i++) {
 if (adj[v][i] == 1 && !visited[i])
 DFS(i);
 }
}
int main() {
 Graph cityRoad;
 int start;
 cityRoad.createGraph();
 cityRoad.displayGraph();
 cout << "\nEnter starting intersection: ";
 cin >> start;
 cityRoad.resetVisited();
 cout << "DFS Traversal: ";
 cityRoad.DFS(start);
 cout << endl;
 return 0;
}
Part B

#include <iostream>
using namespace std;
class Graph {
 int intersections;
 int roadMatrix[20][20];
 bool visited[20];
public:
 void createRoadNetwork();
 void displayGraph();
 void resetVisited();
 void exploreRoadNetwork(int location);
 void exploreAll();
};
// Create the road network (undirected graph)
void Graph::createRoadNetwork() {
 int roads, u, v;
 cout << "Enter number of intersections (max 20): ";
 cin >> intersections;
 for (int i = 0; i < intersections; i++) {
 visited[i] = false;
 for (int j = 0; j < intersections; j++)
 roadMatrix[i][j] = 0; }
 cout << "Enter number of roads: ";
 cin >> roads;
 for (int k = 1; k <= roads; k++) {
 cout << "Enter road " << k << " (intersection1 intersection2): ";
 cin >> u >> v;
 if (u < 0 || u >= intersections || v < 0 || v >= intersections) {
 cout << "Invalid intersection! Try again.\n";
 k--;
 continue;
 }
 roadMatrix[u][v] = 1;
 roadMatrix[v][u] = 1;
 }
}
void Graph::displayGraph() {
 cout << "\nRoad Network (Adjacency Matrix):\n ";
 for (int i = 0; i < intersections; i++)
 cout << i << " ";
 cout << endl;
 for (int i = 0; i < intersections; i++) {
 cout << i << " ";
 for (int j = 0; j < intersections; j++)
 cout << roadMatrix[i][j] << " ";
 cout << endl;
 }
} void Graph::resetVisited() {
 for (int i = 0; i < intersections; i++)
 visited[i] = false;
}
// Recursive DFS
void Graph::exploreRoadNetwork(int location) {
 visited[location] = true;
 cout << location << " ";
 for (int i = 0; i < intersections; i++) {
 if (roadMatrix[location][i] == 1 && !visited[i])
 exploreRoadNetwork(i);
 }
}
// Explore every area, including disconnected ones
void Graph::exploreAll() {
 int part = 1;
 for (int i = 0; i < intersections; i++) {
 if (!visited[i]) {
 cout << "Area " << part++ << ": ";
 exploreRoadNetwork(i);
 cout << endl;
 }
 }
}
int main() {
 Graph cityRoad;
 int choice, start; cityRoad.createRoadNetwork();
 cityRoad.displayGraph();
 do {
 cout << "\n1. Explore from a starting intersection (DFS)"
 << "\n2. Explore all areas of the city"
 << "\n3. Exit"
 << "\nEnter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter starting intersection: ";
 cin >> start;
 if (start < 0 || start >= 20) {
 cout << "Invalid intersection!\n";
 break;
 }
 cityRoad.resetVisited();
 cout << "Locations visited: ";
 cityRoad.exploreRoadNetwork(start);
 cout << endl;
 break;
 case 2:
 cityRoad.resetVisited();
 cityRoad.exploreAll();
 break;
 case 3:
 cout << "Exiting...\n";
 break; default:
 cout << "Invalid Choice\n";
 }
 } while (choice != 3);
 return 0;
}
