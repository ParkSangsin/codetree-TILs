#include <iostream>
using namespace std;

int main() {
    int a = 2;
    int b = 5;
    int temp;

    temp = a;

    a = b;
    b = temp;

    cout << a;
    cout << "\n";
    cout << b;
    return 0;
}