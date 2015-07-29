#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("out", "w", stdout);

	cout << "int x[100] = {";

	for (int i = 0; i <= 100; i++)
		cout << i << ", ";

	cout << endl;

	cout << "int y[100] = {";	

	for (long long i = 2; i <= 202; i += 2)
		{
			 cout << i * i / 2 << ", ";
		}

	return 0;	
}
