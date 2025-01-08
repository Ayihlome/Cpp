#include <iostream>
using namespace std;

string name;
double balance; 
int accountNum;


void createAccount () {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account number: ";
    cin >> accountNum;
    cout << "Enter your initial deposit (must be greater than R0): ";
    cin >> balance;

    cout << "Account created Successfully" << endl;
}

void depositMoney (double &balance){
    double depositAmount;
    cout << "Enter deposit amount (must be greater than R0): ";
    cin >> depositAmount;

    balance += depositAmount;

}

void withdrawMoney (double &balance){
    int withdrawAmount;
    cout << "Enter amount you will be withdrawing (must be greater than R0): ";
    cin >> withdrawAmount;

    if (withdrawAmount < balance){
        balance -= withdrawAmount;
    }else {
        cout << "Insuffiecient Funds" << endl;
    }

}

void checkBalance (double &balance){
    cout << "Your current balance is: R" << balance << endl; 
}

void AccountDetails (string &name, double &balance, int &accountNum){
    cout << "--- Account Details ---" << endl;
    cout << "Acount Holder: " << name << endl;
    cout << "Acount Number: " << accountNum << endl;
    cout << "Account Balance: R" << balance << endl;
}

int main (){
    // Display Menu
    int choice;
    while (choice != 6)
    {
       cout << "--- Bank Account Management System ---" << endl;
       cout << "1. Create Account" << endl;
       cout << "2. Deposit Money" << endl;
       cout << "3. Withdraw Money" << endl;
       cout << "4. Check Balance" << endl;
       cout << "5. Display Account Details" << endl;
       cout << "6. Exit" << endl;
       cout << "Enter your chouice (1-6): ";
       cin >> choice;

       switch (choice)
       {
       case 1:
        createAccount();
        break;
        case 2:
        depositMoney(balance);
        break;
        case 3:
        withdrawMoney(balance);
        break;
        case 4:
        checkBalance(balance);
        break;
        case 5:
        AccountDetails(name, balance, accountNum);
        break;
       
       default:
       cout << "Exiting the system. Goodbye!" << endl;
        break;
       }
    }

    return 0;

}

void menu () {
    
}

