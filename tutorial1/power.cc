using namespace std;

void power(int a, int b, int &c){
    int result = 1;
    for(int i = 0; i < b; ++i){
        result = result * a;
    }

    c = result;
}