#include <iostream>
#include <fstream>

using namespace std;

int main(){

    fstream f;
    f.open("example.txt", ios::in | ios::out | ios::app);

    return 0;
}