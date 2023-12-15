#include <iostream>

using namespace std;

void bubble_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main() {
	int arr[] = {4, 5, 2, 8, 5, 22, 94, 1, 44, 93};
	int len = sizeof(arr) / sizeof(arr[1]);


	bubble_sort(arr, len);

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

