#include <iostream>
#include <queue>
using namespace std;
struct Node {
 int data;
 Node *left, *right;
};
Node* newNode(int v) {
 Node* n = new Node;
 n->data = v;
 n->left = n->right = NULL;
 return n;
}
Node* insert(Node* root, int v) {
 if (!root) return newNode(v);
 if (v < root->data)
 root->left = insert(root->left, v);
 else if (v > root->data)
 root->right = insert(root->right, v);
 else
 cout << "Duplicate Employee ID\n";
 return root;
}
Node* copyTree(Node* r) {
 if (!r) return NULL;
 Node* n = newNode(r->data);
 n->left = copyTree(r->left); n->right = copyTree(r->right);
 return n;
}
void levelOrder(Node* root) {
 if (!root) { cout << "Tree is Empty\n"; return; }
 queue<Node*> q;
 q.push(root);
 while (!q.empty()) {
 Node* t = q.front(); q.pop();
 cout << t->data << " ";
 if (t->left) q.push(t->left);
 if (t->right) q.push(t->right);
 }
 cout << endl;
}
int height(Node* r) {
 if (!r) return -1;
 return max(height(r->left), height(r->right)) + 1;
}
void printLeaves(Node* r) {
 if (!r) return;
 if (!r->left && !r->right) {
 cout << r->data << " ";
 return;
 }
 printLeaves(r->left);
 printLeaves(r->right);
} int main() {
 Node *root = NULL, *copy = NULL;
 int ch, n, v;
 do {
 cout << "\n=== Employee Database Analysis using BST ===\n"
 << "1. Insert Employee IDs\n"
 << "2. Display Original BST (Level Order)\n"
 << "3. Copy BST\n"
 << "4. Display Copied BST (Level Order)\n"
 << "5. Find Height of BST\n"
 << "6. Display Leaf Nodes\n"
 << "7. Exit\n"
 << "Choice: ";
 cin >> ch;
 switch (ch) {
 case 1:
 cout << "How many IDs? ";
 cin >> n;
 while (n--) {
 cout << "Employee ID: ";
 cin >> v;
 root = insert(root, v);
 }
 break;
 case 2:
 cout << "Original BST: ";
 levelOrder(root);
 break;
 case 3:
 copy = copyTree(root); cout << "BST Copied Successfully\n";
 break;
 case 4:
 cout << "Copied BST: ";
 levelOrder(copy);
 break;
 case 5:
 cout << "Height of BST = " << height(root) << endl;
 break;
 case 6:
 cout << "Leaf Nodes: ";
 printLeaves(root);
 cout << endl;
 break;
 case 7:
 cout << "Exiting Program...\n";
 break;
 default:
 cout << "Invalid Choice\n";
 }
 } while (ch != 7);
 return 0;
}

#part B

#include <iostream>
#include <queue>
using namespace std;
struct Node {
 int data;
 Node *left, *right;
};
Node* createNode(int id) {
 Node* n = new Node;
 n->data = id;
 n->left = n->right = NULL;
 return n;
}
// Insert employee ID into BST
Node* insert(Node* root, int id) {
 if (root == NULL) return createNode(id);
 if (id < root->data)
 root->left = insert(root->left, id);
 else if (id > root->data)
 root->right = insert(root->right, id);
 else
 cout << "Duplicate Employee ID " << id << " ignored\n";
 return root;
}
// Create new BST by copying the original Node* copyTree(Node* root) {
 if (root == NULL) return NULL;
 Node* n = createNode(root->data);
 n->left = copyTree(root->left);
 n->right = copyTree(root->right);
 return n;
}
// Level-wise display (one level per line)
void levelOrder(Node* root) {
 if (root == NULL) { cout << "Tree is Empty\n"; return; }
 queue<Node*> q;
 q.push(root);
 int level = 0;
 while (!q.empty()) {
 int count = q.size();
 cout << "Level " << level++ << ": ";
 while (count--) {
 Node* t = q.front(); q.pop();
 cout << t->data << " ";
 if (t->left) q.push(t->left);
 if (t->right) q.push(t->right);
 }
 cout << endl;
 }
}
// Height in edges (empty tree = -1)
int height(Node* root) {
 if (root == NULL) return -1;
 return max(height(root->left), height(root->right)) + 1; }
// Leaf nodes = employees with no subordinates
void printLeaves(Node* root) {
 if (root == NULL) return;
 if (root->left == NULL && root->right == NULL) {
 cout << root->data << " ";
 return;
 }
 printLeaves(root->left);
 printLeaves(root->right);
}
int main() {
 Node *root = NULL, *newTree = NULL;
 int choice, n, id;
 do {
 cout << "\n=====================================\n"
 << " Employee Database Analysis using BST\n"
 << "=====================================\n"
 << "1. Insert Employee IDs\n"
 << "2. Display Original BST (Level Order)\n"
 << "3. Copy BST (Create New BST)\n"
 << "4. Display New BST (Level Order)\n"
 << "5. Find Height of BST\n"
 << "6. Display Leaf Nodes\n"
 << "7. Exit\n"
 << "Enter choice: ";
 cin >> choice; switch (choice) {
 case 1:
 cout << "Enter number of employee IDs: ";
 cin >> n;
 for (int i = 0; i < n; i++) {
 cout << "Enter Employee ID: ";
 cin >> id;
 root = insert(root, id);
 }
 break;
 case 2:
 cout << "\nOriginal BST:\n";
 levelOrder(root);
 break;
 case 3:
 newTree = copyTree(root);
 cout << "BST Copied Successfully\n";
 break;
 case 4:
 cout << "\nNew BST:\n";
 levelOrder(newTree);
 break;
 case 5:
 cout << "Height of BST = " << height(root) << endl;
 break;
 case 6:
 cout << "Leaf Nodes (no subordinate records): ";
 printLeaves(root);
 cout << endl;
 break;
 case 7: cout << "Program Terminated\n";
 break;
 default:
 cout << "Invalid Choice\n";
 }
 } while (choice != 7);
 return 0;
}
