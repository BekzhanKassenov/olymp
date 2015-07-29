#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	string s, t;

	cin >> s >> t;

	s = s + '#' + t + t;

	vector <int> z(3 * n + 1);

	for (int i = 1, l = 0, r = 0; i < 3 * n + 1; i++)
		{
			if (i <= r)
				z[i] = min(z[i - l], r - i + 1);

			while (i + z[i] < 3 * n + 1 && s[z[i]] == s[i + z[i]])
				z[i]++;

			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}

 	for (int i = n + 1; i < 3 * n + 1; i++)
 		{
 			if (z[i] == n)
 				{
 					cout << i - n - 1 << ' ';
 					return 0;
 				}
 		}

 	cout << -1;

 	return 0;	
}
