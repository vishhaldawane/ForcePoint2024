#include <iostream>
using namespace std;
class Fruit
{
    private:
        string name;
        string color;
        string taste;
        float weight;
        bool ripen;
    public:
        Fruit(string nm,string col, string tst, float w, bool r) {
            name=nm;
            color=col;
            taste=tst;
            weight=w;
            ripen=r;
        }
        void printFruit() {
            cout<<"\nFruit Name   : "<<name;
            cout<<"\nFruit Color  : "<<color;
            cout<<"\nFruit Taste  : "<<taste;
            cout<<"\nFruit Weight : "<<weight;
            cout<<"\nFruit Ripen  : "<<ripen<<"\n";
        }
};
int main() {
    Fruit mango("Alphanso","Yellow","Sweet",250.4,true);
    mango.printFruit();

}