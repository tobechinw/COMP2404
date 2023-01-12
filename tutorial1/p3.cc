#include "iostream"

using namespace std;

void power(int a, int b, int &c);

int main(){
    int a, b, c;
    cout<<"Please enter two integers: ";
    cin >> a >> b;

    power(a, b, c);

    cout << a << " to the power " << b <<" is " <<c <<"!" <<endl;
    return 0;
}