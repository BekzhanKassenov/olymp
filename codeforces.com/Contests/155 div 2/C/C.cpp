/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

int a[26] = {0};

int b[26] = {0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s, t, sans;

	cin >> s >> t;

	int len = s.length();

	for (int i = 0; i < len; i++)
		{
			a[s[i] - 'A']++;
			b[t[i] - 'A']++;
			sans += 1;
		}

	int ans = 0;

	for (int j = 0; j < 26; j++)
		{
			for (int i = 0; i < len; i++)
				{	
					if (sans[i] == 1 && s[i] == j + 'A' && b[j] > 0)
						{
							sans[i] = j + 'A';
							b[j]--;
						}
				}

			for (int i = 0; i < len; i++)
				{
					if (sans[i] == 1 && a[s[i] - 'A'] > b[s[i] - 'A'] && b[j] > 0)
						{
							a[s[i] - 'A']--;
							sans[i] = j + 'A';
							a[j]++;
							b[j]--;
							ans++;
						}
				}
		}

	cout << ans << endl << sans;
	return 0;
}
