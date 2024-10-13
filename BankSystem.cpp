// BankSystem.cpp
#include "BankSystem.h"
using namespace std;

//EMPTY CONSTRUCTOR
Bank_System::Bank_System() {
    head = NULL;
    count = 0;
}

//FUNCTION TO CHECK IF ACCOUT BALANCE IS 0
bool Bank_System::IsEmpty(double Balance) {
    return Balance == 0;
}

//FUNCTION TO CHECK IF NEW ACCOUNT ID ALREADY USED OR UNIQUE 
bool Bank_System::SearcAccount(int Acc_ID) {
    account* current = head;
    while (current != NULL) {
        if (current->account_ID == Acc_ID)
            return true;
        current = current->next;
    }
    return false;
}

//ACCOUNT CREATION FUNCTION
void Bank_System::Create_Account() {
    account* newAccount = new account;
    cout << "Enter Account ID \n";
    cin >> newAccount->account_ID;
    if (SearcAccount(newAccount->account_ID)) {
        cout << "Account already exists \n";
        delete newAccount;
    } else {
        cout << "Enter Account customer name \n";
        cin >> newAccount->customer_Name;
        cout << "Set a password \n";
        cin >> newAccount->password;
        cout << "Enter Account initial balance \n";
        cin >> newAccount->Balance;
        newAccount->next = NULL;
        if (head == NULL)
            head = newAccount;
        else {
            account* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newAccount;
        }
        cout << "Account is created Succesfully \n";
        count++;
    }
}

//CHECK BALANCE FUNCTION
void Bank_System::check_balance() {
    cout << "Enter Account ID \n";
    int acc_id;
    cin >> acc_id;
    account* current = head;
    int account_flag = 0;
    while (current != NULL) {
        if (current->account_ID == acc_id) {
            account_flag = 1;
            cout << "Enter password \n";
            int password_check;
            cin >> password_check;
            if (password_check == current->password) {
                cout << "Balance = " << current->Balance << endl;
            } else
                cout << "Wrong password \n";
        }
        current = current->next;
    }
    if (account_flag == 0)
        cout << "Account NOT found , NO Account ID matches \n";
}

//WITHDRAWING FUNCTION
void Bank_System::withdrawing() {
    cout << "Enter Account ID \n";
    int acc_id;
    cin >> acc_id;
    account* current = head;
    int account_flag = 0;
    while (current != NULL) {
        if (current->account_ID == acc_id) {
            account_flag = 1;
            cout << "Enter password \n";
            int password_check;
            cin >> password_check;
            if (password_check == current->password) {
                if (IsEmpty(current->Balance)) {
                    cout << "Sorry, can't withdraw Your account balance is 0 \n";
                } else {
                    int value;
                    cout << "Enter withdraw value \n";
                    cin >> value;
                    if (current->Balance < value)
                        cout << "Sorry , Can't withdraw Your Balance NOT Enough \n";
                    else {
                        current->Balance -= value;
                        cout << "Withdrawing is done Succesfully \n";
                        cout << "Current Balance = " << current->Balance << endl;
                    }    
                }
            } else
                cout << "Wrong password \n";
        }
        current = current->next;
    }
    if (account_flag == 0)
        cout << "Account NOT found , NO Account ID matches \n";
}

//DEPOSITING FUNCTION
void Bank_System::Depositing() {
    cout << "Enter Account ID \n";
    int acc_id;
    cin >> acc_id;
    account* current = head;
    int account_flag = 0;
    while (current != NULL) {
        if (current->account_ID == acc_id) {
            account_flag = 1;
            cout << "Enter password \n";
            int password_check;
            cin >> password_check;
            if (password_check == current->password) {
                int value;
                cout << "Enter deposit value \n";
                cin >> value;
                current->Balance += value;
                cout << "Depositing is done Succesfully \n";
                cout << "Current Balance = " << current->Balance << endl;
            } else
                cout << "Wrong password \n";
        }
        current = current->next;
    }
    if (account_flag == 0)
        cout << "Account NOT found , NO Account ID matches \n";
}

//ACCOUNT DELETION FUNCTION
void Bank_System::Delete_Account() {
    cout << "Enter Account ID \n";
    int acc_id;
    cin >> acc_id;
    account* current = head;
    account* prev = NULL;
    int account_flag = 0;
    while (current != NULL) {
        if (current->account_ID == acc_id) {
            account_flag = 1;
            cout << "Enter password \n";
            int password_check;
            cin >> password_check;
            if (password_check == current->password) {    
                if (current == head) 
                    head = head->next;
                else 
                    prev->next = current->next;            
                delete current;
                cout << "Account is deleted Succesfully \n";
                count--;
            } else
                cout << "Wrong password \n";
            break;
        } else {
            prev = current;
            current = current->next;
        }    
    }
    if (account_flag == 0) 
        cout << "Account NOT found , NO Account ID matches \n";
}

//FUNCTION TO SHOW CURRENT NUMBER OF ACCOUNTS (ÇáÊÚÏíá)
void Bank_System::Count_Accounts() {
    cout << "Number of Accounts = "<< count << endl;
}


//FUNCTION TO DISPLAY A MENU OF OPERATIONS TO USER
void displayMenu() {
    cout << "\n1.Create Account \n"
         << "2.Delete Account \n"
         << "3.Deposit \n"
         << "4.Withdraw \n"
         << "5.Check Account Balance \n"
         << "6.Show Number of Accounts \n"
         << "0.Exit \n";
}
