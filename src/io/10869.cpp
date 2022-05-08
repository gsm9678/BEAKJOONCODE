#include <iostream>

using namespace std;

int main(){
	int A, B, pri;
	
	cin >> pri;
	
	B = pri%10;
	A = pri/10;
	
	cout << A + B << "\n" 
		<< A - B << "\n" 
		<< A * B << "\n" 
		<< A / B << "\n"
		<< A % B << "\n" << endl;
	
	return 0;
}