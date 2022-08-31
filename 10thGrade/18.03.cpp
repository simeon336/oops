#include<iostream>
#include<cstring>

using namespace std;

class Warrior{
    char* name;
    size_t strenght;


public:
    Warrior(){}

    Warrior(const char* name, size_t strenght)
    :strenght(strenght)
    {
        if(!this->name) return;

        this->name = strdup(name);
    }

    Warrior(const Warrior& other)
    : strenght(other.strenght)
    {
        this->name = strdup(other.name);
    }
    ~Warrior(){
        delete [] this->name;   
    }
    Warrior& operator=(const Warrior& other){
        if(this != &other){
            delete [] this->name;

            this->name = strdup(other.name);
            this->strenght = other.strenght;
        }

        return *this;
    }

    char* getName() const { return this->name; }
    size_t getStrenght() const { return this->strenght;}
};

class Army{

    /**
     * @brief Add name of the army, number of warriors, array of warriors and capacity of the array.
     * 
     */
    string name_army;
    int num_war;
    int war[];
    void resize() ;

public:

    /**
     * @brief Construct a new Army object
     * 
     * @param name 
     */
    Army(const char* name);

    /**
     * @brief Construct a new Army object (Copy constructor)
     * 
     * @param other 
     */
    Army(const Army& other);
    /**
    * @brief Destructor
    */
    ~Army();
    /**
     * @brief Assign operator
     * 
     * @param other 
     * @return Army 
     */
    Army& operator=(const Army& other);
    /**
     * @brief Add unique warrior. Return -1 if exist, return 0 if success
     * 
     * @param other 
     * @return int 
     */
    int addWarrior(const Warrior& other);

    char* getName()const ;

    size_t getNumberOfWarriors()const ;

    Warrior& getWarrior(const char* name)const;
};


int main(int argc, char* argv[]){
    Warrior w1("Orc", 10);
    Warrior w2("Hobit",  100);
    
    Army a1("Orcs");
    a1.addWarrior(w1);
    cout<<"Warriors in a1 "<< a1.getName() << ": " << a1.getNumberOfWarriors() << endl; //Warriors in a1 Orcs: 1


    Army a2 = a1;
    cout<< "Successful addition: " << a2.addWarrior(w2) << endl; // Successful addition: 0
    cout<<"Warriors in a2 "<< a2.getName() << ": " << a2.getNumberOfWarriors() << endl; // Warriors in a2 Orcs: 2


    Army a3("Hobits");
    a3 = a2;
    cout << "Adding duplicate: " << a3.addWarrior(w1) << endl; //Adding duplicate: -1
    cout<<"Warriors in a3 "<< a3.getName() << ": " << a3.getNumberOfWarriors() << endl; //Warriors in a3 Orcs: 2


    cout << "Strenght of the warrior Hobit :" << a3.getWarrior("Hobit").getStrenght() << endl; //Strenght of the warrior Hobit: 100

}