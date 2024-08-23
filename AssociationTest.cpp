#include <iostream>
using namespace std;
class Machine {
    private: 
        int machineId; 
    public: 
        Machine(int id) {
            machineId = id;
        }
        void printMachine() {
            cout<<"\nMachine id : "<<machineId;
        }
};
class Tub {
    private: 
        int capacity;
    public:
        Tub() { }
        void setTub(int cap) {
            capacity = cap;
        }
        void printTub() {
            cout<<"\nTub Capacity : "<<capacity;
        }
};
class WashingTub : public Tub {
    private:
        int rpm;
        string type; //steel, platic
    public:
        WashingTub() { }
        void setWashingTub(int cap, int r, string t)  {
            Tub::setTub(cap);
            rpm = r;
            type = t;
        }
        void printWashingTub() {
            Tub::printTub(); //super.printTub();
            cout<<"\nWashing Tub RPM  : "<<rpm;
            cout<<"\nWashing Tub Type : "<<type;
        }
};

//class Powder;
//class WashingPowder; //forward declaration of the class

class Powder{
    private:
        int quantity;
    public:
        Powder(int q) 
        { 
            quantity=q;
        }
        void setPowder(int q) {
            quantity=q;
        }
        void printPowder() {
            cout<<"\nPowder qty : "<<quantity;
        }
};
class WashingPowder : public Powder {
    private:
        string brand;
    public:
        WashingPowder(int q):Powder(q) {

        }

        void setWashingPowder(string b) {
            brand=b;
        }
        void printWashingPowder() {
            Powder::printPowder();
            cout<<"\nBrand : "<<brand;
        }
 };

class Power { 
    string provider;
    public:
        void setPower(string pro) {
            provider = pro;
        }
        void printPower() {
            cout<<"\nPower Provider : "<<provider;
        }
};
class Electricity : public Power {
    float voltage;
    public:
        void setElectricity(float volt) {
            voltage = volt;
        }
        void printElectricity() {
            Power::printPower();
            cout<<"\nElectricity Voltage : "<<voltage;
        }
};
class Water{
    int quantity;
    public:
        void setWater(int q) {
            quantity =q;
        }
        void printWater() {
            cout<<"\nWater : "<<quantity<<" ltrs";
        }
};

class Cloth{
    public:
    string type; //cotton
    float weight; //250gm
    string color; 
    bool isClean; //false
    void setCloth(string t, string col, float w, bool isCl) {
        type=t;
        weight=w;
        color=col;
        isClean = isCl;
    }
    void printCloth() {
        cout<<"\nCloth Type    : "<<type;
        cout<<"\nCloth Color   : "<<color;
        cout<<"\nCloth Weight  : "<<weight;
        cout<<"\nCloth isClean : "<<isClean;
        
    }

};
class Laundry
{
    float waterBill;
    float detergentBill;
    float electricityBill;
    float ironingCost;
    float paperCostForPacking;
    float total;
    void calculate() {
        total = waterBill + detergentBill + electricityBill + ironingCost+paperCostForPacking;
    }
    public:
        void setLaundry(float wb, float db, float eb, float ic, float pcfp) {
             waterBill=wb;
             detergentBill=db;
             electricityBill=eb;
             ironingCost=ic;
             paperCostForPacking=pcfp;
             calculate();
        }
        
        void showLaundry() {
            cout<<"\nWater bill     : "<<waterBill;
            cout<<"\nDetergent bill : "<<detergentBill;
            cout<<"\nPower bill     : "<<electricityBill;
            cout<<"\nIroning bill   : "<<ironingCost;
            cout<<"\n------Total----: "<<total;
        }

};
class WashingMachine : public Machine{ //isA
        WashingTub washTub; //hasA
        string brand;
    public:
        WashingMachine(int id, string brnd, int cap, int rpm, string type ) : Machine(id) {
            brand=brnd;
            washTub.setWashingTub(cap,rpm,type);
        }
    public:
        Laundry wash(WashingPowder washPowder, Electricity electricity, 
                Water water, Cloth cloth) { 
            cout<<"\nBrand : "<<brand;
            Machine::printMachine();
            washTub.printWashingTub();
            washPowder.printWashingPowder();
            electricity.printElectricity();
            water.printWater();
            cloth.printCloth();

            Laundry laundry;
            laundry.setLaundry(20,20,10,7,3);
            return laundry;
        }   
    private: void rinse() { }
    private: void spin() { }
}; //isA
/*---------------------------*/

/*---------------------------*/

/*---------------------------*/



int main() {

    WashingPowder washPowder(50);
    washPowder.setWashingPowder("Ariel");

    Electricity electricity;
    electricity.setPower("Tata Power");
    electricity.setElectricity(220.0f);

    Water water;
    water.setWater(40);//ltrs
    
    Cloth cloth;
    cloth.setCloth("Cotton","Shirt", 250, false);  

    WashingMachine  machine(101,"Samsung",50,500,"Steel Tub");
    Laundry theLaundry = machine.wash(washPowder, 
                            electricity, water, cloth);
    cout<<"\n------after wash-----\n";    
    theLaundry.showLaundry();
    return 0;
}
//