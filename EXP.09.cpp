#include <iostream>
using namespace std;
int main()
{
 int n;
 int graph[20][20];
 int visited[20];
 int u, v, i, j;
 int edges = 0;
 int totalCost = 0;
 cout << "\n Enter number of substations: ";
 cin >> n;
 cout << "\n Enter adjacency matrix (0 means no direct wire):";
 cout << "\n Example: for 3 substations, enter 3 x 3 matrix";
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 cout << "\n Enter cost from substation " << i << " to substation " << j << " : ";
 cin >> graph[i][j];
 }
 } for (i = 0; i < n; i++)
 {
 visited[i] = 0;
 }
 visited[0] = 1;
 cout << "\n Minimum Spanning Tree connections are:";
 while (edges < n - 1)
 {
 int min = 9999;
 u = 0;
 v = 0;
 for (i = 0; i < n; i++)
 {
 if (visited[i] == 1)
 {
 for (j = 0; j < n; j++)
 {
 if (visited[j] == 0 && graph[i][j] != 0)
 {
 if (graph[i][j] < min)
 {
 min = graph[i][j];
 u = i;
 v = j;
 }
 }
 }
 }
 }
 visited[v] = 1; edges++;
 totalCost = totalCost + min;
 cout << "\n Substation " << u << " ---- Substation " << v << " Cost: " << min;
 }
 cout << "\n\n Total minimum wiring cost: " << totalCost;
 cout << "\n";
 return 0;
}

Part B
#include <iostream>
using namespace std;
int main()
{
 int n, graph[20][20], visited[20];
 int i, j, u, v, edges = 0, total = 0;
 cout << "\n Enter number of substations: ";
 cin >> n;
 cout << "\n Enter adjacency matrix (0 = no direct wire):\n";
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 cin >> graph[i][j];
 for (i = 0; i < n; i++)
 visited[i] = 0;
 visited[0] = 1;
 cout << "\n Minimum Spanning Tree connections are:";
 while (edges < n - 1)
 {
 int min = 9999;
 u = v = 0;
 for (i = 0; i < n; i++)
 if (visited[i]) for (j = 0; j < n; j++)
 if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min)
 {
 min = graph[i][j];
 u = i;
 v = j;
 }
 visited[v] = 1;
 edges++;
 total += min;
 cout << "\n Substation " << u << " ---- Substation " << v << " Cost: " << min;
 }
 cout << "\n\n Total minimum wiring cost: " << total << "\n";
 return 0;
}

