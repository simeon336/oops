#include <iostream>

using namespace std;

class Person{
    string name; //
    int age;
    string egn;
    string address;

    Person()
    {}

    Person(string name, string egn, string address, int age = 14)
    :name(name)
    ,egn(egn)
    ,address(address)
    ,age(age)
    {
        if(name.empty()){
            throw invalid_argument("Invalid name");
        }
        if(egn.empty() || egn.size() !=){
            throw invalid_argument("Invalid EGN provided");
        } address.empty()){
            
        }
    }
};
