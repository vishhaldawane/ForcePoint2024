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

class HeartSurgeon : public Surgeon {

    void cut() {
        cout<<"\nHeartSurgeon is Cutting...on the chest...";
    }
    void stitch() {
        cout<<"\nHeartSurgeon is Stitching.....on the chest....";
    }
    
    public:
        HeartSurgeon() {
            cout<<"\nHeartSurgeon ctor invoked...";
        }
        ~HeartSurgeon() {
            cout<<"\nHeartSurgeon dtor invoked...";
        }

        void diagnose() { //1. exclusive (may become 2.inherited)
            cout<<"\nHeartSurgeon is diagnosing....checking ECG  report....";
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

    { //scope started
         Doctor doctorObj1;
         doctorObj1.diagnose();
    }
    cout<<"\n-------------------------";  
    {
        Surgeon surgeonObj; 
        surgeonObj.diagnose();
    }
    cout<<"\n-------------------------";

    {
        HeartSurgeon heartSurgeon;
        heartSurgeon.diagnose();
    } //scope over


    return 0;
}