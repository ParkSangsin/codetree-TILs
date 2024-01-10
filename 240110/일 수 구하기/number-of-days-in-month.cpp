#include <iostream>

using namespace std;

int main() {
    // 변수 선언
    int n;

	// 입력
	cin >> n;
    
    // 출력
    if(n == 2)
		cout << "28";
	else if(n <= 7) {
    	if(n % 2 == 1)
        	cout << "31";
    	else
        	cout << "30";
	}
	else {
    	if(n % 2 == 0)
        	cout << "31";
    	else
        	cout << "30";
	}
	
    return 0;
}