#include <iostream>
#include <stack>
using namespace std;
class Node {
public:
int data;
Node *left;
Node *right;
Node(int value) {
data = value;
left = NULL;
right = NULL;
}
};
class BST {
private:
Node *root;
Node* insert(Node *root, int value) {
if (root == NULL) {
return new Node(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
}
else if (value > root->data) {
root->right = insert(root->right, value);
}
else {
cout << "Duplicate value not inserted.\n";
} return root;
}
public:
BST() {
root = NULL;
}
void createBST() {
int n, value;
cout << "Enter number of nodes: ";
cin >> n;
cout << "Enter node values:\n";
for (int i = 1; i <= n; i++) {
cin >> value;
root = insert(root, value);
}
}
//-------------------------------------------------
// Non-Recursive Inorder Traversal
//-------------------------------------------------
void inorderNonRecursive() {
stack<Node*> S;
Node *current = root;
cout << "Non-Recursive Inorder Traversal: ";
while (current != NULL || !S.empty()) {
while (current != NULL) {
S.push(current);
current = current->left;
}
current = S.top();
S.pop();
cout << current->data << " "; current = current->right;
}
cout << endl;
}
//-------------------------------------------------
// Non-Recursive Preorder Traversal
//-------------------------------------------------
void preorderNonRecursive() {
if (root == NULL) {
return;
}
stack<Node*> S;
S.push(root);
cout << "Non-Recursive Preorder Traversal: ";
while (!S.empty()) {
Node *current = S.top();
S.pop();
cout << current->data << " ";
// Push right child first
if (current->right != NULL)
S.push(current->right);
// Push left child next
if (current->left != NULL)
S.push(current->left);
}
cout << endl;
}
};
int main() {
BST tree; // Create BST
tree.createBST();
// Traversals
tree.inorderNonRecursive();
tree.preorderNonRecursive();
return 0;
}
