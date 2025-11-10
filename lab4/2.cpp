#include <iostream>
#include<string>
using namespace std;

class Account {
    public:
    int accNo;
    double balance;
    
    void setAccount() {
        cout << "Enter account number: ";
        cin >> accNo;
        cout << "Enter balance: ";
        cin >> balance;
    }
    
    void displayAccount() {
        cout << "Account Number: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : virtual public Account {
    public:
    double interestRate;
    
    void setSavings() {
        cout << "Enter interest rate: ";
        cin >> interestRate;
    }
    
    void displaySavings() {
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : virtual public Account {
    public:
    double overdraftLimit;
    
    void setCurrent() {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
    }
    
    void displayCurrent() {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class PremiumAccount : virtual public SavingsAccount,virtual public CurrentAccount {
    public:
    int rewardsPoints;
    
    void setPremium() {
        setAccount();
        setSavings();
        setCurrent();
        
        cout << "Enter rewards points: ";
        cin >> rewardsPoints;
    }
    
    void displayPremium() {
        displayAccount();
        displaySavings();
        displayCurrent();
        
        cout << "Rewards Points: " << rewardsPoints << endl;
    }
};

int main() {
    PremiumAccount premium;
    
    premium.setPremium();
    premium.displayPremium();
    
    return 0;
}