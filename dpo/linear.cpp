#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

int main() {
    const int totalStudents = 15;
    Student students[totalStudents] = {
        {1, "Pranav", 10},
        {2, "Khushi", 10},
        {3, "RITIK", 3.5},
        {4, "Sarah", 4.0},
        {5, "Aditi", 3.7}
    };

    float searchSGPA;
    cout << "Enter SGPA to search: ";
    cin >> searchSGPA;

    bool found = false;
    cout << "Students with SGPA " << searchSGPA << ":" << endl;
    for (int i = 0; i < totalStudents; ++i) {
        if (students[i].sgpa == searchSGPA) {
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students found with SGPA " << searchSGPA << endl;
    }

    return 0;
}
