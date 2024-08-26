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
        Student(int roll=100, string sn="NONAME", char g='F', int a=18, float per=80.0, char gr='A') {
             rollNumber=roll;
             studentName=sn;
             gender=g;
             age=a;
             percentage=per;
             grade=gr;
        }
        void setStudent(int roll=100, string sn="NONAME", char g='F', int a=18, float per=80.0, char gr='A') {
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
            cout<<"\nsizeof name : "<<sizeof(studentName);
            cout<<"\nlength of  name : "<<studentName.length();
            
            cout<<"\nGENDER :"<<gender;
            cout<<"\nAGE    :"<<age;
            cout<<"\nPER    :"<<percentage;
            cout<<"\nGRADE  :"<<grade;
            cout<<"\n--------------------\n";
        }
};
// MyString ms("Chandrashekhar");

class MyString
{
    char *str;
    int len;
    public:
    MyString(char *ptr) {
        str=(char*) malloc(strlen(ptr)+1);
        strcpy(str,ptr);
        len = strlen(str);
    }
    char* toString() {
        return str;
    }
    int length() {
        return len;
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


    Student student1(101,"Chandrashekhar Purushottam Aazaad");
    student1.showStudent();

    Student *studentPtr;
    studentPtr = &student1;

    cout<<"\nstudent1   size : "<<sizeof(student1);
    cout<<"\nstudentPtr size : "<<sizeof(studentPtr);

    studentPtr->showStudent();
    (*studentPtr).showStudent();

    MyString ms("Chandrashekhar PurushottamSingh Azaad");
    cout<<"\nms : "<<ms.toString();
    cout<<"\nlength is : "<<ms.length();
    
    cout<<"\nsize of ms "<<sizeof(ms);
    const int SIZE=5;
    Student students[SIZE] ;
    
    students[0].setStudent(101,"Chandrashekhar",'M',23,90.45,'A');
    students[1].setStudent(102,"BhagatSingh",'M',21,95.45,'A');
    students[2].setStudent(103,"Sukhdev",'M',20,92.45,'A');
    students[3].setStudent(104,"Rajguru",'M',21,93.45,'A');
    students[4].setStudent(105,"MadanLal",'M',24,95.45,'A');
   
    for (int i = 0; i < SIZE; i++)
    {
        students[i].showStudent();
    }
    
    cout<<"\nsize of ms "<<sizeof(students);

    cout<<"\n--------via pointer to an array -----";    studentPtr = students;  //name of the array
    //is the address itself

    for (int i = 0; i < SIZE; i++)
    {
        studentPtr->showStudent();
    }
}