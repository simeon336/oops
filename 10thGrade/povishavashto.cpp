#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    private:
        char* buffer;
        int size;
        int capacity;

    public:
        MyString(){
            
            this->buffer = strdup(buffer);
            this->size = -1;
            this->capacity = -1;
        }

        
        
        MyString(string buffer, int size, int capacity){

        
            
            this->buffer = strdup(buffer.c_str());
            this->size = size;
            this->capacity = capacity;
        }

        MyString(const MyString & other){
      
            buffer = strdup(other.buffer);
            size = other.size;
            capacity = other.capacity;
        }

        MyString& operator=(const MyString & other){
            if(this != &other){
                buffer = strdup(other.buffer);
                size = other.size;
                capacity = other.capacity;
            }

            return *this;
        }

        char* getBuffer()const{
            return buffer;
        }
        
        int getSize()const{
            return size;
        }

        int getCapacity()const{
            return capacity;
        }

        void Append(const string str){
            this->buffer = strdup(buffer);
            int len2 = str.size();
            capacity += len2;
            strcat(buffer, str.c_str());
        }

};

int main(){
    int size = 40;
    int capacity = 50;
    string str = "string";
    string str2 = "kate";
    MyString mystr(str, size, capacity);
    mystr.Append(str2);
    cout << mystr.getBuffer() << endl;

}