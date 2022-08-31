#include <iostream>

using namespace std;


class Student{
    private:
        string name;
        unsigned int classs;
        char classSymbol;
        unsigned int numInClass;
    
    public:
        void set_name(string Name){
            name = Name;
        }

        void set_class(unsigned int Classs){
            classs = Classs;
        }

        void set_classSymbol(char Symbol){
            classSymbol = Symbol;
        }

        void set_numInClass(unsigned int num){
            numInClass = num;
        }

        string getName(){
            return name;
        }

        unsigned int getClass(){
            return classs;
        }

        char get_classSymbol(){
            return classSymbol;
        }

        unsigned int get_classNum(){
            return numInClass;
        }

        Student(string Name, unsigned int Classs, char Symbol, unsigned int num){
            name = Name;
            classs = Classs;
            classSymbol = Symbol;
            numInClass = num;
        }

        Student(const Student & other){
            name = other.name;
            classs = other.classs;
            classSymbol = other.classSymbol;
            numInClass = other.numInClass;
        }

        Student & operator=(const Student & other){
            name = other.name;
            classs = other.classs;
            classSymbol = other.classSymbol;
            numInClass = other.numInClass;

            return *this;
        }
};

int main(){

    return 0;
}