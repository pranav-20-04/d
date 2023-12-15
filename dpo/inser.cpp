#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void insertionSort(Student arr[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].name > key.name) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int maxSize = 15;
    Student students[maxSize] = {
        {103, "Pranav", 10},
        {101, "Sushant", 10},
        {102, "Vaibhav", 10},
   
    };

    int numStudents = 10; 

    cout << "List of students before sorting:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Roll No: " << students[i].rollNo << "\tName: " << students[i].name << "\tSGPA: " << students[i].sgpa << endl;
    }

    insertionSort(students, numStudents);

    cout << "\nList of students after sorting alphabetically by name:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Roll No: " << students[i].rollNo << "\tName: " << students[i].name << "\tSGPA: " << students[i].sgpa << endl;
    }

    return 0;
}
