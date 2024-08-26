#include <iostream>
#include <stdio.h>
using namespace std;

/*
void swap(int &i, int &j) {
    cout<<"\nswapping..ints...";
    int temp = i;
    i = j;
    j = temp;
    cout<<"\nswapping done...";
}
void swap(float &i, float &j) {
    cout<<"\nswapping..float...";
    float temp = i;
    i = j;
    j = temp;
    cout<<"\nswapping done...";
}
void swap(double &i, double &j) {
    cout<<"\nswapping..double...";
    double temp = i;
    i = j;
    j = temp;
    cout<<"\nswapping done...";
}*/

template <class T> void swapValues(T &i, T &j) {
    //type_info information = typeid(T);
    
    cout<<"\nswapping..T... : "<<typeid(T).name();
    T temp = i;
    i = j;
    j = temp;
    cout<<"\nswapping done...";
}
int main() {

    double x=10;
    double y=20;
    cout<<"\nx : "<<x;
    cout<<"\ny : "<<y;

    swapValues<double>(x,y);

    cout<<"\nx : "<<x;
    cout<<"\ny : "<<y;

    cout<<"\n-----------------";

    int p=100;
    int q=200;
    cout<<"\np : "<<p;
    cout<<"\nq : "<<q;

    swapValues<int>(p,q);

    cout<<"\np : "<<p;
    cout<<"\nq : "<<q;


    return 0;
}