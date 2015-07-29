#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	set <long long> q;

	q.insert(1);

	for (long long p = 2, z = 2; p < (1ll << 31); p += z, z++)
		q.insert(p);

	long long tmp;

	while (n--)
		{
			cin >> tmp;

			if (q.find(tmp) != q.end())
				cout << 1 << ' ';

			else
				cout << 0 << ' ';
		}
	return 0;
}
