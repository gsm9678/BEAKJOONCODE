#include <iostream>

using namespace std;

int main(){
	int number, num, n, N;
	N = 0;
	
	cin >> number;
	num = number;
	
	do{
		n = num % 10 + (num/10);
		num = (num%10)*10 + n%10;
		N++;
	}while(number != num);
	
	cout << N << endl;
	
	return 0;
}