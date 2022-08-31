#include <iostream>
#include <string>

using namespace std;

class StudentMarks{
    private:
        double *marks;
        unsigned int size;
        unsigned int capacity;
        string studentName;
    
    public:
        StudentMarks(){
            marks = new double[this->capacity];
            marks[0] = 2.00;
            studentName = '/0';
        }

        StudentMarks(double *marks, unsigned int size, unsigned int capacity, string studentName){
            for(int i = 0; i < this->size, i++){
                if(marks[i] < 2 || marks[i] > 6){
                    throw invalid_argument("Marks should be blah blah");
                }
                marks = new double[capacity];
                this->marks = marks;
                this->size = size;
                this->capacity = capacity;
                this->studentName = studentName;
            }
        }

        StudentMarks(const StudentMarks &other){
            this->capacity = other.capacity;
            this->marks = other.marks;
            this->size = other.size;
            this->studentName = other.studentName;
        }
};