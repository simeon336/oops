#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Machine{
public:
    Machine(string brand, int power, int mass){
        if(power <= 0){
            throw invalid_argument("Invalid power provided!");
        }
        if(mass <= 0){
            throw invalid_argument("Invalid mass provided!");
        }
        if(brand.empty()){
            throw invalid_argument("Invalid brand provided!");
        }

        this->brand = brand;
        this->power = power;
        this->mass = mass;

    };

    Machine(const Machine& other){
        brand = other.brand;
        power = other.power;
        mass = other.mass;
    };
    Machine& operator=(const Machine& other){
        brand = other.brand;
        power = other.power;
        mass = other.mass;

        return *this;
    };

    double calculateTraction()const{
        // Leave it empty
    };
    
    string getBrand(){
        return brand;
    }

    int getPower(){
        return power;
    }

    int getMass(){
        return mass;
    }


    string brand;
    int power;
    int mass;
    //Getters
};


class Car : public Machine{
public:
    Car(const string& brand, int power, int mass) : Machine(brand, power, mass) {};

    Car(const Car& other);
    Car& operator=(const Car& other);
    double calculateTraction()const{
        double result = (mass*power)/100;
        return result;
    }; /* power*mass / 100 */


};

class Motorcycle : public Machine{
public:
    Motorcycle(const string& brand, int power, int mass) : Machine(brand, power, mass) {};
    Motorcycle(const Motorcycle& other);
    Motorcycle& operator=(const Motorcycle& other);

    double calculateTraction()const{
        double result = (power*mass)/100;
        return result;
    }; /* power*mass / 100 */
};

class Track{

public: 
    static int race(const Car& car, const Motorcycle& cycle){
        float resultCar = car.power/car.mass + car.calculateTraction();
        float resultCycle = cycle.power/cycle.mass + cycle.calculateTraction();

        if(resultCar > resultCycle){
            return -1;
        }
        if(resultCycle < resultCar){
            return 1;
        }
        if(resultCar == resultCycle){
            return 0;
        }
    };
};

int main(){
    
    string carName;
    string cycleName;
    int carMass;
    int cycleMass;
    int carPower;
    int cyclePower;

    ifstream readFile;
    readFile.open("input.txt");

    
    return 0;
}