#include <iostream>

using namespace std;

int search(int arr[], int len, int target) {

	int lo = 0, hi = len - 1;

	while (lo < hi) {
		int mid = ((hi - lo) / 2) + lo;

		if (target < mid) {
			hi = mid;
		} else if (target > mid) {
			lo = mid; } else {
			return mid;
		}
	}


	return -1;
}

int main() {
	int numbers[] = {
		0, 1, 2, 3, 4, 5, 6,
	};

	int len = sizeof(numbers) / sizeof(numbers[0]);

	int target;

	cout << "enter number to search: ";
	cin >> target;

	int pos = search(numbers, len, target);

	if (pos != -1) {
		cout << "found at " << pos << "\n";
	} else {
		cout << "not found\n";
	}
}
