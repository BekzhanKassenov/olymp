/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>


using namespace std;

#define abs(x) (x < 0) ? (-x) : x
#define sqr(x) (x) * (x)
#define INF 2000000000
#define EPS 10e-14
#define PII pair <int, int>
#define PIS pair <int, string>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define LL long long
#define ULL unsigned long long

int x, a, b, c;

int n;

vector <pair <int, string> > vc;

int rnd()
{
	return (x = (x * a + b) % c);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;

	vc.resize(n);

	cin >> x >> a >> b >> c;

	for (int i = 0; i < n; i++)
		cin >> vc[i].S >> vc[i].F;

	sort(vc.begin(), vc.end());

	int i = n - 1;

	vector <vector <PIS> > tms(4);

	for (int q = 0; q < 4; q++)	
		{
			tms[q].reserve(n / 4);

			for (int j = 0; j < n / 4; j++)
				{
					tms[q].push_back(vc[i]);
					i--;
				}
		}

	vector <vector <PIS> > ans(n / 4);

	for (int q = 0; q < n / 4; q++)
		{
			ans[q].reserve(4);
			for (int j = 0; j < 4; j++)
				{
					int re = rnd() % tms[j].size();

					ans[q].push_back(tms[j][re]);
					tms[j].erase(tms[j].begin() + re);
				}
		}

	for (int q = 0; q < n / 4; q++)
		{
			cout << "Group " << (char('A' + q)) << ":" << endl;
			for (int j = 0; j < 4; j++)
				cout << ans[q][j].S << endl;
		}

	return 0;
}

