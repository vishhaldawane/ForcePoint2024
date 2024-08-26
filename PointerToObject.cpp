#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
//char        int        float       doube
// 'A'        123        54.12       32322.33
//00000000    0000 0000  0000 0000   0000 0000 0000 0000
//            0000 0000  0000 0000   0000 0000 0000 0000
//                       0000 0000   0000 0000 0000 0000 
//                       0000 0000   0000 0000 0000 0000
//    1         2             4            8
//  65230      65330       65440      65980 <-unsinged int
// ptr

//int the data type of num
    int num=190;

//below int is NOT the data type of ptr
//*ptr's data type is unsinged int ( cause of positive
//memory address)
//here int is the type of that variables
//whose address is hold by the ptr

    int *ptr;

    ptr = &num;

//value of a variable is accessible via
//1. its name [ direct ]
//2. its address [ indirect ]
/*
        name        num         ptr  <-- developer
        value       190         64240 <--developer  
        address     64240       64390 <--system
*/
    cout<<"\n---- with num now -----";

    cout<<"\nnum is : "<<num;
    cout<<"\nnum is : "<<*&num;
    printf("\nnum stored at %ld",&num);
    cout<<"\n---- with pointer now -----";
    cout<<"\nnum is : "<<*ptr;
    printf("\nptr is %ld",ptr);

}