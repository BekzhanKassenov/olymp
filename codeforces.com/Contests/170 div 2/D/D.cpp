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

int x[101] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
int y[101] = {2, 8, 18, 32, 50, 72, 98, 128, 162, 200, 242, 288, 338, 392, 450, 512, 578, 648, 722, 800, 882, 968, 1058, 1152, 1250, 1352, 1458, 1568, 1682, 1800, 1922, 2048, 2178, 2312, 2450, 2592, 2738, 2888, 3042, 3200, 3362, 3528, 3698, 3872, 4050, 4232, 4418, 4608, 4802, 5000, 5202, 5408, 5618, 5832, 6050, 6272, 6498, 6728, 6962, 7200, 7442, 7688, 7938, 8192, 8450, 8712, 8978, 9248, 9522, 9800, 10082, 10368, 10658, 10952, 11250, 11552, 11858, 12168, 12482, 12800, 13122, 13448, 13778, 14112, 14450, 14792, 15138, 15488, 15842, 16200, 16562, 16928, 17298, 17672, 18050, 18432, 18818, 19208, 19602, 20000, 20402};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	srand(time(NULL));

	int n, m;

	cin >> n >> m;

	random_shuffle(x, x + 101);

	vector <PII> ans;

	for (int i = 0; i < m; i++)
		ans.push_back(MP((x[i] + 1) * 2, y[x[i]]));

	vector <int> a, b, c;

	for (int i = 0; i < m; i++)
		{
			for (int j = i + 1; j < m; j++)
				{
					int tmpa = y[x[i]] - y[x[j]];
					int tmpb = (x[j] + 1) * 2 - (x[i] + 1 * 2);
					int tmpc = y[x[i]] * (x[j] + 1) * 2 - y[x[j]] * (x[i] + 1) * 2;
					a.push_back(tmpa);
					b.push_back(tmpb);
					c.push_back(tmpc);
				}
		}

	int l = a.size();

	int tim = n - m;

	while (tim)	
		{
			int tmpx = rand() % 200, tmpy = rand() % 20000;

			bool flag = true;

			int  l =a.size();

			for (int j = 0; j < l; j++)
				{
					if (a[j] * tmpx + b[j] * tmpy + c[j] == 0)
						flag = false;
				}

			if (flag)
				continue;
			else
				{
					for (int j = 0; j < l; j++)
						{
							int tmpa = y[x[j]] - tmpy;
							int tmpb = (tmpx) * 2 - (x[j] + 1 * 2);
							int tmpc = y[x[j]] * (tmpx) * 2 - tmpy * (x[j] + 1) * 2;
							a.push_back(tmpa);
							b.push_back(tmpb);
							c.push_back(tmpc);

						}
					ans.push_back(MP(tmpx, tmpy));
				}
			tim--;
		 }

   	for (int i = 0; i < n; i++)
   		cout << ans[i].F << ' ' << ans[i].S << endl;


	return 0;
}
