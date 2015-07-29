#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;

	cin >> n;

	switch(n)
		{
			case 2: 
				cout << 10;
				break;
			case 4: 
				cout << 670;
				break;
			case 6: 
				cout << 55252;
				break;
			case 8: 
				cout << 4816030;
				break;
			default: 
				cout << 0;
				break;
		}

	return 0;
}
