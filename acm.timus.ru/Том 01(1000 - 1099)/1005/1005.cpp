#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
 	#endif
 	int n;
 	cin >> n;
 	vector <int> a(n);
 	int sum = 0;
 	for (int i = 0; i < n; i++)
 		{
 			cin >> a[i];
 			sum += a[i];
 		}
 	int ans = 1000000000;
 	for (int mask = 0; mask < (1 << n); mask ++)
 		{
 			int s1 = 0;
 			for (int j = 0; j < n; j++)
 				if ((mask & (1 << j)) > 0)
 					s1 += a[j];
 			int s2 = sum - s1;
 			ans = min (ans, int(abs(double(s1 - s2))));
 		}
 	cout << ans;
 	return 0;
}
