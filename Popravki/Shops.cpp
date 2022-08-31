#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
        string name;
        unsigned int kolichestvo;
        double price;
    
    public:
        Product(){}
        Product(string name, unsigned int kolichestvo, double price){
            this->name = name;
            this->kolichestvo = kolichestvo;
            if(price < 0){
                throw invalid_argument("Price cant be nagative!");
            }
            this->price = price;
        }
        
        Product(const Product &other){
            name = other.name;
            kolichestvo = other.kolichestvo;
            price = other.price;
        }

        Product& operator=(const Product &other){
            if(this != &other){
                name = other.name;
                kolichestvo = other.kolichestvo;
                price = other.price;
            }
            return *this;
        }

        string getName()const{
            return this->name;
        }

        unsigned int getKolichestvo()const{
            return this->kolichestvo;
        }

        double getPrice()const{
            return this->price;
        }

        void setPrice(double price){
            this->price = price;
        }

        void setKolichestvo(unsigned int kolichestvo){
            this->kolichestvo = kolichestvo;
        }
};

class Property{
    private:
        string address;
        double basicLoan;
        string type;
    
    public:
        Property(string address, double basicLoan, string type){
            if(type != "supermarket" && type != "pharmacy" && type != "non-stop" && type != "other"){
                throw invalid_argument("Invalid type.");
            }
            if(basicLoan < 0){
                throw invalid_argument("Basic Loan cant be a negative number");
            }
            this->address = address;
            this->basicLoan = basicLoan;
            this->type = type;
        }

        Property(const Property &other){
            address = other.address;
            basicLoan = other.basicLoan;
            type = other.type;
        }

        Property& operator=(const Property &other){
            if(this != &other){
                address = other.address;
                basicLoan = other.basicLoan;
                type = other.type;
            }
            return *this;
        }

        string getType()const{
            return this->type;
        }

        string getAddress()const{
            return this->address;
        }

        double loanCalc(string type){
            if(type == "supermarket"){
                return this->basicLoan + 0.4*this->basicLoan;
            }
            if(type == "pharmacy"){
                return this->basicLoan + 0.3*this->basicLoan;
            } 
            if(type == "non-stop"){
                return this->basicLoan + 0.2*this->basicLoan;
            } 
            return this->basicLoan;
        }
};

class Store : public Property{
    private:
        string name;
        
}

int main(){
    Property magazin("Shaban 336", 30, "pharmacy");
    cout << magazin.loanCalc(magazin.getType()) << endl;
}