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
