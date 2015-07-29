#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int n , k;

	cin >> k >> n;

	if (k / n < 3)
		{
			cout << -1;
			return 0;
		}

	vector <int> arr(k);

	for (int i = 0; i < k; i++)
		arr[i] = i % n + 1;

	rotate(arr.begin(), arr.begin() + 1, arr.end());

	for (int i = 0; i < k; i++)
		cout << arr[i] << ' ';
}
