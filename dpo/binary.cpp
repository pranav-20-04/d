#include <iostream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};


void searchStudentByName(Student students[], int n, string searchName) {
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (students[mid].name == searchName) {
            found = true;
            int index = mid;

            
            while (index >= 0 && students[index].name == searchName) {
                cout << "Roll No: " << students[index].rollNo << "\tName: " << students[index].name << "\tSGPA: " << students[index].sgpa << endl;
                index--;
            }
            index = mid + 1;
            while (index < n && students[index].name == searchName) {
                cout << "Roll No: " << students[index].rollNo << "\tName: " << students[index].name << "\tSGPA: " << students[index].sgpa << endl;
                index++;
            }
            break;
        } else if (students[mid].name < searchName) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Student with name '" << searchName << "' not found." << endl;
    }
}

int main() {
    const int MAX_STUDENTS = 15;
    Student students[MAX_STUDENTS] = {
        {101, "Hinata", 3.8},
        {102, "kagura", 3.5},
        {103, "ayura", 3.9},
        {104, "sakura", 3.6},
        {105, "Mai", 3.7},
        
    };

    int totalStudents = 5; 

    string searchName;
    cout << "Enter the name of the student to search: ";
    cin >> searchName;

   
    searchStudentByName(students, totalStudents, searchName);

    return 0;
}



/*    Initialize:
        Set left to 0 (start of the array)
        Set right to the last index of the array
        Set found flag to false

    Repeat Until left is Less Than or Equal to right:
        Calculate the mid index as the average of left and right

    Compare the Target Name:
        If the name at the mid index matches the target name:
            Print the record at the mid index
            Move mid to the left and search for more matches to the left of mid
            Set found flag to true

    Update Search Range:
        If the target name is less than the name at index mid, set right to mid - 1 (move to the left side)
        If the target name is greater than the name at index mid, set left to mid + 1 (move to the right side)

    Display Results:
        If found is still false after the loop:
            Print "No records found for the given name."*/