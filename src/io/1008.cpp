#include <iostream>

using namespace std;

int main(){
	int pri;
	float A, B, answer;
	
	cin >> pri;
	B = pri%10;
	pri /= 10;
	A = pri%10;
	
	answer = A / B;
	cout << answer << endl;
	
	return 0;
}