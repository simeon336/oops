#include <iostream>
#include <vector>
using namespace std;

class Student {
    private:
    int number;
    string firstName;
    string LastName;
    int year;

    public: 
    void setNumber(int num){
        number = num;
    }
    void setFirstName(string fName){
        firstName = fName;
    }
        void setLastName(string lName){
        LastName = lName;
    }
    void setYear(int Year){
        year = Year;
    }

    int getNumber(){
        return number;
    }
    string getFirstName(){
        return firstName;
    }
    string getLastName(){
        return LastName;
    }
    int getYear(){
        return year;
    }
    Student(int num, string fName, string lName, int _year){
        number = num;
        firstName = fName;
        LastName = lName;
        year = _year;
    }
    Student(){
        number = -1;
        firstName = "";
        LastName = "";
        year = -1;
    }
    Student(const Student & other){
        number = other.number;
        firstName = other.firstName;
        LastName = other.LastName;
        year = other.year;
    }
    Student& operator=(const Student & other){
        number = other.number;
        firstName = other.firstName;
        LastName = other.LastName;
        year = other.year;

        return *this;
    }
};

class RecordBook{
    private:
    vector<Student> students;

    public:
    void addStudent(Student student){
        students.push_back(student);
    }
    void printStudents(){
        for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
            Student student = *it;
            cout << student.getFirstName() << endl;
            cout << student.getLastName() << endl;
            cout << student.getNumber() << endl;
            cout << student.getYear() << endl;

        }
    
    }
};

int main(){
    Student student(3, "Mario", "Ivanov", 2019);
    Student ivan(4, "Ivan", "Mariv", 2019);
    Student pesho(5, "Petyr", "Stanislavov", 2019);

    RecordBook book;
    book.addStudent(student);
    book.addStudent(ivan);
    book.addStudent(pesho);

    book.printStudents();
    

    return 0;
}