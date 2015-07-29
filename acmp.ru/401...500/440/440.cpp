#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

#define sqr(x) (x) * (x)

int a[5] = {0, 25, 50, 75, 100};

int r = 10;

bool check(int _x, int _y, int i)
{
	if (sqr(_x - a[i]) + sqr(_y) <= sqr(r))
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bool used[5] = {0};

	int x, y;

	for (int i = 0; i < 5; i++)
		{
			cin >> x >> y;
			for (int j = 0; j < 5; j++)
				{
					if (check(x, y, j))
						used[j] = true;
				}
		} 

 	int ans = 0;

 	for (int i = 0; i < 5; i++)
 		ans += used[i];

 	cout << ans;
 	return 0;
}

