#include <iostream>
using namespace std;
//the logic around the data is known as contract of a class
class Student
{
 // here is an invisible ctor , known as 1.'default ctor'
 // also knonw as 2.'implicit no-arg ctor'.
};

class Employee
{
    Employee() { // explicit no-arg ctor, visible, hence not default

    }
};
//either u can have implicit or explicit, but not both 
class SavingsAccount
{
    int accountNumber;
    string accountHolder;
    float bankBalance;
    
    public:
    //same name as of the enclosing class, without return type
    //is known as constructor 
    //every class comes with a default [ invisible to human eyes ] ctor

    // it is AUTOMATICALLY INVOKED DURING INSTANCE CREATION TIME
    // to initialize the data member of the class
    // it is invoked only ONCE per object
    // if the constructor fails to run, the data is rollbacked

    SavingsAccount(int acno, string holder, float initialBalance) {
        cout<<"\nSetting initial account details via parameterized ctor....";
        accountNumber=acno;
        accountHolder=holder;
        bankBalance=initialBalance;
    }
    SavingsAccount() {
        cout<<"\nSetting initial account details via no-arg ctor....";
        accountNumber=0;
        accountHolder="NONAME";
        bankBalance=0;
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
    SavingsAccount savingsAccount(101,"Jack",50000); //expecting a default/impl no-arg
    savingsAccount.printBalance();
    savingsAccount.deposit(45000);
    savingsAccount.printBalance();
    savingsAccount.withdraw(7000);
    savingsAccount.printBalance();

    cout << "End\n " << std::endl;
}