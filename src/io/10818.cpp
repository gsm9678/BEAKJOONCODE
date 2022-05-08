#include <iostream>

using namespace std;

int main(){
	int N, min, max;
	
	cin >> N;
	
	int number[N];
	
	for(int i = 0; i < N; i++)
	{
		cin >> number[i];
	}
	min = number[0];
	
	for(int i = 0; i< N; i++){
		if(min > number[i])
			min = number[i];
		if(max < number[i])
			max = number[i];
	}
	cout << min << " " << max << endl;
	
	return 0;
}