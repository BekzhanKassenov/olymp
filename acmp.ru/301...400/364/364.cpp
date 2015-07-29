#include <iostream>
#include <cstdio>

using namespace std;

long long a[8] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328ll, 2305843008139952128ll};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long l, r;

	cin >> l >> r;

	int ans = 0;

	for (int i = 0; i < 8; i++)
		if (a[i] >= l && a[i] <= r)
			ans++;

	if (!ans)
		cout << "Absent";
	else
		for (int i = 0; i < 8; i++)
			if (a[i] >= l && a[i] <= r)
				cout << a[i] << endl;	

	return 0;
}

