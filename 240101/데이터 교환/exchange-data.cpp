#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 6;
    int c = 7;

    int temp1;
    int temp2;
    
    temp1 = a;
    temp2 = b;

    a = c;
    b = temp1;
    c = temp2;

    cout << a;
    cout << '\n';
    cout << b;
    cout << '\n';
    cout << c;

    return 0;
}