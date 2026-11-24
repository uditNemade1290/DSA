#include <iostream>
#include <vector>
using namespace std;
class SocialNetworkGraph {
private:
 int users; // Number of vertices/users
 vector<vector<int>> adjacencyList; // Adjacency list representation
public:
 // Algorithm step 1 to 6: Read inputs and construct graph
 void CreateGraph() {
 cout << "Enter the number of users: ";
 cin >> users;
 // Initialize empty adjacency list for each user
 adjacencyList.resize(users);
 int friendships;
 cout << "Enter the number of friendships (edges): ";
 cin >> friendships;
 cout << "Enter each friendship pair (user1 user2, using 0 to " << users - 1 << "):\n";
 for (int i = 0; i < friendships; i++) {
 int user1, user2; cin >> user1 >> user2;
 // Mutual friendship (undirected graph)
 adjacencyList[user1].push_back(user2);
 adjacencyList[user2].push_back(user1);
 }
 cout << "\nGraph created successfully!\n";
 }
 // Display Adjacency List representation
 void DisplayGraph() {
 if (users == 0) {
 cout << "Graph is empty. Please create the graph first.\n";
 return;
 }
 cout << "\nAdjacency List Representation:\n";
 for (int i = 0; i < users; i++) {
 cout << "User " << i << " -> ";
 for (int neighbor : adjacencyList[i]) {
 cout << neighbor << " ";
 }
 cout << "\n";
 }
 }
};
int main() { SocialNetworkGraph network;
 int choice = 0;
 do {
 cout << "\n== PART A: GRAPH CREATION MENU ==\n";
 cout << "1. Create Graph\n";
 cout << "2. Display Adjacency List\n";
 cout << "3. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 network.CreateGraph();
 break;
 case 2:
 network.DisplayGraph();
 break;
 case 3:
 cout << "Exiting Part A program.\n";
 break;
 default:
 cout << "Invalid choice. Try again.\n";
 }
 } while (choice != 3);
 return 0;
           }

PART B

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class SocialNetworkBFS {
private:
 int users;
 vector<vector<int>> socialList;
public: void CreateSocialNetwork() {
 cout << "Enter the total number of users: ";
 cin >> users;
 socialList.resize(users);
 int friendships;
 cout << "Enter the number of friendships: ";
 cin >> friendships;
 cout << "Enter friendship connections (user1 user2):\n";
 for (int i = 0; i < friendships; i++) {
 int u1, u2;
 cin >> u1 >> u2;
 socialList[u1].push_back(u2);
 socialList[u2].push_back(u1);
 }
 cout << "\nSocial network graph initialized.\n";
 }
 // BFS implementation to traverse network level by level
 void ExploreUsers(int startUser) {
 if (startUser < 0 || startUser >= users) {
 cout << "Invalid starting user ID!\n";
 return;
 }
 // Step 1: Initialize visited array vector<bool> visited(users, false);
 // Step 2: Create queue
 queue<int> q;
 // Step 3 & 4: Mark starting user as visited and enqueue
 visited[startUser] = true;
 q.push(startUser);
 cout << "\nUsers connected level by level starting from User " << startUser << ":\n";
 // Step 5: Process queue until empty
 while (!q.empty()) {
 // Step 6 & 7: Dequeue and print current user
 int currentUser = q.front();
 q.pop();
 cout << currentUser << " ";
 // Step 8: Check all friends of current user
 for (int friendUser : socialList[currentUser]) {
 // Step 9: If friend is not visited
 if (!visited[friendUser]) {
 // Step 10 & 11: Mark visited and enqueue
 visited[friendUser] = true;
 q.push(friendUser);
 }
 } }
 cout << "\n";
 }
};
int main() {
 SocialNetworkBFS network;
 int choice = 0;
 do {
 cout << "\n== PART B: SOCIAL NETWORK BFS MENU ==\n";
 cout << "1. Create Social Network\n";
 cout << "2. Explore Users via BFS\n";
 cout << "3. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 network.CreateSocialNetwork();
 break;
 case 2: {
 int startUser;
 cout << "Enter starting user for BFS traversal: ";
 cin >> startUser;
 network.ExploreUsers(startUser);
 break;
 } case 3:
 cout << "Exiting Part B program.\n";
 break;
 default:
 cout << "Invalid choice. Try again.\n";
 }
 } while (choice != 3);
 return 0;
}
