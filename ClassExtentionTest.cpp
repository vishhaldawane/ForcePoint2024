#include <iostream>
using namespace std;

class Doctor {
    int x;
    public:
   
    void readFile() {
            cout<<"\nReading the file in a loop...";
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
    int y;
    void cut() {
        cout<<"\nSurgeon is Cutting...";
    }
    void stitch() {
        cout<<"\nSurgeon is Stitching......";
    }
    
    public:
        

        void diagnose() { //1. exclusive (may become 2.inherited)
            cout<<"\nSurgeon is diagnosing....checking CT Scan report....";
        }
        void doSurgery() {
            cut();
            cout<<"\nDoing the surgery...";
            stitch();
        }
};

class HeartSurgeon : public Surgeon {
    int z;
    void cut() {
        cout<<"\nHeartSurgeon is Cutting...on the chest...";
    }
    void stitch() {
        cout<<"\nHeartSurgeon is Stitching.....on the chest....";
    }
    
    public:
        

        void diagnose() { //1. exclusive (may become 2.inherited)
            cout<<"\nHeartSurgeon is diagnosing....checking ECG report....";
        }
        void doSurgery() {
            cut();
            cout<<"\nDoing the surgery...";
            stitch();
        }
        void doHeartSurgery() {
            cut();
            cout<<"\nDoing the HEART surgery...";
            stitch();
        }
};
int main() {

    Doctor *ptr;

    Doctor doctor;
  //  doctor.diagnose();
    cout<<"\nsize of doctor : "<<sizeof(doctor);
    ptr = &doctor; //pointer to an object
    ptr->diagnose(); //invoke the object methods via the pointer

    cout<<"\n------------------";

    Surgeon surgeon;
  //  surgeon.diagnose();
    cout<<"\nsize of surgeon : "<<sizeof(surgeon);

    ptr = &surgeon;
    ptr->diagnose();

    cout<<"\n------------------";

    HeartSurgeon heartSurgeon;
    cout<<"\nsize of heart surgeon : "<<sizeof(heartSurgeon);

    //heartSurgeon.diagnose();
    
    ptr = &heartSurgeon;
    ptr->diagnose();
    return 0;
}