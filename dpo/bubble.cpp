#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int main() {
    const int numStudents = 3; 
    Student database[numStudents] = {
        {102, "Pranav", 10},
        {103, "Sushant", 10},
        {101, "Vaibhav", 10}
    };

    cout << "Before Sorting:" << endl;
    cout << "Roll No\tName\tSGPA" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << database[i].rollNo << "\t" << database[i].name << "\t" << database[i].sgpa << endl;
    }

   
    bubbleSort(database, numStudents);

    cout << "\nAfter Sorting (Roll Call List - Ascending Order):" << endl;
    cout << "Roll No\tName\tSGPA" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << database[i].rollNo << "\t" << database[i].name << "\t" << database[i].sgpa << endl;
    }

    return 0;
}
