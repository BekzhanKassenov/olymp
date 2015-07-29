#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> balls;

int n;

int analyse (const vector <int>& c)
{
	vector <int> a[110];
	for (int i = 0; i < n; i++)
		{
			a[c[i]].push_back(i);
		}
	int winner =  -1;
	
	for (int i = 0; i < 101; i++)
		if (a[i].size() == 1)
			{
				winner = a[i][0];
				break;
			}

	vector <pair <int, int> > b(n);
	for (int i = 0; i < n; i++)
		{
			b[i].first = balls[i];
			b[i].second = i;
		}
	if (winner != -1)
		{
			b[winner].first += c[winner];
		}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++)
		if (b[i].second == n - 1)
			return i;
   return 1000000000;
}

int main()
{
	cin >> n;
	balls.resize(n);
	vector <int> c(n);
	for (int i = 0; i < n; i++)
		cin >> balls[i];
	for (int i = 0; i < n - 1; i++)
		cin >> c[i];
	int ans = 1;
	int mx = 0;
	for (int i = 1; i <= 101; i++)
		{
			c[n - 1] = i;
			int k = analyse(c);
			if (k > mx)
				{
					ans = i;
					mx = k;
				}
		} 
	cout << ans;
	return 0;
}
