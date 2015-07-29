#include <iostream>
#include <cstdio> 

using namespace std;

int main() 
{ 
	int n; 
	
	cin >> n; 
	
	if (n > 0) 
		cout<< (n + 1) * n / 2; 
	else 
		cout<< (n - 1) * n / -2 + 1; 

	return 0; 
} 
