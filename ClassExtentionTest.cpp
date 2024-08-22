#include <iostream>
using namespace std;

class Doctor {
    FILE *fp;

    public:
    Doctor() {
        cout<<"\nDoctor ctor...opening file...";
        fp = fopen("abc.txt","r");
    }
    void readFile() {
            cout<<"\nReading the file in a loop...";
    }
    ~Doctor() {
        cout<<"\nDoctor dtor...closing the file...";
        fclose(fp);
    }
};

int main() {

    { //scope started
        cout<<"\nScope started....";
        Doctor doctorObj;
        doctorObj.readFile();

    } //scope over

    cout<<"\nScope is over...";

    return 0;
}