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
  node *New, *root, *temp, *parent;

public:
  thread() { root = NULL; }
  void create();
  void insert(node *, node *);
  void display();
};
void thread::create() {
  New = new node;
  New->left = NULL;
  New->right = NULL;
  New->lth = 0;
  New->rth = 0;
  cout << "\nEnter an element: ";
  cin >> New->data;
  if (root == NULL) {
    root = New;
    tp = new node;
    tp->data = -999;
    tp->left = root;
    root->left = tp;
    root->right = tp;
  } else
    insert(root, New);
}
void thread::insert(node *root, node *New) {
  if (New->data < root->data) {
    if (root->lth == 0) {
      New->left = root->left;
      New->right = root;
      root->left = New;
      root->lth = 1;
    } else
      insert(root->left, New);
  }
  if (New->data > root->data) {
    if (root->rth == 0) {
      New->right = root->right;
      New->left = root;
      root->right = New;
      root->rth = 1;
    } else
      insert(root->right, New);
  }
}
void thread::display() {
  void inorder(node *, node *);
  void preorder(node *, node *);
  if (root == NULL)
    cout << "\nTree not created";
  else {
    cout << "\nInorder Traversal..";
    inorder(root, tp);
    cout << "\nPreorder Traversal..";
    preorder(root, tp);
  }
}
void inorder(node *temp, node *tp) {
  while (temp != tp) {
    while (temp->lth == 1)
      temp = temp->left;
    cout << " " << temp->data;
    while (temp->rth == 0) {
      temp = temp->right;
      if (temp == tp)
        return;
      cout << "\t" << temp->data;
    }
    temp = temp->right;
  }
}
void preorder(node *temp, node *tp) {
  int flag = 0;
  while (temp != tp) {
    if (flag == 0)
      cout << " " << temp->data;
    if (temp->lth == 1 && flag == 0)
      temp = temp->left;
    else {
      while (1) {
        if (temp->rth == 1) {
          flag = 0;
          temp = temp->right;
          break;
        } else {
          if (temp != tp) {
            flag = 1;
            temp = temp->right;
            break;
          }
        }
      }
    }
  }
}
int main() {
  int ch;
  int ans;
  thread th;
  do {
    cout << "\nThreaded Binary Tree";
    cout << "\nPress:\n1.To create\n2.To display: ";
    cin >> ch;
    switch (ch) {
    case 1:
      do {
        th.create();
        cout << "Press 1 to continue entering: ";
        cin >> ans;
      } while (ans == 1);
      break;
    case 2:
      th.display();
      break;
    }
    cout << "Do you want to see choices?(1)";
    cin >> ans;
  } while (ans == 1);
  return 0;
}
