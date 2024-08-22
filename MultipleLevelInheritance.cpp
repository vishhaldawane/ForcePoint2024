#include <iostream>
using namespace std;
/*

    PetrolEngine        CNGEngine
        |                   |
        +-------------------+
                  |
            HybridEngine1

    PetrolEngine        ElectricEngine
        |                   |
        +-------------------+
                  |
            HybridEngine2

            
*/

class PetrolEngine
{
    string fuelName;
    int fuelSize;
    string fuelClarity;
    float costPerLitre;

    public:
     PetrolEngine() {
        cout<<"\nPetrolEngine ctor...";
    }
    void setPetrolEngine(string fn, int fc, string fcl, float cpl) {
        fuelName=fn;
        fuelSize=fc;
        fuelClarity=fcl;
        costPerLitre=cpl;
    }
    void printPetrolEngine() {
        cout<<"\nFuel Name     : "<<fuelName;
        cout<<"\nFuel Size     : "<<fuelSize;
        cout<<"\nFuel Clarity  : "<<fuelClarity;
        cout<<"\nFuel COST PL  : "<<costPerLitre;
        cout<<"\n-----------------------";
    }
    void usingPetrol() {
        cout<<"\nUsing petrol....";
    }
};
class ElectricEngine
{
    string batteryName;
    int batteryChargingLevel; //1 to 100
    float chargingTime;
    float distanceCovered;

    public:
    ElectricEngine() {
        cout<<"\nElectricEngine ctor...";
    }
    void setElectricEngine(string bn, int bcl, float ct, float dc) {
        batteryName=bn;
        batteryChargingLevel=bcl;
        chargingTime=ct;
        distanceCovered=dc;
    }
    void printPetrolEngine() {
        cout<<"\nBattery Name     : "<<batteryName;
        cout<<"\nBattery Level    : "<<batteryChargingLevel;
        cout<<"\nCharging Time    : "<<chargingTime;
        cout<<"\nDistance covered : "<<distanceCovered;
        cout<<"\n-----------------------";
    }
    void usingBattery() {
        cout<<"\nUsing batteries....";
    }
};
class HybridEngine : public PetrolEngine, public ElectricEngine
{
    bool runningOnEletric;

    public:
    HybridEngine(bool status) {
        cout<<"\nHybridEngine ctor...";
        runningOnEletric=status;
        if(runningOnEletric==true) {
            usingBattery();
        }
        else {
            usingPetrol();
        }
    }


};

int main()
{
    HybridEngine hybridEngine(false);
    return 0;
}