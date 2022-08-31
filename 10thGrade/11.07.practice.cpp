#include <iostream>
#include <cstring>

using namespace std;

class MyString{
    private:
        char *buffer;
        int size;
        int capacity;

    public:
        MyString(){
            capacity = 20;
            size = 0;
            buffer = new char[capacity]();
            buffer[0] = '\0';
        }

        MyString(string str){
            capacity = str.size() *2;
            size = str.size();
            buffer = strdup(str.c_str());
        }

        MyString(const MyString &other){
            size = other.size;
            capacity = other.capacity;
            buffer = strdup(other.buffer);
        }

        MyString &operator=(const MyString &other){
            size = other.size;
            capacity = other.capacity;
            buffer = strdup(other.buffer);

            return *this;
        }

        void setSize(int Size){
            size = Size;
        }

        void setCapacity(int Capacity){
            capacity = Capacity;
        }

        void setBuffer(char *str){
            buffer = str;
        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        char* getBuffer(){
            return buffer;
        }

        void append(string str){
            int len = str.size() + getSize();
            if(len+1 > getCapacity()){
                setCapacity((len+1)*2);
                setBuffer((char *)realloc(getBuffer(), getCapacity()));
            }

            strcat(getBuffer(), str.c_str());
            setSize(len);
        }

};

int main(){
    MyString str("neshto");
    MyString str2(" test");
    string str3 = " test";
    str.append(str3);
    cout << str.getBuffer() << endl;

    return 0;
}