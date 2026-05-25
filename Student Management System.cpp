#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

Student students[100];
int studentCount = 0;

void addStudent() {
    cout << "Enter Student ID: ";
    cin >> students[studentCount].id;
    
    cout << "Enter Name: ";
    cin >> students[studentCount].name;
    
    cout << "Enter Age: ";
    cin >> students[studentCount].age;
    
    cout << "Enter Course: ";
    cin >> students[studentCount].course;

    studentCount++;
}

void displayStudents() {
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << " | Name: " << students[i].name << " | Age: " << students[i].age << " | Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            cout << "Name: " << students[i].name << " | Age: " << students[i].age << " | Course: " << students[i].course << endl;
        }
    }
}

void updateStudent() {
    int updateID;
    cout << "Enter Student ID to update: ";
    cin >> updateID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == updateID) {
            cout << "Enter New Name: ";
            cin >> students[i].name;
            
            cout << "Enter New Age: ";
            cin >> students[i].age;
            
            cout << "Enter New Course: ";
            cin >> students[i].course;
        }
    }
}

void deleteStudent() {
    int deleteID;
    cout << "Enter Student ID to delete: ";
    cin >> deleteID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteID) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            break;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add a Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search for a Student by ID\n";
        cout << "4. Update Student Information\n";
        cout << "5. Delete a Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            displayStudents();
        } else if (choice == 3) {
            searchStudent();
        } else if (choice == 4) {
            updateStudent();
        } else if (choice == 5) {
            deleteStudent();
        }

    } while (choice != 6);

    return 0;
}