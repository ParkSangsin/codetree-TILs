#include <iostream>
using namespace std;

int main() {
    double ft = 30.48;
    double mi = 160934;

    cout << fixed;
    cout.precision(1);

    cout << "9.2ft = " << 9.2 * ft << "cm";
    cout << "\n";
    cout << "1.3mi = " << 1.3 * mi << "cm";
    return 0;
}