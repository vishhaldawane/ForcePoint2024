#include <iostream>
#define NEGATIVE_ACCOUNT_NUMBER -1
#define INVALID_ACCOUNT_HOLDER_NAME -2
#define INVALID_OPENING_BALANCE -3

using namespace std;
//the logic around the data is known as contract of a class


class BankException {
    string message;
    int errorCode;
    public:
    BankException(string msg, int error) {
        message = msg;
        errorCode = error;
    }
    virtual string getMessage() {
        return message;
    }

};
class NegativeAccountNumberException : public BankException
{
    public:
    NegativeAccountNumberException(string message, int error) : BankException(message,error) {

    }

};
class InvalidNameException  : public BankException
{
    public:
    InvalidNameException(string message, int error) : BankException(message,error) {

    }
};

class InvalidAccountOpeningBalanceException : public BankException
{
    public:
    InvalidAccountOpeningBalanceException(string message, int error) : BankException(message,error) {

    }
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
    
    // although it doesnt have return type, it can take arguments
    // hence it can be OVERLOADED

    SavingsAccount(int acno, string holder, float initialBalance) 
    {
        cout<<"\nSetting initial account details via SavingsAccount(int,string,float) ctor....";
        
        //ACNO
        if(acno<0) {
            //cout<<"\nNegative account number disallowed....";
            throw NegativeAccountNumberException("Invalid account number, it cannot be in negative",-1);// as if an exception to be thrown... from here
        }
        else
            accountNumber=acno;
        
        //NAME
        bool found=false;
        for(int i=0;i<holder.length();i++) { //Sm&th
            char ch = holder[i];
            if( (ch>=65 && ch<=90) || (ch>=97  && ch<=122) ) {
                //cout<<"ch : "<<ch<<endl;
                found=true;
            }
            else {
                found=false;
                break;
            }
        }
        if(found==false) {
            throw InvalidNameException("Account holder can only have alphabets",-2);
        }
        else {
            cout<<"\nsetting the holder..";
            accountHolder=holder;
        }

        //BALANCE
        if(initialBalance<5000) {
            throw InvalidAccountOpeningBalanceException("Opening balance cannot be lesser than 5000 INR",-3);
        }
        else
            bankBalance=initialBalance;
    }
    SavingsAccount(int acno, string holder) {
        cout<<"\nSetting initial account details via SavingsAccount(int,string) ctor....";
        accountNumber=acno;
        accountHolder=holder;
        bankBalance=0;
    }
    SavingsAccount(string holder) {
        cout<<"\nSetting initial account details via SavingsAccount(string) ctor....";
        accountNumber=0;
        accountHolder=holder;
        bankBalance=0;
    }
    SavingsAccount(int acno, float amount) {
        cout<<"\nSetting initial account details via SavingsAccount(int,float) ctor....";
        accountNumber=acno;
        accountHolder="";
        bankBalance=amount;
    }
     SavingsAccount(float amount) {
        cout<<"\nSetting initial account details via SavingsAccount(float) ctor....";
        accountNumber=0;
        accountHolder="";
        bankBalance=amount;
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
    try
    {
        SavingsAccount savingsAccount(101,"Smith",-50000); //expecting a default/impl no-arg
        savingsAccount.printBalance();
        savingsAccount.deposit(45000);
        savingsAccount.printBalance();
        savingsAccount.withdraw(7000);
        savingsAccount.printBalance();
    }
    catch(NegativeAccountNumberException &ref)
    {
        cout<<"\nCAUGHT HERE1 "<<ref.getMessage();
        //std::cerr << ref.what() << '\n';
    }
    catch(InvalidAccountOpeningBalanceException &ref)
    {
        cout<<"\nCAUGHT HERE2 "<<ref.getMessage();
        //std::cerr << ref.what() << '\n';
    }
    catch(InvalidNameException &ref)
    {
        cout<<"\nCAUGHT HERE3 "<<ref.getMessage();
        //std::cerr << ref.what() << '\n';
    }
    cout << "End\n " << std::endl;
}