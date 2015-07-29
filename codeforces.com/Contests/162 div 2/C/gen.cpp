#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	srand(time(NULL));

	int n = rand() % 1000000 + 1;

	for (int i = 0; i < n; i++)
		if (rand() & 1)
			putchar('l');
		else
			putchar('r');

	cout << endl;
	return 0;	
}

