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

class WashingMachine : public {//isA
        WashingTub washTub; //hasA
        string brand;
    public:
        WashingMachine(int id, string brnd, int cap, int rpm, string type ) : Machine(id) {
            brand=brnd;
            washTub.setWashingTub(cap,rpm,type);
        }
    public:
        void wash() { 
            cout<<"\nBrand : "<<brand;
            Machine::printMachine();
            washTub.printWashingTub();
        }   
    private: void rinse() { }
    private: void spin() { }
}; //isA
/*---------------------------*/
class Powder{};
class WashingPowder : public Powder { };
/*---------------------------*/
class Power { };
class Electricity : public Power { };
/*---------------------------*/
class Cloth{};
class Water{};

int main() {

    WashingMachine  machine(101,"Samsung",50,500,"Steel Tub");
    machine.wash();
    return 0;
}
