#include <iostream>


using namespace std;


int search(int arr[], int len, int lookup) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == lookup) {
			return i;
		}
	}

	return -1;
}

int main() {
	// int numbers[] = {
	// 	1, 5, 2, 9, 10, 22, 5, 7, 6, 0,
	// 	-55, 33, 59, 3,
	// };
	//
	// int len = sizeof(numbers) / sizeof(numbers[0]);

	const int max_nums = 20;
	int numbers[max_nums];

	int len;

	cout << "Enter the size of array: ";
	cin >> len;

	cout << "Enter values: ";

	
	for (int i = 0; i < len; i++) {
		cin >> numbers[i];
	}

	int lookup;

	cout << "Enter a value to lookup: ";
	cin >> lookup;

	int pos = search(numbers, len, lookup);

	if (pos == -1) {
		cout << "not found\n";
	} else {
		cout << "found at " << pos << "\n";
	}
}

