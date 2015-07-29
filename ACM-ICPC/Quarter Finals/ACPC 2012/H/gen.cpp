#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	freopen("in", "w", stdout);

	int n;

	srand(time(NULL));

	int cnt = rand() % 10 + 1;

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++)
		{
			long long n = rand() % 7 + 1;

			cout << n << ' ' ;

			for (int j = 0; j < 6; j++)
				cout << rand() % 3;

			cout << endl;
		}

	return 0;
}
