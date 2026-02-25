#include <iostream>
#include <cstring>
using namespace std;

/* ===============| Base class : BankAccount|=============== */
class BankAccount {
private:
    int accountNumber;
    char accountHolderName[50];
    double balance;

public:
	//Constructor
    BankAccount(int accountno, const char* name, double bal) {
        accountNumber = accountno;
        strcpy(accountHolderName, name);
        balance = bal;
    }
  
    
    //setter
    void setdata(double bal) {
        balance = bal;
    }

    //getter
    double getdata() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        
        cout << "Amount Deposited\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }
    
    //desplay
    void displayAccountInfo() {
        cout << "Account Number = " << accountNumber << endl;
        cout << "Name = " << accountHolderName << endl;
        cout << "Balance = " << balance << endl;
    }

    void calculateInterest() {
        cout << "No interest for base account\n";
    }
};

/* ===============| Derived class : SavingsAccount|=============== */
class SavingsAccount : public BankAccount {
    double interestRate;

public:
	//Constructor
    SavingsAccount(int accountno, const char* ahn, double bal, double rate)
        : BankAccount(accountno, ahn, bal) {
        interestRate = rate;
    }
    
    void calculateInterest(double rate) {
        double interest = getdata() * rate / 100;
        cout << "Savings Interest : " << interest << endl;
    }
};

/* ===============| Derived class : FixedDepositAccount|=============== */
class FixedDepositAccount : public BankAccount {
    int term;

public:
	//Constructor
    FixedDepositAccount(int accountno, const char* ahn, double bal, int term)
        : BankAccount(accountno, ahn, bal) {
        this->term = term;
    }

    void calculateInterest(double rate, int months) {
        double interest = (getdata() * rate * months) / (12 * 100);
        cout << "Fixed Deposit Interest : " << interest << endl;
    }
};

/* ===============| Main function|=============== */
int main() {
    SavingsAccount obj1(101, "Rohit", 10000, 5);
    FixedDepositAccount obj2(102, "Roshni", 10000, 12);

    int choice;
    double amount;

    do {
        cout << "\n===== BANK MENU =====";
        cout << "\n1. Deposit (Savings)";
        cout << "\n2. Withdraw (Savings)";
        cout << "\n3. Savings Interest";
        cout << "\n4. Fixed Deposit Interest";
        cout << "\n5. Display Savings Account Info";
        cout << "\n6. Check Balance";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	cout << "Enter the amount: ";
            cin >> amount;
            obj1.deposit(amount);
            break;

        case 2:
        	cout << "Enter the amount: ";
            cin >> amount;
            obj1.withdraw(amount);
            break;

        case 3:
            obj1.calculateInterest(5);
            break;

        case 4:
            obj2.calculateInterest(6.5, 12);
            break;

        case 5:
            obj1.displayAccountInfo();
            break;
            
        case 6:
            cout << "Current Balance = " << obj1.getdata() << endl;
            break;

        case 0:
            cout << "Thank You!\n";
            break;
            
        default:
        	cout<<"Invalid Choice !"<<endl;
			break;
        }
    } while (choice != 0);

    return 0;
}

/*
output: 

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 6
Current Balance = 10000

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 1
Enter the amount: 5000
Amount Deposited

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 3
Savings Interest : 750

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 2
Enter the amount: 1000
Amount Withdrawn

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 6
Current Balance = 14000

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 4
Fixed Deposit Interest : 650

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 8
Invalid Choice !

===== BANK MENU =====
1. Deposit (Savings)
2. Withdraw (Savings)
3. Savings Interest
4. Fixed Deposit Interest
5. Display Savings Account Info
6. Check Balance
0. Exit
Enter choice: 0
Thank You!
*/
