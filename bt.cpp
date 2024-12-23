#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int d) : data(d), right(nullptr), left(nullptr) {}
};

// Hardcoded input for the binary tree
Node* createTree() {
    Node* root = new Node(1); // Root node
    root->left = new Node(2); // Left child of root
    root->right = new Node(3); // Right child of root
    root->left->left = new Node(4); // Left child of node 2
    root->left->right = new Node(5); // Right child of node 2
    root->right->left = new Node(6); // Left child of node 3
    root->right->right = new Node(7); // Right child of node 3
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

      int n=q.size();
      for(int i=0;i<n;i++)
      {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
      }
      cout<<endl;
    }
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        s.push(temp);
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }

    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}

void InOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left); // Fix: call PreOrderTraversal instead of InOrderTraversal
    PreOrderTraversal(root->right); // Fix: call PreOrderTraversal instead of InOrderTraversal
}

int main() {
    Node* root = createTree(); // Using hardcoded tree creation

    cout << "Reverse Level Order Traversal: ";
    reverseLevelOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    InOrderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal: ";
    PreOrderTraversal(root);
    cout << endl;


    cout<<"Level Order:";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}
