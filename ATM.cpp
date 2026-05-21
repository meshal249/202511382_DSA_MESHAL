#include <iostream>
#include <string>

using namespace std;

void checkBalance(int balance) {
    cout << "\033[32m\nCurrent Balance: " << balance << " FRW\033[0m\n";
}

int depositMoney(int balance, string history[], int &transCount) {
    int amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    balance += amount;
    
    cout << "\033[32m\nDeposit Successful\033[0m\n";
    cout << "New Balance: " << balance << " FRW\n";
    
    history[transCount] = "Deposited: " + to_string(amount) + " FRW";
    transCount++;
    
    return balance;
}

int withdrawMoney(int balance, string history[], int &transCount) {
    int amount;
    cout << "\nEnter amount to withdraw: ";
    cin >> amount;
    
    if (amount > balance) {
        cout << "\033[31m\nInsufficient Funds\033[0m\n";
    } else {
        balance -= amount;
        cout << "\033[32m\nWithdrawal Successful\033[0m\n";
        cout << "Withdrawn Amount: " << amount << " FRW\n";
        cout << "Remaining Balance: " << balance << " FRW\n";
        
        history[transCount] = "Withdrawn : " + to_string(amount) + " FRW";
        transCount++;
    }
    return balance;
}

void showHistory(string history[], int transCount) {
    cout << "\n\033[36m====== TRANSACTION HISTORY ======\033[0m\n";
    if (transCount == 0) {
        cout << "\033[31mNo Transactions Found\033[0m\n";
    } else {
        for (int i = 0; i < transCount; i++) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
}

int main() {
    int defaultPIN = 12345;
    int maxAttempts = 3;
    int pin, choice;
    int balance = 0;
    string transactionHistory[100];
    int transCount = 0;

    cout << "\033[36m\t\t=======================\n";
    cout << "\t\t     BK ATM SYSTEM     \n";
    cout << "\t\t=======================\033[0m\n";

    do {
        cout << "\tEnter your PIN: ";
        cin >> pin;
        maxAttempts--;

        if (pin == defaultPIN) {
            cout << "\033[32m\n\tLogin Successful\033[0m\n";
            cout << "\033[35m\tWelcome to BK ATM\033[0m\n";
            
            do {
                cout << "\n\033[34m=========== MAIN MENU ===========\033[0m\n";
                cout << "[1] Check Balance\n";
                cout << "[2] Deposit Money\n";
                cout << "[3] Withdraw Money\n";
                cout << "[4] Transaction History\n";
                cout << "[5] Exit\n";
                cout << "\033[34m=================================\033[0m\n";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        checkBalance(balance);
                        break;
                    case 2:
                        balance = depositMoney(balance, transactionHistory, transCount);
                        break;
                    case 3:
                        balance = withdrawMoney(balance, transactionHistory, transCount);
                        break;
                    case 4:
                        showHistory(transactionHistory, transCount);
                        break;
                    case 5:
                        cout << "\033[33m\nThank You For Using BK ATM\033[0m\n";
                        break;
                    default:
                        cout << "\033[31m\nInvalid Choice\033[0m\n";
                }
            } while (choice != 5);
            return 0;
        } else {
            cout << "\033[31m\nWrong PIN\033[0m\n";
            if (maxAttempts > 0) {
                cout << "\033[33mRemaining Attempts : " << maxAttempts << "\033[0m\n";
            }
        }
    } while (pin != defaultPIN && maxAttempts > 0);

    if (maxAttempts == 0) {
        cout << "\033[31m\nATM BLOCKED\033[0m\n";
    }
    
    return 0;
}