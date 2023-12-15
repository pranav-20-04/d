#include <iostream>
#include <math.h>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};
class LinkedList {
private:
  Node *head;

public:
  LinkedList() { this->head = NULL; }
  void push(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
  void pop() {
    if (head == NULL) {
      return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  int precedence(char c) {
    if (c == '^') {
      return 3;
    } else if (c == '*' || c == '/') {
      return 2;
    } else if (c == '+' || c == '-') {
      return 1;
    } else {
      return -1;
    }
  }
  string infixToPostfix(string s) {
    string result;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9')) {
        result += c;
      } else if (c == '(') {
        push('(');
      } else if (c == ')') {
        while (head != NULL && head->data != '(') {
          result += head->data;
          pop();
        }
        if (head != NULL) {
          pop(); // Remove the '(' from the stack
        }
      } else {
        while (head != NULL && precedence(c) <= precedence(head->data)) {
          result += head->data;
          pop();
        }
        push(c);
      }
    }
    while (head != NULL) {
      result += head->data;
      pop();
    }
    return result;
  }
  string infixToPrefix(string s) {
    string result;
    string reversed1;
    string reversed2;
    for (int i = s.length() - 1; i >= 0; i--) {
      reversed1 += s[i];
    }
    string temp;
    for (int i = 0; i < reversed1.length(); i++) {
      char c = reversed1[i];
      if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9')) {
        temp += c;
      } else if (c == ')') {
        push(')');
      } else if (c == '(') {
        while (head != NULL && head->data != ')') {
          temp += head->data;
          pop();
        }
        if (head != NULL) {
          pop(); // Remove the '(' from the stack
        }
      } else {
        while (head != NULL && precedence(c) <= precedence(head->data)) {
          temp += head->data;
          pop();
        }
        push(c);
      }
    }
    while (head != NULL) {
      temp += head->data;
      pop();
    }
    for (int i = temp.length() - 1; i >= 0; i--) {
      reversed2 += temp[i];
    }
    return reversed2;
  }
  int PostFixEvaluation(string s) {
    int result;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        push(c - '0');
      } else {
        int a = head->data;
        pop();
        int b = head->data;
        pop();
        switch (c) {
        case '+':
          push(a + b);
          break;
        case '-':
          push(a - b);
          break;
        case '*':
          push(a * b);
          break;
        case '/':
          push(a / b);
          break;
        case '^':
          push(pow(a, b));
          break;
        }
      }
    }
    result = head->data;
    return result;
  }
  int PrefixEvaluation(string s) {
    int tempo;
    for (int i = s.length(); i <= 0; i--) {
      char c = s[i];
      if (c >= '0' && c <= '9') {
        push(c - '0');
      } else {
        int a = head->data;
        pop();
        int b = head->data;
        pop();
        switch (c) {
        case '+':
          push(a + b);
          break;
        case '-':
          push(a - b);
          break;
        case '*':
          push(a * b);
          break;
        case '/':
          push(a / b);
          break;
        case '^':
          push(pow(a, b));
          break;
        }
      }
    }
    tempo = head->data;
    return tempo;
  }
};
int main() {
  LinkedList st;
  string infix = "(1+2*3)/7";
  cout << "Infix Expression is : " << infix << endl;
  string postfix = st.infixToPostfix(infix);
  cout << "PostFix Expression is : " << postfix << endl;
  string prefix = st.infixToPrefix(infix);
  cout << "prefix expression is : " << prefix << endl;
  int Evaluated1 = st.PostFixEvaluation(postfix);
  cout << "Evaluation of PostFix Expression is : " << Evaluated1 << endl;
  int Evaluated2 = st.PrefixEvaluation(prefix);
  cout << "Evaluation of Prefix Expression is : " << Evaluated2 << endl;
  return 0;
}
