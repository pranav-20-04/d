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











/*    Initialize a structure representing a student with fields: Roll No, Name, SGPA.
    1.Create an array of structures to hold student records, ensuring it can store at least 15 records.

    2. Populate the database with student records, including Roll No, Name, and SGPA for each student.

    Implement the Bubble Sort algorithm to arrange the list of students based on their Roll Numbers in ascending order.

    Start a loop from the first record to the second last record (0 to n-1) in the database.

    Within the loop, start another loop from the second record to the last record (i to n) in the database.

    Compare the Roll Numbers of adjacent student records.

    If the Roll Number of the current record is greater than the Roll Number of the next record, swap their positions in the array.

    Continue this process until the entire array has been iterated over and the highest Roll Number has been placed at the end.

    Repeat steps 5-9 until the entire list is sorted in ascending order based on Roll Numbers.

    Display the roll call list, showing Roll Numbers, corresponding Names, and SGPA for each student, now arranged in ascending order based on Roll Numbers.*/
    
