#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int n = rand() % 100000 + 2;

	int k = n + rand() % 100000 + 1;

	freopen("in", "w", stdout);

	cout << k << ' ' << n << endl;
}
