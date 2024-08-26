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

template <class T> class Pair {
    T x;
    T y;

    public:
    
    Pair(T a, T b) {
        cout<<"\nPair(T,T) ctor...";
        x = a;
        y = b;
    }
    void swapValues() {
        cout<<"\nPair : swapping..T... : "<<typeid(T).name();
        T temp = x;
        x = y;
        y = temp;
        cout<<"\nswapping done..."; 
    }
    void printValues() {
        cout<<"\nPair : printValues()";
        cout<<"\nx "<<x;
        cout<<"\ny "<<y;
        
    }
};

int main() {

    double x=10;
    double y=20;
   
    Pair<double> pair1(x,y);
    pair1.printValues();
    pair1.swapValues();
    pair1.printValues();


   

    cout<<"\n-----------------";
/*
    int p=100;
    int q=200;
    cout<<"\np : "<<p;
    cout<<"\nq : "<<q;

    swapValues<int>(p,q);

    cout<<"\np : "<<p;
    cout<<"\nq : "<<q;

*/

    return 0;
}