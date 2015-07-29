#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

 	int ans1 = 0, ans2 = 0;

 	for (int i = 1; i < n - 1; i++)
 		{
 			if (a[i] + a[i - 1] + a[i + 1] > ans2)
 				{
 					ans2 = a[i] + a[i - 1] + a[i + 1];
 					ans1 = i + 1;
 				}
 		}

  	cout << ans2 << ' ' << ans1;
}
