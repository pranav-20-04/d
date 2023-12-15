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
    cout << "\n4. Exit";
    cout << "\nEnter option : ";
    cin >> op;
    switch (op) {
    case 1:
      if (obj.isFull()) {
        cout << "\nCan't insert....Queue Overflow!!!";
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
      exit(0);
      break;
    }
  }
  return 0;
}



/*    Set the front and rear pointers to -1 initially, indicating an empty queue.

Enqueue (Insertion):

    Check if the queue is full. To check if the queue is full:
        If (rear + 1) % size == front, the queue is full.
    If the queue is not full:
        Increment the rear pointer by 1 using (rear + 1) % size to wrap around the circular queue.
        Place the new element at the position indicated by the rear pointer.
        If it's the first element, set the front pointer to 0.

Dequeue (Deletion):

    Check if the queue is empty. To check if the queue is empty:
        If front == -1, the queue is empty.
    If the queue is not empty:
        Output the element at the front.
        Increment the front pointer by 1 using (front + 1) % size to wrap around the circular queue.
        If after dequeuing, front becomes equal to rear, set both front and rear to -1 to indicate an empty queue.

Display:

    Start from the front pointer and iterate through the queue elements using a loop until reaching the rear pointer.
    Output each element at the current position.*/