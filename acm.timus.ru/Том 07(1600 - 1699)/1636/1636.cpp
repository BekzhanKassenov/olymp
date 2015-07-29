#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int t1, t2;

	cin >> t1 >> t2;

	int tmp, st = 0;

	for (int i = 0; i < 10; i++)
		{
			cin >> tmp;

			st += tmp * 20;
		}

	if (t1 + st > t2)
		puts("Dirty debug :(");
	else
		puts("No chance.");

	return 0;	
}
