#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

int partition(Student students[], int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (students[j].sgpa >= pivot) {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(Student students[], int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);

        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

void printTopTen(Student students[], int n) {
    quickSort(students, 0, n - 1);
    
    cout << "Top Ten Students based on SGPA:" << endl;
    for (int i = 0; i < min(10, n); i++) {
        cout << "Name: " << students[i].name << "\t Roll No: " << students[i].rollNo << "\t SGPA: " << students[i].sgpa << endl;
    }
}

int main() {
    const int NumS = 15; 
    Student database[NumS] = {
        
        // Example:
        {101, "Pranav", 10},
        {102, "Vaibha", 3.5},
        {103, "Vaibh", 9.5},
        {104, "Vaib", 4.4},
        {105, "Vai", 6.6},
        {106, "Va", 6.3},
        {107, "Sus", 7.5},
        {108, "Sush", 7.9},
        {109, "Susha", 7.5},
        {110, "Sushan", 7.4},
        
    };

    printTopTen(database, NumS);

    return 0;
}






/*    Define a Student structure/class containing at least two fields: name and marks to store student information.

    Implement the Quick Sort algorithm to sort the list of students based on their marks in descending order.

    Quick Sort Algorithm:
        Choose a pivot element (usually the last element in the list).
        Partition the list such that elements smaller than the pivot are placed to its left and larger elements to its right.
        Recursively apply the same process to the sublists on the left and right sides of the pivot until the entire list is sorted.

    After sorting the list using Quick Sort, the top ten students will be the first ten elements in the sorted list (since we sorted in descending order).

    Display the top ten students' names along with their marks to show the top performers in the class.

Pseudocode for Quick Sort Algorithm:

plaintext

Algorithm QuickSort(A, low, high):
    if low < high:
        pivotIndex = Partition(A, low, high) // Partition the array
        QuickSort(A, low, pivotIndex - 1)   // Sort the left subarray
        QuickSort(A, pivotIndex + 1, high)  // Sort the right subarray

Algorithm Partition(A, low, high):
    pivot = A[high] // Choose the pivot element (usually the last element)
    i = low - 1     // Initialize the index of smaller element

    for j = low to high - 1:
        if A[j] >= pivot:
            i++
            Swap A[i] with A[j]

    Swap A[i + 1] with A[high]
    return i + 1*/
