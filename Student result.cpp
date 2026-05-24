#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double calculateTotal(double m1, double m2, double m3) {
    return m1 + m2 + m3;
}

string getStatus(double average) {
    if (average >= 50) {
        return "Passed";
    } else {
        return "Failed";
    }
}

int main() {
    bool addMore = true;

    while (addMore) {
        string name;
        double mark1, mark2, mark3;

        cout << "Enter student's name: ";
        getline(cin >> ws, name);

        cout << "Enter marks for Subject 1: ";
        cin >> mark1;

        cout << "Enter marks for Subject 2: ";
        cin >> mark2;

        cout << "Enter marks for Subject 3: ";
        cin >> mark3;

        double total = calculateTotal(mark1, mark2, mark3);
        double average = total / 3.0;

        cout << "\n--- Student Result ---\n";
        cout << "Name: " << name << "\n";
        cout << "Total Marks: " << total << "\n";
        cout << "Average: " << fixed << setprecision(2) << average << "\n";
        cout << "Status: " << getStatus(average) << "\n";
        cout << "----------------------\n\n";

        cout << "Do you want to enter another student? (y/n): ";
        string choice;
        cin >> choice;
        
        if (choice != "y" && choice != "Y") {
            addMore = false;
        }
    }
     return 0;
}