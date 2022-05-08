#include <iostream>

using namespace std;

int main(){
	int hour, min;
	
	cin >> hour >> min;
	
	min -= 45;
	if(min < 0)
	{
		hour -= 1;
		if(hour< 0)
			hour = 23;
		
		min = 60 + min;
	}
	
	cout << hour << " " << min << endl;
	
	return 0;
}