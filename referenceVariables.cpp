#include <iostream>
using namespace std;
int main() {
    int rajesh=190;
    int *ptr=&rajesh;
    int &raj = rajesh;
    
    printf("\nvalue of rajesh : %d",rajesh); //190
    printf("\nvalue of raj    : %d",raj); //190

    printf("\naddress of rajesh : %ld",&rajesh);//65000
    printf("\naddress of raj    : %ld",&raj);//65000

    printf("\nvalue of ptr      : %ld",ptr); //65000
    printf("\naddress of ptr    : %ld",&ptr);//65340

    cout<<"\nsetting 290 to raj....";
    raj=290;
    printf("\nvalue of rajesh : %d",rajesh); //190
    printf("\nvalue of raj    : %d",raj); //190

    int &raju = raj;

    int &raja = raju;

    int &rajee = rajesh;

    printf("\nvalue of rajesh : %d",rajesh); //190
    printf("\nvalue of raj    : %d",raj); //190
    printf("\nvalue of raju   : %d",raju); //190
    printf("\nvalue of raja    : %d",raja); //190
    printf("\nvalue of rajee    : %d",rajee); //190


}