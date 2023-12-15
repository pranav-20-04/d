#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool isThreaded;

    Node(int val) {
        data = val;
        left = right = nullptr;
        isThreaded = false;
    }
};

Node* createThreaded(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* dummy = new Node(-1); // Dummy node to handle the case of the first node's predecessor
    dummy->right = root;
    dummy->isThreaded = true;

    Node* prev = dummy;

    // Perform an in-order traversal and create threads
    Node* current = root;
    while (current != nullptr) {
        if (current->left != nullptr) {
            prev = current->left;
            while (prev->right != nullptr && !prev->isThreaded)
                prev = prev->right;

            prev->right = current;
            prev->isThreaded = true;
        }

        if (current->right != nullptr && !current->isThreaded)
            current = current->right;
        else {
            current = current->right;
            prev = current;
        }
    }

    return dummy;
}

void preOrderTraversal(Node* root) {
    while (root != nullptr) {
        cout << root->data << " ";

        // Move to the left child
        if (root->left != nullptr)
            root = root->left;
        else if (root->right != nullptr)
            root = root->right;
        else {
            while (root != nullptr && root->isThreaded)
                root = root->right;

            if (root != nullptr)
                root = root->right;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Convert the binary tree to a threaded binary tree
    Node* threadedRoot = createThreaded(root);

    cout << "Pre-order traversal of the threaded binary tree: ";
    preOrderTraversal(threadedRoot);

    return 0;
}
