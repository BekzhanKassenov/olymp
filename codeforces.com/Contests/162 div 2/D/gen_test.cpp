#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = rand() % 19 + 1;

	cout << n << endl;

	for (int i = 0; i < n; i++)
		cout << rand() % 10000 + 1 << ' ';

	cout << endl;

	return 0;	
}
