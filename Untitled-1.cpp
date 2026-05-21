#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readChapterFromFile(string filename) {
    ifstream file(filename);
    string line;
    
    if (file.is_open()) {
        cout << "\n\033[36m--- Content of " << filename << " ---\033[0m\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        cout << "\033[36m------------------------------------\033[0m\n";
    } else {
        cout << "\033[31mError: Could not open '" << filename << "'. Please ensure the text file exists in the directory.\033[0m\n";
    }
}

void showHistorySection() {
    cout << "\n\033[33m=== History and Evolution of C++ ===\033[0m\n";
    cout << "1. Early Origins: Fortran, Algol 60, CPL, BCPL.\n";
    cout << "2. Creation of 'C' by Dennis Ritchie.\n";
    cout << "3. Bjarne Stroustrup created 'C with Classes' which evolved into C++.\n";
    cout << "4. Influences: Simula 67 (for objects) and C (for speed).\n";
}

void learnCppSection() {
    int choice;
    do {
        cout << "\n\033[32m=== Learn C++ Concepts ===\033[0m\n";
        cout << "[1] Data Types\n";
        cout << "[2] Control Flow\n";
        cout << "[3] Loops\n";
        cout << "[4] Arrays\n";
        cout << "[5] File Streams\n";
        cout << "[6] Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                readChapterFromFile("datatypes.txt"); 
                break;
            case 2: 
                readChapterFromFile("controlflow.txt"); 
                break;
            case 3: 
                readChapterFromFile("loops.txt"); 
                break;
            case 4: 
                readChapterFromFile("arrays.txt"); 
                break;
            case 5: 
                readChapterFromFile("filestreams.txt"); 
                break;
            case 6: 
                cout << "Returning to Main Menu...\n"; 
                break;
            default: 
                cout << "\033[31mInvalid choice! Please try again.\033[0m\n";
        }
    } while (choice != 6);
}

int main() {
    int mainChoice;

    do {
        cout << "\n\033[35m=== Foundations and History of C++ System ===\033[0m\n";
        cout << "[1] View the History of C++\n";
        cout << "[2] Learn about C++ Concepts\n";
        cout << "[3] Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                showHistorySection();
                break;
            case 2:
                learnCppSection();
                break;
            case 3:
                cout << "\033[33mExiting the program. Goodbye!\033[0m\n";
                break;
            default:
                cout << "\033[31mInvalid choice! Please try again.\033[0m\n";
        }
    } while (mainChoice != 3);

    return 0;
}