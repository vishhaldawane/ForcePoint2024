#include <iostream>
#include <stdio.h>
using namespace std;

class Student
{
    int rollNumber;
    string studentName;
    char gender;
    int age;
    float percentage;
    char grade;
    public:
        Student(int roll, string sn, char g, int a, float per, char gr) {
             rollNumber=roll;
             studentName=sn;
             gender=g;
             age=a;
             percentage=per;
             grade=gr;
        }
        void showStudent() {
            cout<<"\nROLL   :"<<rollNumber;
            cout<<"\nNAME   :"<<studentName;
            cout<<"\nGENDER :"<<gender;
            cout<<"\nAGE    :"<<age;
            cout<<"\nPER    :"<<percentage;
            cout<<"\nGRADE  :"<<grade;
            cout<<"\n--------------------\n";
        }
};
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
    cout<<"\nnum size : "<<sizeof(num);
    cout<<"\nptr size : "<<sizeof(ptr);


    Student student1(101,"Jack",'M',23,92.44,'A');
    student1.showStudent();

    Student *studentPtr;
    studentPtr = &student1;

    cout<<"\nstudent1   size : "<<sizeof(student1);
    cout<<"\nstudentPtr size : "<<sizeof(studentPtr);

    studentPtr->showStudent();
    (*studentPtr).showStudent();

    
}