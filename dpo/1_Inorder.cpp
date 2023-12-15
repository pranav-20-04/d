#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool isThreaded;

    Node(int value) {
        data = value;
        left = right = nullptr;
        isThreaded = false;
    }
};

Node* createThreaded(Node* root) {
    if (!root)
        return nullptr;

    Node* prev = nullptr;
    Node* current = root;

    while (current) {
        if (!current->left) {
            if (prev && !prev->right) {
                prev->right = current;
                prev->isThreaded = true;
            }
            prev = current;
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (!predecessor->right) {
                predecessor->right = current;
                predecessor->isThreaded = true;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                prev = current;
                current = current->right;
            }
        }
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (!root)
        return;

    Node* current = root;
    while (current) {
        if (!current->left) {
            cout << current->data << " ";
            current = current->right;
        } else {
            Node* predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right) {
                cout << current->data << " ";
                predecessor->right = nullptr;
                current = current->right;
            } else {
                predecessor->right = current;
                current = current->left;
            }
        }
    }
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    Node* threadedRoot = createThreaded(root);

    cout << "In-order traversal of threaded binary tree: ";
    inOrderTraversal(threadedRoot);
    

    return 0;
}
