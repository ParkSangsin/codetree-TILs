#include <iostream>
using namespace std;

int main() {
    double ft = 30.48;

    cout << fixed;
    cout.precision(1);

    double n;
    cin >> n;

    cout << n * ft;    
    return 0;
}