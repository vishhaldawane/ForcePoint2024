#include <iostream>
#include <stdio.h>
using namespace std;
/*
                        Animal
                           | breathing() { }
            ----------------------------------
            |              |                |
  L      Bird            Mammal            Fish             R 
        | fly()         |walk() |            | swim()
        |               |       +--------+   |           
    +--------+       +-------------+     |   +-----------+
    |        |       |             |     |   |           | 
    Parrot  FlyingMammal          Tiger SwimmingMammal  Sword
                Bottom

Dreaded diamond - death of a diamond

*/
class Animal {
    public:
    Animal() {
        cout<<"\nAnimal....ctor...";

    }
    void breathing() {
        cout<<"\nAnimal is breathing....";
    }
};
//virtual base classes [ plural term ]

class Bird : public virtual Animal {
    public:
        Bird() {
            cout<<"\nBird ctor...";
        }
        void fly() {
            cout<<"\nBird is flying...";
        }
        void layEggs() {
            cout<<"\nBird is laying eggs......";
        }
        void breathing() {
            cout<<"\nBird is breathing....";
        }
};

class Mammal : public virtual Animal  {
    public:
        Mammal() {
            cout<<"\nMammal ctor...";
        }
        void walk() {
            cout<<"\nMammal is walking...";
        }
        void givingBirth() {
            cout<<"\nMammal is giving birth...";
        }
        void breathing() {
            cout<<"\nMammal is breathing....";
        }
};


class FlyingMammal : public Bird, public Mammal {
    public:
    FlyingMammal() {
        cout<<"\nFlyingMammal ctor...";
    }
    void hangingInvertly() {
        cout<<"\nFlying mammal is haning invertly....";
    }
    void fly() {
        cout<<"\nFlying mammal is using ultrasound...while flying...";
    }
    void givingBirth() {
        cout<<"\nFlying mammal is giving birth....";
    }
    void walk() {
            cout<<"\nFlying mammal  is walking..on the tree branch...";
    }
    void layEggs() {
        cout<<"\nFlying mammal is NOT laying eggs......";
    }
    void breathing() {
       
       // Bird::breathing();
       // Mammal::breathing();
        cout<<"\nFlyingMammal is breathing....";
    }
};

int main() {

    Bird bird;
    bird.layEggs();
    bird.layEggs();
    bird.breathing();
    cout<<"\n-----------";

    Mammal mammal;
    mammal.givingBirth();
    mammal.walk();
    mammal.breathing();
    cout<<"\n-----------";

    FlyingMammal bat;
    bat.fly();
    bat.givingBirth();
    bat.hangingInvertly();
    bat.layEggs();
    bat.walk();
   // bat.breathing();
    bat.Animal::breathing();
    bat.Bird::breathing();
    bat.Mammal::breathing();
    return 0;
}

/*


class Parrot : public Bird {
    public:
        Parrot() {
            cout<<"\nParrot ctor...";
        }
        void fly() {
            cout<<"\nParrot is flying...";
        }
        void layEggs() {
            cout<<"\nParrot  is laying eggs......";
        }
};

class Tiger : public Mammal {
    public:
        Tiger() {
            cout<<"\nTiger ctor...";
        }
        void walk() {
            cout<<"\nTiger is walking...";
        }
        void givingBirth() {
            cout<<"\nTiger is giving birth...";
        }
};
*/