#include<iostream>
#define NAME_SIZE 50
using namespace std;

class Planet{
    private:
    char *PlanetName;
    double distance;
    double PlanetDiameter;
    double masa;
public:
    //TODO add getters and setters
    Planet(char *name, double distanceToSun, double diameter, double weight){
        cout << "Hello from constructor:)" << endl;
    }
    
    /*  PlanetName = name;
        distance = distanceToSun;
        PlanetDiameter = diameter;
        masa = weight; */

    void print(){
        cout << "Planet name: " << PlanetName << endl;
        cout << "Distance to Sun: " << distance << endl;
        cout << "Diameter of the planet: " << PlanetDiameter << endl;
        cout << "Weight of the planet: " << masa << endl;
    }

    double getSecondsToSun(){
        double time;
        time = distance / 299792;
        return time;
    }
    ~Planet(){
        cout << "Hello from destructor:)";
    };
};

int main(){
    Planet planeta();
    char* ime = new char[NAME_SIZE];
    double dist;
    double diam;
    double mass;

    cout << "Enter planet name: ";
    for(int i = 0; i != NAME_SIZE; ++i){
        cin >> ime[i];
        if(ime[i] == '\n'){
            ime[i] = '\0';
            break;
        }
    }
    cout << "Enter distance to Sun in km: ";
    cin >> dist;
    cout << "Enter the diameter of the planet: ";
    cin >> diam;
    cout << "Enter the weight of the planet: ";
    cin >> mass;

    Planet planeta(ime,);

    //Get the name from the console
    //Then create an object of type Planet and test all the methods.
    cout << "Time to the sun in seconds: " << planeta.getSecondsToSun() << "s" << endl;
    return 0;
}