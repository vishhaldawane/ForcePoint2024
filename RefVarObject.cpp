#include <iostream>
#include <stdio.h>
using namespace std;
class Employee {
    int empNumber;
    float salary;
    float hra;
    float da;
    float ta;
    float net;
};
void fun1(Employee x) {
    cout<<"\nfun1: "<<&x;
    cout<<"\nfun1: "<<sizeof(x);
    cout<<"\n------------";

}
void fun2(Employee *x) {
    cout<<"\nfun2: "<<&x;
    cout<<"\nfun2: "<<sizeof(x);
    cout<<"\n------------";
}
void fun3(Employee &x) {
    cout<<"\nfun3: "<<&x;
    cout<<"\nfun3: "<<sizeof(x);
    cout<<"\n------------";
}

int main() {
    Employee empObj1;
    cout<<"\nmain: "<<&empObj1;
    cout<<"\n------------";

    fun1(empObj1); //pass by value
    fun2(&empObj1); //pass by address
    fun3(empObj1); //pass by reference
}