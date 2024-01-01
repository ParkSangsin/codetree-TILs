#include <iostream>
using namespace std;

int main() {
    int weight = 13;
    double rate = 0.165;
    
    cout << fixed;

    cout << weight << " * " ;

    cout.precision(6);
    cout << rate << " = " << weight * rate;
    return 0;
}