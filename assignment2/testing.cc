#include <iostream>
using namespace std;

int main(){
    int x = 0;
    int y = x;
    int& z = x;
    z = 10;
    cout << x << ", "<< y <<", "<< z;

    return 0;
}