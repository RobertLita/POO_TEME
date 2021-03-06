#include <iostream>
#include <cmath>
using namespace std;

//// TODO Mostenire, practic avem mai multe tipuri de obiecte foarte similare
////  Spre exemplu tipuri de masini: EV, Convertible

//// The parent class may be named Base Class, and the Children Derived

class Car {
public:
    void horn() {
        cout << "a Car horns" << endl;
    }

    // TODO constructorul este la fel pt Car,
    //  !! deoarece *protected* se comporta tot ca *private* in clasa in cate este folosit
    Car() : m_autonomy(0), m_mileage(0) {}

    Car(const int autonomy, const int mileage) : m_autonomy(autonomy), m_mileage(mileage) {}

    friend ostream &operator<<(ostream &os, const Car &car) {
        os << "m_autonomy: " << car.m_autonomy << " m_mileage: " << car.m_mileage;
        return os;
    }

protected:
    int m_autonomy;
private:
    int m_mileage;
};

//// TODO in program, mostenirea inseamna ca o clasa (Derived) refoloseste
////  implementarile clasei parinte (Base).
//// TODO poate fi preluat:
////  * campuri membre (NU STATICE, deoarece ele vor ramane asociate cu parintele intotdeauna)
////  * metodele membre (deoarece continem toate campurile din parinte, si metodele pot fi folosite)
//
//// TODO CUM DECIDEM *private* vs *protected* :D
////  E simplu, ne intrebam daca vrem ca ele sa fie accesibile si in fiu :D
////  * vrem sa fie accesibile in fii? Le facem protected
////  * vrem sa devina inaccesibile in fii? Le facem private (asta ar avea sens spre exemplu la id-uri generate automat.
///                                                             De ce sa le modificam si-n fii daca s-a ocupat clasa parinte de ele?)

class Convertible : public Car { // mosteneste public clasa Car
public:
    void horn() {
        // inca putem folosi pe cea din clasa de baza
        Car::horn();
        cout << "a Convertible horns" << endl;
    }

    Convertible(bool isWaterProof)
            : Car(), m_isWaterProof(isWaterProof) { // TODO delegam constructor din clasa de baza,
        //                                                                      pt ca e f probabil noi sa nu avem acces
        //                                                                      la toti membrii de acolo :D
    }

    friend ostream &operator<<(ostream &os, const Convertible &convertible) {
        os << (const Car &) convertible << " m_isWaterProof: " << convertible.m_isWaterProof;
        return os;
    }

    // TODO mostenirea public se comporta cam asa:
    //  private -> Ce in parinte era private, ramane private dar inaccesibil direct(
    //          am putea folosi getters si setters pt a le accese)
    //  protected -> Ce in parinte era protected, devine private dar accesibil direct in Convertible:
//    Convertible() {   // uncomment to see that m_autonomy is accesible, whereas m_mileage is not
//        m_autonomy;   //  private dar accesibil direct in Convertible:
//        m_mileage;    // inaccesibile in the derived class, because it was private in parent class !!!
//    }
    //  public -> la mostenire *publica*, ce era public in parinte ramane public

protected:
private:
    bool m_isWaterProof;
};

// TODO code 1 to 2 more "Cars" (EV, RV, LuxCar, RaceCar etc) that
//  1. inherit the base (Car) class
//  2. also implement the operator<< output stream operator,
//  3. and contain additional data like batteryLife (EV), squareMeters and hasKitchen (RV), timeToHundred(RaceCar), priceToRent (LuxCar :)).)
//  * YES, they also need to contain a default constructor and a fully parametrized constructor,
//      the reason is that these are the typical methods needed for fully functional and easy to test in main objects


// TODO your code :D

class EV : public Car{
private:
    float batteryLife;
    bool hasFastCharging;
public:
    void horn() {
        Car::horn();
        cout << "an EV horns" << '\n';
    }
    EV(float batterylife,bool hasfastcharging): Car(),batteryLife(batterylife),hasFastCharging(hasfastcharging){}
    friend ostream &operator<<(ostream &os, const EV &ev) {
        os << (const Car &) ev << " m_batteryLife: " << ev.batteryLife<<" m_hasFastCharging: "<<ev.hasFastCharging;
        return os;
    }
};

class RaceCar : public Car{
private:
    float timeToHundred;
public:
    void horn() {
        Car::horn();
        cout << "an EV horns" << endl;
    }
    explicit RaceCar(float timetohundred): Car(),timeToHundred(timetohundred){}
    friend ostream &operator<<(ostream &os, const RaceCar &rc) {
        os << (const Car &) rc << " m_timeToHundred: " << rc.timeToHundred;
        return os;
    }
};

/*
 *  TODO II  Shape and its children :D
 *
 *      TODO The requirements can be found after the three classes below:
 */



// Exemplu practic pt functii virtuale

// TODO in cel mai practic mod, virtual inseamna ca o functie denumite la fel ca-n parinte
//  se comporta diferit in fiecare dintre clasele derivate diferit
//  In PLUS, vrem sa oferim mai mult dinamism, deoarece ea se va comporta diferit dar apelul va fi identic,
//      deci cu ajutorul pointerilor/referintelor catre clasa de baza vom putea crea array-uri de tipuri diferite
//      care se comporta diferit. Oricum, mai bine trecem la partea practica :)

// Clasa de baza:   Shape
// Clase derivate:  Square, Circle

// Ce au in comun? Toate au si inaltime. Toate am vrea sa aiba o functie de calculare volum
// Cum difera? Difera prin implementarea functiei de volum


class Shape {
public:
    Shape(float height) : m_height(height) {}

    // virtual este un cuvant cheie de pus in fata unei functii,
    //  si inseamna ca acea functie se comporta diferit pt clasele derivate, si e de asteptat sa fie
    //  reimplemenentata in clasele mostenitoare.
    virtual float volume() {           // TODO doar in parinte vom folosi virtual, deoarece ne spune cum se
        //                                 comporta la "mostenire", iar noi nu mai nostenim Circle or Square
        return -1;
    }
    virtual float baseArea(){
        return -1;
    }

protected:
    float m_height;
};

class Circle : public Shape {
public:
    float baseArea(){
        return 3.14 * m_radius * m_radius;
    }
    float volume() {
        return baseArea() * m_height;
    }

    Circle(float height, float radius) : Shape(height), m_radius(radius) {}

private:
    float m_radius;

};

class Square : public Shape {
public:
    Square(const float height, const float side) : Shape(height), m_side(side) {}

    float baseArea(){
        return m_side * m_side;
    }
    float volume() {
        return baseArea() * m_height;
    }


private:
    float m_side;
};

//
// TODO code 2 more "Shapes" that inherit the base (Shape) class, then add one more virtual function
//  (e.g Triangle, Hexagon, Polygon - number of sides and the size of a side, sides should be equal -
//   Ellipse, or just be creative :)).)
//  1. The derived classes will contain an "float volume()" member function
//  2. Also implement one more virtual function inside the parent class, namely "virtual float Shape::baseArea()"
//  3. Then implement member functions like "virtual float baseArea()" for each of your chosen derived classes
//      AND use it to computer the volume inside all the classes (at least all your chosen classes, but you may also
//      use it for predefined classes like Square and Circle)
//     Practically, the code inside volume may become   float volume() { return baseArea() * m_height; }
//  4. Add new code to the main() function, by allocating one more Shape for each new types you chose to implement
//      then adding them to the same pointers array and calling the volume function.

// TODO your code :D

class Triangle : public Shape{
private:
    float m_l1,m_l2,m_l3;
public:
    Triangle(const float height, const float l1, const float l2, const float l3): Shape(height), m_l1(l1), m_l2(l2), m_l3(l3){}
    float baseArea(){
        float p = (m_l1 + m_l2 + m_l3) / 2;
        return sqrt(p * (p - m_l1) * (p - m_l2) * (p - m_l3));
    }
    float volume(){
        return baseArea() * m_height;
    }
};

class Dodecagon : public Shape{
private:
    float m_side;
public:
    Dodecagon(const float height,const float side) : Shape(height), m_side(side){}
    float baseArea(){
        return 3 * m_side * m_side * 3.73; //(2 + sqrt(3))
    }
    float volume(){
        return baseArea() * m_height;
    }
};


// Scopul nostru este sa putem calcula foarte usor volumun cu orice
int main() {
    Circle *circle = new Circle(2, 3); // inaltime si raza.
    // retine adresa unui cerc
    Square *square = new Square(4, 3);  // inaltime si latura patratului
    // TODO dynamically declare two more shapes

    Triangle *triangle = new Triangle(5,3,4,6);
    Dodecagon *dodecagon = new Dodecagon(10,8.5);

    // TODO add two more shapes to the array
    Shape *shapes[10] = {circle, square, triangle, dodecagon};

    cout << shapes[0]->volume() << '\n';
    cout << shapes[1]->volume() << '\n';
    cout << shapes[2]->volume() << '\n';
    cout << shapes[3]->volume() << '\n';
    // TODO call two more shapes from the array

}
