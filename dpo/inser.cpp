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


/*    Start the algorithm.
    Begin an outer loop from i = 1 to i < n.
        This loop traverses through each student from the second student to the last.
    Inside the loop:
        Set current as the student at the current position (students[i]).
        Set j as the position just before i (j = i - 1).
        Start an inner loop:
            Continue until j >= 0 and students[j].name is lexicographically greater than current.name.
                (Here, students[j].name refers to the name of the student at position j, and current.name is the name of the student at position i).
            If the condition is true:
                Move the student at position j one place ahead in the array (students[j + 1] = students[j]).
                Decrement j.
        Insert current at position j + 1 in the sorted sequence (students[j + 1] = current).
    End the inner loop.
    End the outer loop.
    End the algorithm.*/







