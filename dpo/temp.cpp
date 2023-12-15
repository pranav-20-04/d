#include <iostream>
using namespace std;

class node {
public:
    int data;
    int lth, rth;
    node *left, *right;
};

class thread {
private:
    node *tp;
    node *New, *root;

public:
    thread() { root = NULL; }
    void create();
    void insert(node *, node *);
    void display();
    void inorder(node *, node *);
    void preorder(node *, node *);
};

void thread::create() {
    // Same as before
    // ...
}

void thread::insert(node *root, node *New) {
    // Same as before
    // ...
}

void thread::display() {
    if (root == NULL)
        cout << "\nTree not created";
    else {
        cout << "\nInorder Traversal..";
        inorder(root, tp);
        cout << "\nPreorder Traversal..";
        preorder(root, tp);
    }
}

void thread::inorder(node *temp, node *tp) {
    // Same as before
    // ...
}

void thread::preorder(node *temp, node *tp) {
    // Same as before
    // ...
}

int main() {
    // Same as before
    // ...
}
