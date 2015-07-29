#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{	
	freopen("in", "w", stdout);

	srand(time(NULL));

	cout << rand() % 2000 + 1;

	return 0;
}
