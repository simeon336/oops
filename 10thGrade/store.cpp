#include <iostream>
#include<cstring>

using namespace std;

class Product{
    private:
        string name;
        unsigned int quantity;
        double price;
    public:
        Product(){
            name = "";
            quantity = -1;
            price = -1;
        }

        Product(string Name, unsigned int Quantity, double Price){
            name = Name;
            quantity = Quantity;
            price = Price;
            if(price < 0){
                price = -1;
            }
        }

        Product(const Product & other){
            name = other.name;
            quantity = other.quantity;
            price = other.price;
        }

        Product& operator=(const Product & other){
            name = other.name;
            quantity = other.quantity;
            price = other.price;

            return *this;
        }

        void setPrice(double Price){
            price = Price;
        }

        void setQuantity(unsigned int Quantity){
            quantity = Quantity;
        }

        string getName(){
            return name;
        }

        unsigned int getQuantity(){
            return quantity;
        }

        double getPrice(){
            return price;
        }


};

class Property{
    private:
        string address;
        double rent;
        string propertyType;

        void restrictionAddress(string Address){
            if(propertyType != "supermarket" && propertyType != "pharmacy" && propertyType != "non-stop" && propertyType != "other"){
                throw "Invalid property type! Please enter one of the following: supermarket; pharmacy; non-stop; other.";
            }
        }

        void restrictionRent(double Rent){
            if(Rent < 0){
                throw "Rent must be greater than zero";
            }
        }
        public:
            Property(string Address, double Rent, string PropertyType){
                address = Address;
                rent = Rent;
                propertyType = PropertyType;
            }

            Property(const Property & other){
                address = other.address;
                rent = other.rent;
                propertyType = other.propertyType;
            }

            Property& operator =(const Property & other){
                address = other.address;
                rent = other.rent;
                propertyType = other.propertyType;

                return *this;
            }

            string getAddress(){
                return address;
            }

            string getPropertyType(){
                return propertyType;
            }

            double RentCalculator(double rent, string propertyType){
                if(propertyType == "supermartket"){
                    return rent + rent*0.4;
                }else if(propertyType == "pharmacy"){
                    return rent + rent*0.3;
                }else if(propertyType == "non-stop"){
                    return rent + rent*0.2;
                }else{
                    return rent;
                }
            }

   
};