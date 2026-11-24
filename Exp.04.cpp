#include <iostream>
using namespace std;
struct Node {
int data;
Node *left;
Node *right;
Node(int value) {
data = value;
left = right = NULL;
}
};
// Create a binary tree recursively.
// Enter -1 when there is no node.
Node* createTree() {
int value;
cin >> value;
if (value == -1)
return NULL;
Node* newNode = new Node(value);
cout << "Enter left child of " << value << ": ";
newNode->left = createTree();
cout << "Enter right child of " << value << ": ";
newNode->right = createTree();
return newNode;
} // Inorder: Left -> Root -> Right
void inorder(Node* root) {
if (root == NULL)
return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}
// Preorder: Root -> Left -> Right
void preorder(Node* root) {
if (root == NULL)
return;
cout << root->data << " ";
preorder(root->left);
preorder(root->right);
}
// Postorder: Left -> Right -> Root
void postorder(Node* root) {
if (root == NULL)
return;
postorder(root->left);
postorder(root->right);
cout << root->data << " ";
}
int main() {
cout << "Create Binary Tree\n";
cout << "Enter root value: "; Node* root = createTree();
cout << "\nInorder Traversal: ";
inorder(root);
cout << "\nPreorder Traversal: ";
preorder(root);
cout << "\nPostorder Traversal: ";
postorder(root);
cout << endl;
return 0;
}
