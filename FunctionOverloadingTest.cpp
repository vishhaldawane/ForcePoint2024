#include <iostream>
using namespace std;

class Phone
{
    public:
    void dial(string name) {
        cout<<"\ndialing to "<<name;
    }
    void dial(string name1, string name2) {
        cout<<"\ndialing conference call to "<<name1<< " and "<<name2;
    }
    void dial(int speedDial) {
        cout<<"\ndialing to "<<speedDial;
    }
    void dial(int speedDial, float duration) {
        cout<<"\ndialing to "<<speedDial<<" talking for "<<duration<<" minutes";
    }
};
int main() {
    Phone myPhone;
    myPhone.dial("Harshiny");
    myPhone.dial(123);
    myPhone.dial("Shilpa","Sheetal");

    myPhone.dial(122,4.5);
}