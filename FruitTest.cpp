#include <iostream>
using namespace std;
class Fruit //UDT - user defined data type
{
    private:
        string name;
        string color;
        string taste;
        float weight;
        bool ripen;
        string shape;

    public:
        Fruit(string nm,string col, string tst, float w, bool r,string shp) {
            name=nm;
            color=col;
            taste=tst;
            weight=w;
            ripen=r;
            shape=shp;
        }
        void printFruit() {
            cout<<"\nFruit Name   : "<<name;
            cout<<"\nFruit Color  : "<<color;
            cout<<"\nFruit Taste  : "<<taste;
            cout<<"\nFruit Weight : "<<weight;
            cout<<"\nFruit Ripen  : "<<ripen;
            cout<<"\nFruit Shape  : "<<shape<<"\n";

        }
};
int main() {
    int   i;
    Fruit mango("Alphanso","Yellow","Sweet",250.4,true,"oval");
    Fruit apple("Kashmiri Apple","Red","Sweet",125.5,true,"rounded");
    Fruit orange("Nagpur Orange","Orange","SourSweet",150.2,true,"round");
    Fruit jackfruit("KokanJackfruit","Pale Yellow","PulpySweet",3250.0,true,"Big Oval");

    mango.printFruit();
    apple.printFruit();
    orange.printFruit();
    jackfruit.printFruit();


}