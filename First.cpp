#include <iostream>
using namespace std;
//the logic around the data is known as contract of a class
struct SavingsAccount
{
    private: 
    float bankBalance;
    
    public:
    void withdraw(float amountToWithdraw) {
        if(amountToWithdraw<(bankBalance-5000)) {
            cout<<"\nWithdrawing "<<bankBalance;
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
        cout<<"\nBank Balance  : "<<bankBalance;
    }
};
int main()
{
    cout << "Begin\n " << std::endl;
    SavingsAccount savingsAccount;
    //savingsAccount.bankBalance=50000;
    savingsAccount.deposit(45000);
    savingsAccount.printBalance();
    savingsAccount.withdraw(7000);
    savingsAccount.printBalance();

    cout << "End\n " << std::endl;
}