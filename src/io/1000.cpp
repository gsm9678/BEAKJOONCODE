#include <iostream>

using namespace std;

int main(){
	int A, B, pri;
	cin >> pri;
	B = pri%10;
	pri /= 10;
	A = pri%10;
	
	cout << A + B << endl;
	
	return 0;
}