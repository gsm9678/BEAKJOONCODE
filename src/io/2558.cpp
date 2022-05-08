#include <iostream>

using namespace std;

int main(){
	int A, B;
	int b;
	
	cin >> A;
	cin >> B;
	b = B;
	
	while(b != 0){
		cout << A * (b % 10) << endl;
		b /= 10;
	}
	cout << A * B << endl;
}