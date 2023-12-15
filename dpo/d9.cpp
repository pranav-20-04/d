#include <iostream>
using namespace std;
void MaxHeapify(int Arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && Arr[l] > Arr[largest]) {
    largest = l;
  }
  if (r < n && Arr[r] > Arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(Arr[i], Arr[largest]);
    MaxHeapify(Arr, n, largest);
  }
}
void BuildMaxHeap(int Arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    MaxHeapify(Arr, n, i);
  }
}
void HeapSort(int Arr[], int n) {
  BuildMaxHeap(Arr, n);
  for (int i = n - 1; i > 0; i--) {
    swap(Arr[0], Arr[i]);
    MaxHeapify(Arr, i, 0);
  }
}
void Display(int Arr[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << Arr[i] << " ";
  }
  cout << "\n";
}
int main() {
  int n;
  cout << "How many elements you want to sort?: ";
  cin >> n;
  int *Arr = new int[n];
  cout << "Enter " << n << " Elements:\n";
  for (int i = 0; i < n; i++) {
    cin >> Arr[i];
  }
  HeapSort(Arr, n);
  cout << "\nSorted array is:\n";
  Display(Arr, n);
  delete[] Arr;
  return 0;
}
