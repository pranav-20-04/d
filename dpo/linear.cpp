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



/*    Create a data structure to store student information including their SGPA (e.g., a class or a data structure with fields like name, roll number, SGPA).
    Read student information along with their SGPA.
    Define a function or method to search students by SGPA.
    Initialize an empty list/array to store students with the target SGPA.
    Iterate through the list of students.
    For each student:
        Check if the SGPA of the student matches the target SGPA.
        If it matches:
            Add the student's information to the list of students with the target SGPA.
    If the list of students with the target SGPA is empty:
        Display a message indicating no students with the given SGPA were found.
    If the list of students with the target SGPA is not empty:
        Display the list of students with their information, indicating they have the same SGPA.
    End.*/
