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
    void diagnose() { //1. exclusive (may become 2.inherited)
        cout<<"\nDoctor is diagnosing....checking ENT..";
    }
};
//1. exclusive function
//2. inherited function
//3. overrridden function
//4. implemented functions

class Surgeon : public Doctor {

    void cut() {
        cout<<"\nSurgeon is Cutting...";
    }
    void stitch() {
        cout<<"\nSurgeon is Stitching......";
    }
    
    public:
        Surgeon() {
            cout<<"\nSurgeon ctor invoked...";
        }
        ~Surgeon() {
            cout<<"\nSurgeon dtor invoked...";
        }

        void diagnose() { //1. exclusive (may become 2.inherited)
            cout<<"\nSurgeon is diagnosing....checking CT Scan report....";
        }
        void doSurgery() {
            cut();
            cout<<"\nDoing the surgery...";
            stitch();
        }
};

int main() {

    { //scope started
        cout<<"\nScope started....";
        // Doctor doctorObj1;
        // Doctor doctorObj2;
        // Doctor doctorObj3;
        
        // doctorObj1.readFile();
        // doctorObj2.readFile();
        // doctorObj3.readFile();

        Surgeon surgeonObj;
      //  surgeonObj.diagnose();
        //surgeonObj.doSurgery();
    

    } //scope over

    cout<<"\nScope is over...";

    return 0;
}