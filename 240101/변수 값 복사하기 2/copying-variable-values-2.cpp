#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 6;
    int c = 7;

    a = b = c;

    cout << a << " " << b << " " << c;
    return 0;
}