#include <iostream>
using namespace std;
//the logic around the data is known as contract of a class
class SavingsAccount
{
    int accountNumber;
    string accountHolder;
    float bankBalance;
    
    public:

    void setSavingsAccount(int acno, string holder, float balance) {
        cout<<"\nSetting initial savings account details....";
        accountNumber=acno;
        accountHolder=holder;
        bankBalance=balance;
    }
    void withdraw(float amountToWithdraw) {
        if(amountToWithdraw<(bankBalance-5000)) {
            cout<<"\nWithdrawing "<<amountToWithdraw;
            bankBalance-=amountToWithdraw;
        }
        else {
            cout<<"\nMaintain min balance as 5000 INR, can't withdraw";
        }
    }
    void deposit(float amountToDeposit) {
        if(amountToDeposit>=50000) {
            cout<<"\nPlease provide the proof of the income or PAN";
        }
        else {
            cout<<"\nDepositing cash "<<amountToDeposit;
            bankBalance+=amountToDeposit;
        }
    }
    void printBalance() {
        cout<<"\nBank Acno    : "<<accountNumber;
        cout<<"\nBank Holder  : "<<accountHolder;
        cout<<"\nBank Balance : "<<bankBalance<<endl;
    }
};
int main()
{
    cout << "Begin\n " << std::endl;
    SavingsAccount savingsAccount;
    savingsAccount.setSavingsAccount(101,"Jack",50000);
    savingsAccount.printBalance();
    savingsAccount.deposit(45000);
    savingsAccount.printBalance();
    savingsAccount.withdraw(7000);
    savingsAccount.printBalance();

    cout << "End\n " << std::endl;
}