#include <iostream>

#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; 
        } else {
            Node* temp = top;
            char popped = temp->data;
            top = top->next;
            delete temp;
            return popped;
        }
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        } else {
            return top->data;
        }
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix;
    
    for (char& c : infix) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Pop '('
        } else {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }
    
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
