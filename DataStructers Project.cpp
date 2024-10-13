// YOUSSEF MOHAMED MOSTAFA (SOFTWARE ENGINEERING)
// DATA STRUCTERS PROJECT - BANK SYSTEM

// main.cpp
#include "BankSystem.h"
using namespace std;

int main() {
    Bank_System b;
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            b.Create_Account();
            break;
        case 2:
            b.Delete_Account();
            break;
        case 3:
            b.Depositing();
            break;
        case 4:
            b.withdrawing();
            break;
        case 5:
            b.check_balance();
            break;
        case 6:
            b.Count_Accounts();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid Choice \n";
        }
    }
}
