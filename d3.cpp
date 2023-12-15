#include <iostream>
#define MAX 5
using namespace std;
class CircleQueue {
  int queue[MAX], front, rear;

public:
  CircleQueue() {
    front = -1;
    rear = -1;
  }
  void EnQueue(int n) {
    if (isEmpty())
      front++;
    rear = (rear + 1) % MAX;
    queue[rear] = n;
  }
  void DeQueue() {
    cout << queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % MAX;
    }
  }
  bool isEmpty() {
    if (front == -1) {
      return true;
    } else {
      return false;
    }
  }
  bool isFull() {
    if ((rear + 1) % MAX == front) {
      return true;
    } else {
      return false;
    }
  }
  void Peek() { cout << "Elements at Front : " << queue[front]; }
  void display() {
    int i;
    if (front == -1) {
      cout << "\n Queue is Empty !!! ";
      return;
    }
    cout << "\nQueue : ";
    if (front <= rear) {
      for (i = front; i <= rear; i++) {
        cout << queue[i] << " ";
      }
    } else {
      for (i = front; i < MAX; i++) {
        cout << queue[i] << " ";
      }
      for (i = 0; i <= rear; i++) {
        cout << queue[i] << " ";
      }
    }
  }
};
int main() {
  int op, element;
  CircleQueue obj;
  while (1) {
    cout << "\n1. EnQueue";
    cout << "\n2. DeQueue";
    cout << "\n3. Display All Elements";
    cout << "\n4. Display Front Elements ";
    cout << "\n5. Exit";
    cout << "\nEnter option : ";
    cin >> op;
    switch (op) {
    case 1:
      if (obj.isFull()) {
        cout << "\nCan't insert....Queue Overflowe!!!";
        break;
      } else {
        cout << "\nEnter element to be inserted : ";
        cin >> element;
        obj.EnQueue(element);
        break;
      }
    case 2:
      if (obj.isEmpty()) {
        cout << "\nCan't Delete....Queue Underflow!!!";
        break;
      } else {
        cout << "\nDeleted element from queue : ", obj.DeQueue();
        break;
      }
    case 3:
      obj.display();
      break;
    case 4:
      if (obj.isEmpty()) {
        cout << "\nNo front element....Queue Empty!!!";
        break;
      } else {
        obj.Peek();
        break;
      }
    case 5:
      exit(0);
      break;
    }
  }
  return 0;
}























/*1. Initialization:

    Define a Circular Queue class that contains necessary data members and functions.
    Declare an array to store elements, front and rear pointers, and size variables.

2. Insertion (Enqueue) Operation:

    Check if the queue is full ((rear + 1) % maxSize == front).
        If full, display an overflow message.
        If not full:
            Increment rear circularly (rear = (rear + 1) % maxSize).
            Insert the new element at the rear position.
            If it's the first insertion, set front to 0.

3. Deletion (Dequeue) Operation:

    Check if the queue is empty (front == -1).
        If empty, display an underflow message.
        If not empty:
            Store the element to be removed.
            If front and rear are at the same position (i.e., only one element is present), reset front and rear to -1.
            Otherwise, increment front circularly (front = (front + 1) % maxSize).
            Return the stored element.

4. Display Operation:

    Check if the queue is empty (front == -1).
        If empty, display an empty queue message.
        If not empty:
            Initialize a temporary variable i with front value.
            Loop until i becomes equal to rear:
                Display the element at index i.
                Increment i circularly (i = (i + 1) % maxSize)*/
